#include "merge.h"
#include "parser.h"

#include "error.h"
#include "lexer.h"
#include "merge.h"
#include "profile.h"
#include "store.h"
#include "unescape.h"
#include "protocolspack/protocol.h"

#include <stdlib.h>
#include <string.h>

static int proto_parse_loop(proto_doc_impl_t *doc, const char *data, size_t len,
                              const proto_options_t *opt,
                              proto_import_ctx_t *ictx,
                              proto_error_t **out_err);

static char *proto_copy_unquoted(proto_doc_impl_t *doc, proto_slice_t raw) {
  return proto_arena_strndup(&doc->arena, raw.data, raw.len);
}


static int proto_token_is_number(proto_slice_t s) {
  size_t i;
  if (s.len == 0) {
    return 0;
  }
  for (i = 0; i < s.len; i++) {
    if (s.data[i] < '0' || s.data[i] > '9') {
      return 0;
    }
  }
  return 1;
}

static int proto_parse_row(proto_doc_impl_t *doc, proto_lexer_t *lx,
                           proto_token_t *tok, proto_error_t **out_err) {
  char name[256];
  int number = 0;
  size_t i;
  if (tok->text.len >= sizeof(name)) {
    return -1;
  }
  memcpy(name, tok->text.data, tok->text.len);
  name[tok->text.len] = '\0';

  if (proto_lexer_next(lx, tok) != 0) {
    return -1;
  }
  if (tok->kind != PROTO_TOK_UNQUOTED && tok->kind != PROTO_TOK_IDENT) {
    if (out_err) {
      *out_err = proto_error_new("expected protocol number", tok->line, tok->column);
    }
    return -1;
  }
  if (!proto_token_is_number(tok->text)) {
    if (out_err) {
      *out_err = proto_error_new("invalid protocol number", tok->line, tok->column);
    }
    return -1;
  }
  for (i = 0; i < tok->text.len; i++) {
    number = number * 10 + (tok->text.data[i] - '0');
  }
  if (proto_row_begin((proto_doc_t *)doc, name) != 0) {
    return -1;
  }
  if (proto_row_set_number((proto_doc_t *)doc, number) != 0) {
    return -1;
  }

  if (proto_lexer_next(lx, tok) != 0) {
    return 0;
  }
  while (tok->kind == PROTO_TOK_IDENT || tok->kind == PROTO_TOK_UNQUOTED ||
         tok->kind == PROTO_TOK_STRING) {
    char alias[512];
    char *val = NULL;
    if (tok->kind == PROTO_TOK_STRING) {
      val = proto_decode_quoted(&doc->arena, tok->text);
    } else {
      if (tok->text.len >= sizeof(alias)) {
        return -1;
      }
      memcpy(alias, tok->text.data, tok->text.len);
      alias[tok->text.len] = '\0';
      val = proto_arena_strdup(&doc->arena, alias);
    }
    if (!val) {
      return -1;
    }
    if (proto_row_add_alias((proto_doc_t *)doc, val) != 0) {
      return -1;
    }
    if (proto_lexer_next(lx, tok) != 0) {
      return 0;
    }
  }
  return 0;
}

static int proto_parse_assignment(proto_doc_impl_t *doc, proto_lexer_t *lx,
                                    proto_token_t *tok, int exported,
                                    proto_error_t **out_err) {
  if (tok->kind != PROTO_TOK_IDENT) {
    if (out_err) {
      *out_err = proto_error_new("expected key name", tok->line, tok->column);
    }
    return -1;
  }
  char key_buf[256];
  if (tok->text.len >= sizeof(key_buf)) {
    return -1;
  }
  memcpy(key_buf, tok->text.data, tok->text.len);
  key_buf[tok->text.len] = '\0';

  if (proto_lexer_next(lx, tok) != 0) {
    return -1;
  }
  if (tok->kind != PROTO_TOK_EQUAL) {
    if (out_err) {
      *out_err = proto_error_new("expected '=' after key", tok->line,
                                   tok->column);
    }
    return -1;
  }

  if (proto_lexer_next(lx, tok) != 0) {
    return -1;
  }

  char *value = NULL;
  if (tok->kind == PROTO_TOK_STRING) {
    value = proto_decode_quoted(&doc->arena, tok->text);
  } else if (tok->kind == PROTO_TOK_UNQUOTED ||
             tok->kind == PROTO_TOK_IDENT) {
    value = proto_copy_unquoted(doc, tok->text);
  } else if (tok->kind == PROTO_TOK_NEWLINE || tok->kind == PROTO_TOK_EOF) {
    value = proto_arena_strdup(&doc->arena, "");
  } else {
    if (out_err) {
      *out_err = proto_error_new("expected value", tok->line, tok->column);
    }
    return -1;
  }
  if (!value) {
    return -1;
  }

  if (doc->active_profile && doc->active_profile[0]) {
    if (proto_profile_set(doc, doc->active_profile, key_buf, value, exported) != 0) {
      return -1;
    }
  } else if (proto_set_entry(doc, key_buf, value, exported) != 0) {
    return -1;
  }

  if (tok->kind != PROTO_TOK_NEWLINE && tok->kind != PROTO_TOK_EOF) {
    if (proto_lexer_next(lx, tok) != 0) {
      return -1;
    }
  }
  return 0;
}

static int proto_parse_include(proto_doc_impl_t *doc, proto_token_t *tok,
                                 proto_import_ctx_t *ictx,
                                 const proto_options_t *opt,
                                 proto_error_t **out_err) {
  if (!ictx || !ictx->read_fn) {
    if (out_err) {
      *out_err = proto_error_new("include without reader", tok->line, tok->column);
    }
    return -1;
  }
  char path[512];
  if (tok->text.len >= sizeof(path)) {
    return -1;
  }
  memcpy(path, tok->text.data, tok->text.len);
  path[tok->text.len] = '\0';

  const char *inc_data = NULL;
  size_t inc_len = 0;
  if (proto_import_ctx_read(ictx, path, &inc_data, &inc_len) != 0) {
    if (out_err) {
      *out_err = proto_error_new("failed to read include", tok->line, tok->column);
    }
    return -1;
  }
  if (proto_import_stack_push(&ictx->stack, path) != 0) {
    return -1;
  }
  proto_doc_impl_t *inc = (proto_doc_impl_t *)proto_doc_create();
  if (!inc) {
    proto_import_stack_pop(&ictx->stack);
    return -1;
  }
  int rc = proto_parse_loop(inc, inc_data, inc_len, opt, ictx, out_err);
  proto_import_stack_pop(&ictx->stack);
  if (rc != 0) {
    proto_doc_destroy((proto_doc_t *)inc);
    return -1;
  }
  rc = proto_merge_docs(doc, (proto_doc_t *)inc);
  proto_doc_destroy((proto_doc_t *)inc);
  return rc;
}

static int proto_parse_loop(proto_doc_impl_t *doc, const char *data, size_t len,
                              const proto_options_t *opt,
                              proto_import_ctx_t *ictx,
                              proto_error_t **out_err) {
  int strict = opt ? opt->strict : 0;
  proto_lexer_t lx;
  proto_lexer_init(&lx, data, len, strict);
  proto_token_t tok;

  if (proto_lexer_next(&lx, &tok) != 0) {
    return -1;
  }

  while (tok.kind != PROTO_TOK_EOF) {
    if (tok.kind == PROTO_TOK_NEWLINE) {
      if (proto_lexer_next(&lx, &tok) != 0) {
        return -1;
      }
      continue;
    }

    if (tok.kind == PROTO_TOK_PROFILE) {
      char prof[128];
      if (tok.text.len >= sizeof(prof)) {
        return -1;
      }
      memcpy(prof, tok.text.data, tok.text.len);
      prof[tok.text.len] = '\0';
      doc->active_profile = proto_arena_strdup(&doc->arena, prof);
      if (!doc->active_profile) {
        return -1;
      }
      if (proto_lexer_next(&lx, &tok) != 0) {
        return -1;
      }
      continue;
    }

    if (tok.kind == PROTO_TOK_INCLUDE) {
      if (proto_parse_include(doc, &tok, ictx, opt, out_err) != 0) {
        return -1;
      }
      if (proto_lexer_next(&lx, &tok) != 0) {
        return -1;
      }
      continue;
    }

    int exported = 0;
    if (tok.kind == PROTO_TOK_EXPORT) {
      exported = 1;
      if (proto_lexer_next(&lx, &tok) != 0) {
        return -1;
      }
    }

    if (tok.kind == PROTO_TOK_IDENT) {
      proto_lexer_t peek_lx = lx;
      proto_token_t peek = tok;
      if (proto_lexer_next(&peek_lx, &peek) == 0 &&
          peek.kind != PROTO_TOK_EQUAL &&
          (peek.kind == PROTO_TOK_UNQUOTED || peek.kind == PROTO_TOK_IDENT) &&
          proto_token_is_number(peek.text)) {
        if (proto_parse_row(doc, &lx, &tok, out_err) != 0) {
          return -1;
        }
        if (tok.kind != PROTO_TOK_NEWLINE && tok.kind != PROTO_TOK_EOF) {
          if (proto_lexer_next(&lx, &tok) != 0) {
            return -1;
          }
        }
        continue;
      }
      if (proto_parse_assignment(doc, &lx, &tok, exported, out_err) != 0) {
        return -1;
      }
      continue;
    }

    if (strict) {
      if (out_err) {
        *out_err = proto_error_new("unexpected token", tok.line, tok.column);
      }
      return -1;
    }

    if (proto_lexer_next(&lx, &tok) != 0) {
      return -1;
    }
  }
  return 0;
}

int proto_parse_buffer(const char *data, size_t len,
                         const proto_options_t *opt,
                         proto_doc_t **out_doc, proto_error_t **out_err) {
  return proto_parse_buffer_with_includes(data, len, opt, NULL, NULL, out_doc,
                                            out_err);
}

int proto_parse_buffer_with_includes(
    const char *data, size_t len, const proto_options_t *opt,
    proto_read_include_fn read_fn, void *read_ctx,
    proto_doc_t **out_doc, proto_error_t **out_err) {
  if (out_doc) {
    *out_doc = NULL;
  }
  if (out_err) {
    *out_err = NULL;
  }

  proto_doc_impl_t *doc = (proto_doc_impl_t *)proto_doc_create();
  if (!doc) {
    return -1;
  }

  proto_import_ctx_t ictx;
  if (read_fn) {
    proto_import_ctx_init(&ictx, read_fn, read_ctx);
  }

  if (proto_parse_loop(doc, data, len, opt, read_fn ? &ictx : NULL, out_err) != 0) {
    if (read_fn) {
      proto_import_ctx_free(&ictx);
    }
    proto_doc_destroy((proto_doc_t *)doc);
    return -1;
  }

  if (read_fn) {
    proto_import_ctx_free(&ictx);
  }

  if (out_doc) {
    *out_doc = (proto_doc_t *)doc;
  } else {
    proto_doc_destroy((proto_doc_t *)doc);
  }
  return 0;
}

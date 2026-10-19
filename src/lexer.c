#include "lexer.h"

#include "strutil.h"

#include <ctype.h>
#include <string.h>

static void proto_lexer_skip_ws(proto_lexer_t *lx) {
  while (lx->cur < lx->end) {
    char c = *lx->cur;
    if (c == ' ' || c == '\t' || c == '\r') {
      lx->cur++;
      lx->column++;
    } else {
      break;
    }
  }
}

static void proto_lexer_skip_comment(proto_lexer_t *lx) {
  if (lx->cur >= lx->end || *lx->cur != '#') {
    return;
  }
  while (lx->cur < lx->end && *lx->cur != '\n') {
    lx->cur++;
    lx->column++;
  }
}

static proto_token_t proto_make_tok(proto_lexer_t *lx,
                                        proto_token_kind_t k,
                                        const char *start, size_t len) {
  proto_token_t t;
  t.kind = k;
  t.text = proto_slice(start, len);
  t.line = lx->line;
  t.column = lx->column;
  return t;
}

void proto_lexer_init(proto_lexer_t *lx, const char *data, size_t len,
                        int strict) {
  lx->cur = data;
  lx->end = data + len;
  lx->line = 1;
  lx->column = 1;
  lx->strict = strict;
}

static int proto_lexer_read_string(proto_lexer_t *lx, char quote,
                                     proto_token_t *tok) {
  const char *start = lx->cur;
  lx->cur++;
  lx->column++;
  while (lx->cur < lx->end) {
    char c = *lx->cur;
    if (c == quote) {
      const char *body = start + 1;
      size_t len = (size_t)(lx->cur - body);
      lx->cur++;
      lx->column++;
      *tok = proto_make_tok(lx, PROTO_TOK_STRING, body, len);
      tok->line = lx->line;
      return 0;
    }
    if (c == '\\') {
      if (lx->cur + 1 >= lx->end) {
        return -1;
      }
      lx->cur += 2;
      lx->column += 2;
      continue;
    }
    if (c == '\n') {
      if (lx->strict) {
        return -1;
      }
      break;
    }
    lx->cur++;
    lx->column++;
  }
  return -1;
}

static int proto_lexer_read_multiline(proto_lexer_t *lx, proto_token_t *tok) {
  if (lx->cur + 2 >= lx->end || lx->cur[0] != '"' || lx->cur[1] != '"' ||
      lx->cur[2] != '"') {
    return -1;
  }
  const char *body_start = lx->cur + 3;
  lx->cur += 3;
  lx->column += 3;
  while (lx->cur + 2 < lx->end) {
    if (lx->cur[0] == '"' && lx->cur[1] == '"' && lx->cur[2] == '"') {
      size_t len = (size_t)(lx->cur - body_start);
      lx->cur += 3;
      lx->column += 3;
      *tok = proto_make_tok(lx, PROTO_TOK_STRING, body_start, len);
      return 0;
    }
    if (*lx->cur == '\n') {
      lx->line++;
      lx->column = 1;
    } else {
      lx->column++;
    }
    lx->cur++;
  }
  return -1;
}

static int proto_lexer_read_profile(proto_lexer_t *lx, proto_token_t *tok) {
  if (*lx->cur != '[') {
    return -1;
  }
  lx->cur++;
  lx->column++;
  const char *start = lx->cur;
  while (lx->cur < lx->end && *lx->cur != ']' && *lx->cur != '\n') {
    lx->cur++;
    lx->column++;
  }
  if (lx->cur >= lx->end || *lx->cur != ']') {
    return -1;
  }
  size_t len = (size_t)(lx->cur - start);
  lx->cur++;
  lx->column++;
  *tok = proto_make_tok(lx, PROTO_TOK_PROFILE, start, len);
  return 0;
}

static int proto_match_include(proto_lexer_t *lx) {
  static const char kw[] = "@import";
  if ((size_t)(lx->end - lx->cur) < sizeof(kw) - 1) {
    return 0;
  }
  return memcmp(lx->cur, kw, sizeof(kw) - 1) == 0;
}

static int proto_lexer_read_include_path(proto_lexer_t *lx, proto_token_t *tok) {
  const char *start = lx->cur;
  lx->cur += 8;
  lx->column += 8;
  proto_lexer_skip_ws(lx);
  if (lx->cur >= lx->end) {
    return -1;
  }
  char quote = 0;
  if (*lx->cur == '"' || *lx->cur == '\'') {
    quote = *lx->cur;
    return proto_lexer_read_string(lx, quote, tok);
  }
  start = lx->cur;
  while (lx->cur < lx->end && *lx->cur != '\n' && *lx->cur != '\r' &&
         *lx->cur != '#') {
    lx->cur++;
    lx->column++;
  }
  while (lx->cur > start && (lx->cur[-1] == ' ' || lx->cur[-1] == '\t')) {
    lx->cur--;
    lx->column--;
  }
  *tok = proto_make_tok(lx, PROTO_TOK_INCLUDE, start, (size_t)(lx->cur - start));
  return 0;
}

static int proto_match_export(proto_lexer_t *lx) {
  static const char kw[] = "export";
  if ((size_t)(lx->end - lx->cur) < sizeof(kw) - 1) {
    return 0;
  }
  if (memcmp(lx->cur, kw, sizeof(kw) - 1) != 0) {
    return 0;
  }
  if (lx->cur + (sizeof(kw) - 1) < lx->end &&
      proto_is_key_char(lx->cur[sizeof(kw) - 1])) {
    return 0;
  }
  return 1;
}

int proto_lexer_next(proto_lexer_t *lx, proto_token_t *tok) {
  proto_lexer_skip_ws(lx);
  if (lx->cur >= lx->end) {
    *tok = proto_make_tok(lx, PROTO_TOK_EOF, lx->cur, 0);
    return 0;
  }

  char c = *lx->cur;
  if (c == '\n') {
    lx->cur++;
    lx->line++;
    lx->column = 1;
    *tok = proto_make_tok(lx, PROTO_TOK_NEWLINE, lx->cur - 1, 1);
    return 0;
  }
  if (c == '#') {
    proto_lexer_skip_comment(lx);
    return proto_lexer_next(lx, tok);
  }
  if (c == '=') {
    lx->cur++;
    lx->column++;
    *tok = proto_make_tok(lx, PROTO_TOK_EQUAL, lx->cur - 1, 1);
    return 0;
  }
  if (c == '"' && lx->cur + 2 < lx->end && lx->cur[1] == '"' && lx->cur[2] == '"') {
    return proto_lexer_read_multiline(lx, tok);
  }
  if (c == '"' || c == '\'') {
    return proto_lexer_read_string(lx, c, tok);
  }
  if (c == '[') {
    return proto_lexer_read_profile(lx, tok);
  }
  if (proto_match_include(lx)) {
    return proto_lexer_read_include_path(lx, tok);
  }
  if (proto_match_export(lx)) {
    const char *start = lx->cur;
    lx->cur += 6;
    lx->column += 6;
    *tok = proto_make_tok(lx, PROTO_TOK_EXPORT, start, 6);
    return 0;
  }
  if (proto_is_key_start(c)) {
    const char *start = lx->cur;
    lx->cur++;
    lx->column++;
    while (lx->cur < lx->end && proto_is_key_char(*lx->cur)) {
      lx->cur++;
      lx->column++;
    }
    *tok = proto_make_tok(lx, PROTO_TOK_IDENT, start,
                            (size_t)(lx->cur - start));
    return 0;
  }

  const char *start = lx->cur;
  while (lx->cur < lx->end && *lx->cur != '\n' && *lx->cur != '\r' &&
         *lx->cur != '#') {
    lx->cur++;
    lx->column++;
  }
  while (lx->cur > start && (lx->cur[-1] == ' ' || lx->cur[-1] == '\t')) {
    lx->cur--;
    lx->column--;
  }
  *tok = proto_make_tok(lx, PROTO_TOK_UNQUOTED, start,
                          (size_t)(lx->cur - start));
  return 0;
}

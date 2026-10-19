#include "expand.h"

#include "buffer.h"
#include "error.h"
#include "strutil.h"

#include <stdlib.h>
#include <string.h>

static const char *proto_lookup_value(const proto_doc_impl_t *doc,
                                        const char *key) {
  return proto_store_get(doc, key);
}

static int proto_expand_once(proto_doc_impl_t *doc, const char *in,
                               proto_buffer_t *out, proto_error_t **err) {
  const char *p = in;
  int changed = 0;
  while (*p) {
    if (p[0] == '$' && p[1] == '{') {
      const char *start = p + 2;
      const char *end = strchr(start, '}');
      if (!end) {
        if (err) {
          *err = proto_error_new("unterminated ${...} expansion", 0, 0);
        }
        return -1;
      }
      char key[256];
      size_t klen = (size_t)(end - start);
      if (klen >= sizeof(key)) {
        if (err) {
          *err = proto_error_new("expansion key too long", 0, 0);
        }
        return -1;
      }
      memcpy(key, start, klen);
      key[klen] = '\0';
      const char *val = proto_lookup_value(doc, key);
      if (!val) {
        if (err) {
          *err = proto_error_new("unknown expansion variable", 0, 0);
        }
        return -1;
      }
      if (proto_buffer_append_cstr(out, val) != 0) {
        return -1;
      }
      p = end + 1;
      changed = 1;
      continue;
    }
    if (p[0] == '$' && p[1] != '\0' && p[1] != '{') {
      char key[256];
      size_t ki = 0;
      const char *q = p + 1;
      while (*q && (proto_is_key_char(*q) || *q == '_') && ki + 1 < sizeof(key)) {
        key[ki++] = *q++;
      }
      if (ki > 0) {
        key[ki] = '\0';
        const char *val = proto_lookup_value(doc, key);
        if (val) {
          if (proto_buffer_append_cstr(out, val) != 0) {
            return -1;
          }
          p = q;
          changed = 1;
          continue;
        }
      }
    }
    if (proto_buffer_append_char(out, *p) != 0) {
      return -1;
    }
    p++;
  }
  return changed;
}

int proto_expand_value(proto_doc_impl_t *doc, char *value, char **out,
                         int max_depth, proto_error_t **err) {
  if (!doc || !value || !out) {
    return -1;
  }
  char *cur = value;
  for (int depth = 0; depth < max_depth; depth++) {
    proto_buffer_t buf;
    proto_buffer_init(&buf);
    int ch = proto_expand_once(doc, cur, &buf, err);
    if (ch < 0) {
      proto_buffer_free(&buf);
      return -1;
    }
    if (!ch) {
      proto_buffer_free(&buf);
      *out = cur;
      return 0;
    }
    char *next = proto_arena_strdup(&doc->arena, buf.data);
    proto_buffer_free(&buf);
    if (!next) {
      return -1;
    }
    cur = next;
  }
  if (err) {
    *err = proto_error_new("expansion depth exceeded", 0, 0);
  }
  return -1;
}

int proto_expand_doc(proto_doc_impl_t *doc, int max_depth,
                       proto_error_t **err) {
  if (!doc) {
    return -1;
  }
  for (size_t i = 0; i < doc->count; i++) {
    char *expanded = NULL;
    if (proto_expand_value(doc, doc->entries[i].value, &expanded, max_depth,
                             err) != 0) {
      return -1;
    }
    doc->entries[i].value = expanded;
  }
  return 0;
}

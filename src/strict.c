#include "strict.h"

#include "protocolspack/proto.h"
#include "parser.h"
#include "store.h"
#include "utf8.h"

#include <string.h>

static int proto_value_needs_quotes(const char *value) {
  if (!value) {
    return 0;
  }
  for (const char *p = value; *p; p++) {
    char c = *p;
    if (c == ' ' || c == '\t' || c == '#' || c == '"' || c == '\'' ||
        c == '\\' || c == '\n' || c == '\r' || c == '$') {
      return 1;
    }
  }
  return 0;
}

proto_strict_violation_t proto_strict_check(const proto_doc_t *doc) {
  const proto_doc_impl_t *d = (const proto_doc_impl_t *)doc;
  if (!d || d->count == 0) {
    return PROTO_STRICT_EMPTY_DOCUMENT;
  }
  for (size_t i = 0; i < d->count; i++) {
    proto_slice_t s = proto_slice(d->entries[i].key, strlen(d->entries[i].key));
    if (!proto_utf8_valid(s)) {
      return PROTO_STRICT_INVALID_UTF8;
    }
    s.data = d->entries[i].value;
    s.len = d->entries[i].value ? strlen(d->entries[i].value) : 0;
    if (!proto_utf8_valid(s)) {
      return PROTO_STRICT_INVALID_UTF8;
    }
    if (proto_value_needs_quotes(d->entries[i].value)) {
      return PROTO_STRICT_UNQUOTED_SPECIAL;
    }
  }
  return PROTO_STRICT_OK;
}

int proto_strict_parse_memory(const char *data, size_t len,
                                proto_doc_t **out_doc,
                                proto_error_t **out_err) {
  proto_options_t opt = proto_default_options();
  opt.strict = 1;
  return proto_parse_buffer(data, len, &opt, out_doc, out_err);
}

int proto_require_exported(const proto_doc_t *doc, const char *key) {
  const proto_doc_impl_t *d = (const proto_doc_impl_t *)doc;
  if (!d || !key) {
    return -1;
  }
  for (size_t i = 0; i < d->count; i++) {
    if (strcmp(d->entries[i].key, key) == 0) {
      return d->entries[i].exported ? 0 : -1;
    }
  }
  return -1;
}

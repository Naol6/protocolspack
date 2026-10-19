#ifndef PROTO_STRICT_H
#define PROTO_STRICT_H

#include "protocolspack/proto_types.h"

typedef enum proto_strict_violation {
  PROTO_STRICT_OK = 0,
  PROTO_STRICT_EMPTY_DOCUMENT,
  PROTO_STRICT_MISSING_EXPORT,
  PROTO_STRICT_INVALID_UTF8,
  PROTO_STRICT_UNQUOTED_SPECIAL
} proto_strict_violation_t;

proto_strict_violation_t proto_strict_check(const proto_doc_t *doc);
int proto_strict_parse_memory(const char *data, size_t len,
                                proto_doc_t **out_doc,
                                proto_error_t **out_err);
int proto_require_exported(const proto_doc_t *doc, const char *key);

#endif /* PROTO_STRICT_H */

#ifndef PROTO_COERCE_H
#define PROTO_COERCE_H

#include "protocolspack/proto_types.h"

typedef enum proto_value_kind {
  PROTO_VALUE_STRING = 0,
  PROTO_VALUE_BOOL,
  PROTO_VALUE_INT,
  PROTO_VALUE_FLOAT
} proto_value_kind_t;

proto_value_kind_t proto_coerce_kind(const char *value);
int proto_coerce_bool(const char *value, int *out);
int proto_coerce_int(const char *value, long long *out);
int proto_coerce_double(const char *value, double *out);
int proto_coerce_entry_bool(const proto_doc_t *doc, const char *key, int *out);
int proto_coerce_entry_int(const proto_doc_t *doc, const char *key, long long *out);

#endif /* PROTO_COERCE_H */

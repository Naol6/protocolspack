#include "coerce.h"

#include "store.h"
#include "strutil.h"

#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

proto_value_kind_t proto_coerce_kind(const char *value) {
  if (!value) {
    return PROTO_VALUE_STRING;
  }
  if (proto_str_ieq(value, "true") || proto_str_ieq(value, "false") ||
      proto_str_ieq(value, "yes") || proto_str_ieq(value, "no") ||
      proto_str_ieq(value, "on") || proto_str_ieq(value, "off")) {
    return PROTO_VALUE_BOOL;
  }
  char *end = NULL;
  errno = 0;
  strtoll(value, &end, 10);
  if (end && *end == '\0' && errno == 0) {
    return PROTO_VALUE_INT;
  }
  errno = 0;
  strtod(value, &end);
  if (end && *end == '\0' && errno == 0) {
    return PROTO_VALUE_FLOAT;
  }
  return PROTO_VALUE_STRING;
}

int proto_coerce_bool(const char *value, int *out) {
  if (!value || !out) {
    return -1;
  }
  if (proto_str_ieq(value, "true") || proto_str_ieq(value, "yes") ||
      proto_str_ieq(value, "on") || proto_str_ieq(value, "1")) {
    *out = 1;
    return 0;
  }
  if (proto_str_ieq(value, "false") || proto_str_ieq(value, "no") ||
      proto_str_ieq(value, "off") || proto_str_ieq(value, "0")) {
    *out = 0;
    return 0;
  }
  return -1;
}

int proto_coerce_int(const char *value, long long *out) {
  if (!value || !out) {
    return -1;
  }
  char *end = NULL;
  errno = 0;
  long long v = strtoll(value, &end, 10);
  if (errno != 0 || !end || *end != '\0') {
    return -1;
  }
  *out = v;
  return 0;
}

int proto_coerce_double(const char *value, double *out) {
  if (!value || !out) {
    return -1;
  }
  char *end = NULL;
  errno = 0;
  double v = strtod(value, &end);
  if (errno != 0 || !end || *end != '\0') {
    return -1;
  }
  *out = v;
  return 0;
}

int proto_coerce_entry_bool(const proto_doc_t *doc, const char *key, int *out) {
  const char *v = proto_store_get((const proto_doc_impl_t *)doc, key);
  if (!v) {
    return -1;
  }
  return proto_coerce_bool(v, out);
}

int proto_coerce_entry_int(const proto_doc_t *doc, const char *key,
                             long long *out) {
  const char *v = proto_store_get((const proto_doc_impl_t *)doc, key);
  if (!v) {
    return -1;
  }
  return proto_coerce_int(v, out);
}

#ifndef PROTO_INTERNAL_H
#define PROTO_INTERNAL_H

#include <stdlib.h>
#include <string.h>

typedef struct proto_slice {
  const char *data;
  size_t len;
} proto_slice_t;

static inline proto_slice_t proto_slice(const char *data, size_t len) {
  proto_slice_t s;
  s.data = data;
  s.len = len;
  return s;
}

char *proto_strdup(const char *s);
char *proto_strndup(const char *s, size_t n);

#endif /* PROTO_INTERNAL_H */

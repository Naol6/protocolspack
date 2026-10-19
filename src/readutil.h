#ifndef PROTO_READUTIL_H
#define PROTO_READUTIL_H

#include <stddef.h>

typedef struct proto_read_result {
  char *data;
  size_t len;
} proto_read_result_t;

int proto_read_file_bytes(const char *path, proto_read_result_t *out);
void proto_read_result_free(proto_read_result_t *r);
int proto_read_stdin(proto_read_result_t *out);

#endif /* PROTO_READUTIL_H */

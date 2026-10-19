#ifndef PROTO_BUFFER_H
#define PROTO_BUFFER_H

#include <stddef.h>

typedef struct proto_buffer {
  char *data;
  size_t len;
  size_t cap;
} proto_buffer_t;

void proto_buffer_init(proto_buffer_t *buf);
void proto_buffer_free(proto_buffer_t *buf);
int proto_buffer_reserve(proto_buffer_t *buf, size_t need);
int proto_buffer_append(proto_buffer_t *buf, const char *data, size_t len);
int proto_buffer_append_char(proto_buffer_t *buf, char c);
int proto_buffer_append_cstr(proto_buffer_t *buf, const char *s);

#endif /* PROTO_BUFFER_H */

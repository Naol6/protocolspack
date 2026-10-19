#include "buffer.h"

#include <stdlib.h>
#include <string.h>

#define PROTO_BUFFER_INIT_CAP 64

static size_t proto_grow_cap(size_t cap, size_t need) {
  size_t n = cap ? cap : PROTO_BUFFER_INIT_CAP;
  while (n < need) {
    if (n > (size_t)-1 / 2) {
      return 0;
    }
    n *= 2;
  }
  return n;
}

void proto_buffer_init(proto_buffer_t *buf) {
  buf->data = NULL;
  buf->len = 0;
  buf->cap = 0;
}

void proto_buffer_free(proto_buffer_t *buf) {
  free(buf->data);
  buf->data = NULL;
  buf->len = 0;
  buf->cap = 0;
}

int proto_buffer_reserve(proto_buffer_t *buf, size_t need) {
  if (need <= buf->cap) {
    return 0;
  }
  size_t new_cap = proto_grow_cap(buf->cap, need);
  if (new_cap == 0) {
    return -1;
  }
  char *p = (char *)realloc(buf->data, new_cap);
  if (!p) {
    return -1;
  }
  buf->data = p;
  buf->cap = new_cap;
  return 0;
}

int proto_buffer_append(proto_buffer_t *buf, const char *data, size_t len) {
  if (len == 0) {
    return 0;
  }
  if (buf->len > (size_t)-1 - len) {
    return -1;
  }
  size_t need = buf->len + len + 1;
  if (proto_buffer_reserve(buf, need) != 0) {
    return -1;
  }
  memcpy(buf->data + buf->len, data, len);
  buf->len += len;
  buf->data[buf->len] = '\0';
  return 0;
}

int proto_buffer_append_char(proto_buffer_t *buf, char c) {
  return proto_buffer_append(buf, &c, 1);
}

int proto_buffer_append_cstr(proto_buffer_t *buf, const char *s) {
  return proto_buffer_append(buf, s, strlen(s));
}

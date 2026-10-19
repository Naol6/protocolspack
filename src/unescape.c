#include "unescape.h"

#include "buffer.h"

#include <stdlib.h>
#include <string.h>

static int proto_hex_digit(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  if (c >= 'a' && c <= 'f') {
    return c - 'a' + 10;
  }
  if (c >= 'A' && c <= 'F') {
    return c - 'A' + 10;
  }
  return -1;
}

char *proto_decode_quoted(proto_arena_t *a, proto_slice_t raw) {
  char *raw_copy = (char *)malloc(raw.len == 0 ? 1 : raw.len);
  if (!raw_copy) {
    return NULL;
  }
  if (raw.len > 0) {
    memcpy(raw_copy, raw.data, raw.len);
  }
  raw.data = raw_copy;

  proto_buffer_t buf;
  proto_buffer_init(&buf);
  char *out = NULL;

  for (size_t i = 0; i < raw.len; i++) {
    char c = raw.data[i];
    if (c != '\\') {
      if (proto_buffer_append_char(&buf, c) != 0) {
        goto done;
      }
      continue;
    }
    if (i + 1 >= raw.len) {
      goto done;
    }
    char e = raw.data[++i];
    if (e == 'n') {
      if (proto_buffer_append_char(&buf, '\n') != 0) {
        goto done;
      }
      continue;
    }
    if (e == 't') {
      if (proto_buffer_append_char(&buf, '\t') != 0) {
        goto done;
      }
      continue;
    }
    if (e == 'r') {
      if (proto_buffer_append_char(&buf, '\r') != 0) {
        goto done;
      }
      continue;
    }
    if (e == 'x') {
      if (i + 1 >= raw.len) {
        goto done;
      }
      int hi = proto_hex_digit(raw.data[i + 1]);
      int lo = proto_hex_digit(raw.data[i + 2]);
      if (hi < 0 || lo < 0) {
        goto done;
      }
      char byte = (char)((hi << 4) | lo);
      if (proto_buffer_append_char(&buf, byte) != 0) {
        goto done;
      }
      i += 2;
      continue;
    }
    if (e == '\\' || e == '"' || e == '\'') {
      if (proto_buffer_append_char(&buf, e) != 0) {
        goto done;
      }
      continue;
    }
    goto done;
  }
  out = proto_arena_strndup(a, buf.data, buf.len);

done:
  proto_buffer_free(&buf);
  free(raw_copy);
  return out;
}

#include "readutil.h"

#include <stdio.h>
#include <stdlib.h>

int proto_read_file_bytes(const char *path, proto_read_result_t *out) {
  if (!path || !out) {
    return -1;
  }
  FILE *f = fopen(path, "rb");
  if (!f) {
    return -1;
  }
  if (fseek(f, 0, SEEK_END) != 0) {
    fclose(f);
    return -1;
  }
  long sz = ftell(f);
  if (sz < 0) {
    fclose(f);
    return -1;
  }
  if (fseek(f, 0, SEEK_SET) != 0) {
    fclose(f);
    return -1;
  }
  char *buf = (char *)malloc((size_t)sz + 1);
  if (!buf) {
    fclose(f);
    return -1;
  }
  size_t n = fread(buf, 1, (size_t)sz, f);
  fclose(f);
  buf[n] = '\0';
  out->data = buf;
  out->len = n;
  return 0;
}

void proto_read_result_free(proto_read_result_t *r) {
  if (!r) {
    return;
  }
  free(r->data);
  r->data = NULL;
  r->len = 0;
}

int proto_read_stdin(proto_read_result_t *out) {
  if (!out) {
    return -1;
  }
  size_t cap = 4096;
  size_t len = 0;
  char *buf = (char *)malloc(cap);
  if (!buf) {
    return -1;
  }
  int c;
  while ((c = getchar()) != EOF) {
    if (len + 1 >= cap) {
      cap *= 2;
      char *p = (char *)realloc(buf, cap);
      if (!p) {
        free(buf);
        return -1;
      }
      buf = p;
    }
    buf[len++] = (char)c;
  }
  buf[len] = '\0';
  out->data = buf;
  out->len = len;
  return 0;
}

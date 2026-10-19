#include "path.h"

#include "protocolspack_internal.h"

#include <stdlib.h>
#include <string.h>

char *proto_path_basename(const char *path) {
  if (!path) {
    return NULL;
  }
  const char *slash = strrchr(path, '/');
  const char *bslash = strrchr(path, '\\');
  const char *base = path;
  if (slash && slash + 1 > base) {
    base = slash + 1;
  }
  if (bslash && bslash + 1 > base) {
    base = bslash + 1;
  }
  return proto_strdup(base);
}

char *proto_path_join(const char *dir, const char *file) {
  if (!dir || !file) {
    return NULL;
  }
  size_t dlen = strlen(dir);
  size_t flen = strlen(file);
  int need_sep = dlen > 0 && dir[dlen - 1] != '/' && dir[dlen - 1] != '\\';
  size_t total = dlen + flen + (need_sep ? 1 : 0) + 1;
  char *out = (char *)malloc(total);
  if (!out) {
    return NULL;
  }
  memcpy(out, dir, dlen);
  size_t off = dlen;
  if (need_sep) {
    out[off++] = '/';
  }
  memcpy(out + off, file, flen + 1);
  return out;
}

int proto_path_is_absolute(const char *path) {
  if (!path || !path[0]) {
    return 0;
  }
  if (path[0] == '/' || path[0] == '\\') {
    return 1;
  }
  if (path[1] == ':' && ((path[0] >= 'A' && path[0] <= 'Z') ||
                         (path[0] >= 'a' && path[0] <= 'z'))) {
    return 1;
  }
  return 0;
}

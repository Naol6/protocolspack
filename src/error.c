#include "error.h"

#include "protocolspack_internal.h"

#include <stdlib.h>

proto_error_t *proto_error_new(const char *msg, int line, int column) {
  proto_error_t *err = (proto_error_t *)calloc(1, sizeof(*err));
  if (!err) {
    return NULL;
  }
  err->message = proto_strdup(msg ? msg : "unknown error");
  if (!err->message) {
    free(err);
    return NULL;
  }
  err->line = line;
  err->column = column;
  return err;
}

void proto_error_destroy(proto_error_t *err) {
  if (!err) {
    return;
  }
  free(err->message);
  free(err);
}

#ifndef PROTO_ERROR_H
#define PROTO_ERROR_H

#include "protocolspack/proto_types.h"

struct proto_error {
  char *message;
  int line;
  int column;
};

proto_error_t *proto_error_new(const char *msg, int line, int column);
void proto_error_destroy(proto_error_t *err);

#endif /* PROTO_ERROR_H */

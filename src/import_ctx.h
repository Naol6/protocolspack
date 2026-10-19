#ifndef PROTO_INCLUDE_CTX_H
#define PROTO_INCLUDE_CTX_H

#include "protocolspack/proto_types.h"
#include "import_stack.h"

typedef int (*proto_read_include_fn)(void *ctx, const char *path,
                                       const char **out_data, size_t *out_len);

typedef struct proto_import_ctx {
  proto_import_stack_t stack;
  proto_read_include_fn read_fn;
  void *user_ctx;
} proto_import_ctx_t;

void proto_import_ctx_init(proto_import_ctx_t *ctx,
                              proto_read_include_fn read_fn, void *user_ctx);
void proto_import_ctx_free(proto_import_ctx_t *ctx);
int proto_import_ctx_read(void *ctx_void, const char *path,
                             const char **out_data, size_t *out_len);

#endif /* PROTO_INCLUDE_CTX_H */

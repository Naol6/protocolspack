#include "import_ctx.h"

void proto_import_ctx_init(proto_import_ctx_t *ctx,
                              proto_read_include_fn read_fn, void *user_ctx) {
  proto_import_stack_init(&ctx->stack);
  ctx->read_fn = read_fn;
  ctx->user_ctx = user_ctx;
}

void proto_import_ctx_free(proto_import_ctx_t *ctx) {
  if (!ctx) {
    return;
  }
  proto_import_stack_free(&ctx->stack);
}

int proto_import_ctx_read(void *ctx_void, const char *path,
                             const char **out_data, size_t *out_len) {
  proto_import_ctx_t *ctx = (proto_import_ctx_t *)ctx_void;
  if (proto_import_stack_has(&ctx->stack, path)) {
    return -1;
  }
  return ctx->read_fn(ctx->user_ctx, path, out_data, out_len);
}

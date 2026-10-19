#ifndef PROTO_H
#define PROTO_H

#include "proto_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*proto_read_include_fn)(void *ctx, const char *path,
                                       const char **out_data, size_t *out_len);

typedef enum proto_walk_action {
  PROTO_WALK_CONTINUE = 0,
  PROTO_WALK_STOP
} proto_walk_action_t;

typedef proto_walk_action_t (*proto_walk_fn)(void *ctx, const char *key,
                                                 const char *value, int exported,
                                                 size_t index);

proto_options_t proto_default_options(void);

int proto_parse_memory(const char *data, size_t len,
                         const proto_options_t *opt,
                         proto_doc_t **out_doc,
                         proto_error_t **out_err);

int proto_parse_memory_with_includes(
    const char *data, size_t len, const proto_options_t *opt,
    proto_read_include_fn read_fn, void *read_ctx,
    proto_doc_t **out_doc, proto_error_t **out_err);

int proto_parse_file(const char *path, const proto_options_t *opt,
                       proto_doc_t **out_doc, proto_error_t **out_err);

void proto_doc_free(proto_doc_t *doc);
void proto_error_free(proto_error_t *err);

const char *proto_error_message(const proto_error_t *err);
int proto_error_line(const proto_error_t *err);
int proto_error_column(const proto_error_t *err);

size_t proto_entry_count(const proto_doc_t *doc);
const char *proto_entry_key(const proto_doc_t *doc, size_t idx);
const char *proto_entry_value(const proto_doc_t *doc, size_t idx);
int proto_entry_exported(const proto_doc_t *doc, size_t idx);
const char *proto_get(const proto_doc_t *doc, const char *key);
const char *proto_get_profile(const proto_doc_t *doc, const char *profile,
                                const char *key);

int proto_serialize(const proto_doc_t *doc, char **out_buf, size_t *out_len);
int proto_pretty_print(const proto_doc_t *doc, char **out_buf, size_t *out_len);
int proto_merge(proto_doc_t *dst, const proto_doc_t *src);
proto_validate_code_t proto_validate(const proto_doc_t *doc);

int proto_expand_all(proto_doc_t *doc, int max_depth, proto_error_t **err);
int proto_walk(const proto_doc_t *doc, proto_walk_fn fn, void *ctx);
size_t proto_count_exported(const proto_doc_t *doc);

int proto_coerce_bool_value(const char *value, int *out);
int proto_coerce_int_value(const char *value, long long *out);
int proto_apply_to_environ(const proto_doc_t *doc, int overwrite);

#ifdef __cplusplus
}
#endif

#endif /* PROTO_H */

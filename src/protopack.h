#ifndef PROTO_DOTENV_H
#define PROTO_DOTENV_H

#include "protocolspack/proto_types.h"

int proto_protopack_load_buffer(const char *data, size_t len, proto_doc_t **out,
                               proto_error_t **err);
int proto_protopack_load_strict(const char *data, size_t len, proto_doc_t **out,
                               proto_error_t **err);
int proto_protopack_normalize(proto_doc_t *doc, proto_error_t **err);
int proto_protopack_to_export_block(const proto_doc_t *doc, char **out,
                                   size_t *out_len);
int proto_protopack_strip_exports(proto_doc_t *doc);
int proto_protopack_has_key(const proto_doc_t *doc, const char *key);
int proto_protopack_keys_match(const proto_doc_t *a, const proto_doc_t *b);
size_t proto_protopack_count_nonblank_lines(const char *data, size_t len);
int proto_protopack_merge_file(proto_doc_t *doc, const char *data, size_t len,
                              proto_error_t **err);
int proto_protopack_filter_exported(const proto_doc_t *doc,
                                   proto_doc_t **out);
int proto_protopack_require_keys(const proto_doc_t *doc, const char **keys,
                                size_t count);
int proto_protopack_validate_strict(const proto_doc_t *doc);

#endif /* PROTO_DOTENV_H */

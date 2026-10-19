#ifndef PROTO_QUERY_H
#define PROTO_QUERY_H

#include "protocolspack/proto_types.h"

size_t proto_query_prefix(const proto_doc_t *doc, const char *prefix,
                            const char ***out_keys, size_t *out_count);
const char *proto_query_first(const proto_doc_t *doc, const char *prefix);
int proto_query_has_prefix(const proto_doc_t *doc, const char *prefix);

#endif /* PROTO_QUERY_H */

#ifndef PROTO_FILTER_H
#define PROTO_FILTER_H

#include "protocolspack/proto_types.h"

typedef int (*proto_filter_fn)(void *ctx, const char *key, const char *value);

int proto_filter_entries(const proto_doc_t *doc, proto_filter_fn fn, void *ctx);
proto_doc_t *proto_filter_copy(const proto_doc_t *doc, proto_filter_fn fn,
                                   void *ctx);

#endif /* PROTO_FILTER_H */

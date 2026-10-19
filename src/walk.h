#ifndef PROTO_WALK_H
#define PROTO_WALK_H

#include "protocolspack/proto.h"

int proto_walk(const proto_doc_t *doc, proto_walk_fn fn, void *ctx);
size_t proto_count_entries(const proto_doc_t *doc);
size_t proto_count_exported(const proto_doc_t *doc);

#endif /* PROTO_WALK_H */

#ifndef PROTO_SNAPSHOT_H
#define PROTO_SNAPSHOT_H

#include "protocolspack/proto_types.h"

proto_doc_t *proto_snapshot_clone(const proto_doc_t *doc);
int proto_snapshot_equals(const proto_doc_t *a, const proto_doc_t *b);

#endif /* PROTO_SNAPSHOT_H */

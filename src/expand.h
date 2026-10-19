#ifndef PROTO_EXPAND_H
#define PROTO_EXPAND_H

#include "arena.h"
#include "protocolspack/proto_types.h"
#include "store.h"

int proto_expand_value(proto_doc_impl_t *doc, char *value, char **out,
                         int max_depth, proto_error_t **err);
int proto_expand_doc(proto_doc_impl_t *doc, int max_depth,
                       proto_error_t **err);

#endif /* PROTO_EXPAND_H */

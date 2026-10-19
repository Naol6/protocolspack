#ifndef PROTO_ENVMAP_H
#define PROTO_ENVMAP_H

#include "protocolspack/proto_types.h"

int proto_apply_to_environ(const proto_doc_t *doc, int overwrite);
int proto_load_from_environ(proto_doc_t *doc, const char **keys, size_t count);
int proto_unset_from_doc(const proto_doc_t *doc);

#endif /* PROTO_ENVMAP_H */

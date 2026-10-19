#ifndef PROTO_CANONICAL_H
#define PROTO_CANONICAL_H

#include "protocolspack/proto_types.h"

int proto_canonicalize_keys(proto_doc_t *doc);
int proto_canonicalize_key_inplace(char *key);

#endif /* PROTO_CANONICAL_H */

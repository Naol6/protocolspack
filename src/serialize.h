#ifndef PROTO_SERIALIZE_H
#define PROTO_SERIALIZE_H

#include "protocolspack/proto_types.h"

int proto_serialize_doc(const proto_doc_t *doc, char **out_buf,
                          size_t *out_len);

#endif /* PROTO_SERIALIZE_H */

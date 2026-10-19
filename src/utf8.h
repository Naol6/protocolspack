#ifndef PROTO_UTF8_H
#define PROTO_UTF8_H

#include "protocolspack_internal.h"

int proto_utf8_valid(proto_slice_t s);
int proto_utf8_decode(const char **p, const char *end, unsigned *out_cp);
size_t proto_utf8_encode(unsigned cp, char out[4]);

#endif /* PROTO_UTF8_H */

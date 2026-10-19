#ifndef PROTO_UNESCAPE_H
#define PROTO_UNESCAPE_H

#include "arena.h"
#include "protocolspack_internal.h"

char *proto_decode_quoted(proto_arena_t *a, proto_slice_t raw);

#endif /* PROTO_UNESCAPE_H */

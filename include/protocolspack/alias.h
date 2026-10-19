#ifndef PROTOCOLSPACK_ALIAS_H
#define PROTOCOLSPACK_ALIAS_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct proto_alias proto_alias_t;

proto_alias_t *proto_alias_create(void);
void proto_alias_destroy(proto_alias_t *m);

int proto_alias_begin(proto_alias_t *m, const char *name);
int proto_alias_append_token(proto_alias_t *m, const char *line, size_t len);
uint32_t proto_alias_finalize_digest(proto_alias_t *m);

#ifdef __cplusplus
}
#endif

#endif

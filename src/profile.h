#ifndef PROTO_PROFILE_H
#define PROTO_PROFILE_H

#include "arena.h"
#include "store.h"

char *proto_profile_key(proto_arena_t *arena, const char *profile,
                          const char *key);
int proto_profile_set(proto_doc_impl_t *doc, const char *profile,
                        const char *key, char *value, int exported);
const char *proto_profile_get(const proto_doc_impl_t *doc, const char *profile,
                                const char *key);

#endif /* PROTO_PROFILE_H */

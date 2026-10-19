#include "profile.h"

#include "buffer.h"

#include <stdio.h>
#include <string.h>

char *proto_profile_key(proto_arena_t *arena, const char *profile,
                          const char *key) {
  if (!profile || !profile[0]) {
    return proto_arena_strdup(arena, key);
  }
  proto_buffer_t buf;
  proto_buffer_init(&buf);
  proto_buffer_append_cstr(&buf, profile);
  proto_buffer_append_char(&buf, '.');
  proto_buffer_append_cstr(&buf, key);
  char *out = proto_arena_strdup(arena, buf.data);
  proto_buffer_free(&buf);
  return out;
}

int proto_profile_set(proto_doc_impl_t *doc, const char *profile,
                        const char *key, char *value, int exported) {
  char *full = proto_profile_key(&doc->arena, profile, key);
  if (!full) {
    return -1;
  }
  return proto_set_entry(doc, full, value, exported);
}

const char *proto_profile_get(const proto_doc_impl_t *doc, const char *profile,
                                const char *key) {
  char buf[512];
  if (!profile || !profile[0]) {
    return proto_store_get(doc, key);
  }
  snprintf(buf, sizeof(buf), "%s.%s", profile, key);
  return proto_store_get(doc, buf);
}

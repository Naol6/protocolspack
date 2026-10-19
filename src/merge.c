#include "merge.h"

#include "store.h"

#include <string.h>

int proto_merge_docs(proto_doc_t *dst, const proto_doc_t *src) {
  proto_doc_impl_t *d = (proto_doc_impl_t *)dst;
  const proto_doc_impl_t *s = (const proto_doc_impl_t *)src;
  if (!d || !s) {
    return -1;
  }

  for (size_t i = 0; i < s->count; i++) {
    char *value = proto_arena_strdup(&d->arena, s->entries[i].value);
    if (!value) {
      return -1;
    }
    if (proto_set_entry(d, s->entries[i].key, value, s->entries[i].exported) !=
        0) {
      return -1;
    }
  }
  return 0;
}

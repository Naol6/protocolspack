#include "walk.h"

#include "store.h"

int proto_walk(const proto_doc_t *doc, proto_walk_fn fn, void *ctx) {
  const proto_doc_impl_t *d = (const proto_doc_impl_t *)doc;
  if (!d || !fn) {
    return -1;
  }
  for (size_t i = 0; i < d->count; i++) {
    proto_walk_action_t act =
        fn(ctx, d->entries[i].key, d->entries[i].value, d->entries[i].exported, i);
    if (act == PROTO_WALK_STOP) {
      return 0;
    }
  }
  return 0;
}

size_t proto_count_entries(const proto_doc_t *doc) {
  const proto_doc_impl_t *d = (const proto_doc_impl_t *)doc;
  return d ? d->count : 0;
}

size_t proto_count_exported(const proto_doc_t *doc) {
  const proto_doc_impl_t *d = (const proto_doc_impl_t *)doc;
  if (!d) {
    return 0;
  }
  size_t n = 0;
  for (size_t i = 0; i < d->count; i++) {
    if (d->entries[i].exported) {
      n++;
    }
  }
  return n;
}

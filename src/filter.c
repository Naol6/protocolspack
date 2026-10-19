#include "filter.h"

#include "merge.h"
#include "store.h"

int proto_filter_entries(const proto_doc_t *doc, proto_filter_fn fn, void *ctx) {
  const proto_doc_impl_t *d = (const proto_doc_impl_t *)doc;
  if (!d || !fn) {
    return -1;
  }
  for (size_t i = 0; i < d->count; i++) {
    if (!fn(ctx, d->entries[i].key, d->entries[i].value)) {
      return 0;
    }
  }
  return 1;
}

proto_doc_t *proto_filter_copy(const proto_doc_t *doc, proto_filter_fn fn,
                                   void *ctx) {
  const proto_doc_impl_t *d = (const proto_doc_impl_t *)doc;
  if (!d || !fn) {
    return NULL;
  }
  proto_doc_impl_t *out = (proto_doc_impl_t *)proto_doc_create();
  if (!out) {
    return NULL;
  }
  for (size_t i = 0; i < d->count; i++) {
    if (!fn(ctx, d->entries[i].key, d->entries[i].value)) {
      continue;
    }
    char *val = proto_arena_strdup(&out->arena, d->entries[i].value);
    if (!val || proto_set_entry(out, d->entries[i].key, val,
                                  d->entries[i].exported) != 0) {
      proto_doc_destroy((proto_doc_t *)out);
      return NULL;
    }
  }
  return (proto_doc_t *)out;
}

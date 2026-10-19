#include "snapshot.h"

#include "merge.h"
#include "store.h"

#include <string.h>

proto_doc_t *proto_snapshot_clone(const proto_doc_t *doc) {
  const proto_doc_impl_t *src = (const proto_doc_impl_t *)doc;
  if (!src) {
    return NULL;
  }
  proto_doc_impl_t *dst = (proto_doc_impl_t *)proto_doc_create();
  if (!dst) {
    return NULL;
  }
  if (proto_merge_docs(dst, doc) != 0) {
    proto_doc_destroy((proto_doc_t *)dst);
    return NULL;
  }
  return (proto_doc_t *)dst;
}

int proto_snapshot_equals(const proto_doc_t *a, const proto_doc_t *b) {
  const proto_doc_impl_t *da = (const proto_doc_impl_t *)a;
  const proto_doc_impl_t *db = (const proto_doc_impl_t *)b;
  if (!da || !db) {
    return 0;
  }
  if (da->count != db->count) {
    return 0;
  }
  for (size_t i = 0; i < da->count; i++) {
    const char *kb = proto_store_get(db, da->entries[i].key);
    if (!kb || strcmp(da->entries[i].value, kb) != 0) {
      return 0;
    }
    for (size_t j = 0; j < db->count; j++) {
      if (strcmp(db->entries[j].key, da->entries[i].key) == 0) {
        if (db->entries[j].exported != da->entries[i].exported) {
          return 0;
        }
        break;
      }
    }
  }
  return 1;
}

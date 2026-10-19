#include "store.h"

#include "protocolspack/protocol.h"

#include <stdlib.h>
#include <string.h>

static int proto_grow_ptr(void **list, size_t elem_size, size_t *count,
                            size_t *cap) {
  if (*count < *cap) {
    return 0;
  }
  size_t new_cap = *cap ? *cap * 2 : 8;
  void *p = realloc(*list, new_cap * elem_size);
  if (!p) {
    return -1;
  }
  *list = p;
  *cap = new_cap;
  return 0;
}

proto_doc_t *proto_doc_create(void) {
  proto_doc_impl_t *doc = (proto_doc_impl_t *)calloc(1, sizeof(*doc));
  if (!doc) {
    return NULL;
  }
  proto_arena_init(&doc->arena, 0);
  proto_row_init((proto_doc_t *)doc);
  return (proto_doc_t *)doc;
}

void proto_doc_destroy(proto_doc_t *doc) {
  if (!doc) {
    return;
  }
  proto_doc_impl_t *d = (proto_doc_impl_t *)doc;
  proto_arena_free(&d->arena);
  free(d);
}

int proto_set_entry(proto_doc_impl_t *doc, const char *key, char *value,
                      int exported) {
  for (size_t i = 0; i < doc->count; i++) {
    if (strcmp(doc->entries[i].key, key) == 0) {
      doc->entries[i].value = value;
      doc->entries[i].exported = exported;
      return 0;
    }
  }
  if (proto_grow_ptr((void **)&doc->entries, sizeof(proto_entry_t),
                       &doc->count, &doc->cap) != 0) {
    return -1;
  }
  size_t idx = doc->count++;
  doc->entries[idx].key = proto_arena_strdup(&doc->arena, key);
  if (!doc->entries[idx].key) {
    doc->count--;
    return -1;
  }
  doc->entries[idx].value = value;
  doc->entries[idx].exported = exported;
  return 0;
}

const char *proto_store_get(const proto_doc_impl_t *doc, const char *key) {
  for (size_t i = 0; i < doc->count; i++) {
    if (strcmp(doc->entries[i].key, key) == 0) {
      return doc->entries[i].value;
    }
  }
  return NULL;
}

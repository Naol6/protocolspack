#include "diff.h"

#include "store.h"

#include <stdlib.h>
#include <string.h>

static int proto_diff_grow(proto_diff_t *diff) {
  if (diff->count < diff->cap) {
    return 0;
  }
  size_t new_cap = diff->cap ? diff->cap * 2 : 8;
  proto_diff_entry_t *p =
      (proto_diff_entry_t *)realloc(diff->entries, new_cap * sizeof(*p));
  if (!p) {
    return -1;
  }
  diff->entries = p;
  diff->cap = new_cap;
  return 0;
}

static int proto_diff_push(proto_diff_t *diff, proto_diff_kind_t kind,
                             const char *key, const char *old_val,
                             const char *new_val) {
  if (proto_diff_grow(diff) != 0) {
    return -1;
  }
  proto_diff_entry_t *e = &diff->entries[diff->count++];
  e->kind = kind;
  e->key = key;
  e->old_value = old_val;
  e->new_value = new_val;
  return 0;
}

proto_diff_t *proto_diff_create(void) {
  return (proto_diff_t *)calloc(1, sizeof(proto_diff_t));
}

void proto_diff_free(proto_diff_t *diff) {
  if (!diff) {
    return;
  }
  free(diff->entries);
  free(diff);
}

int proto_diff_documents(const proto_doc_t *old_doc, const proto_doc_t *new_doc,
                           proto_diff_t *diff) {
  const proto_doc_impl_t *o = (const proto_doc_impl_t *)old_doc;
  const proto_doc_impl_t *n = (const proto_doc_impl_t *)new_doc;
  if (!diff) {
    return -1;
  }
  if (o) {
    for (size_t i = 0; i < o->count; i++) {
      const char *key = o->entries[i].key;
      const char *old_val = o->entries[i].value;
      const char *new_val = n ? proto_store_get(n, key) : NULL;
      if (!new_val) {
        if (proto_diff_push(diff, PROTO_DIFF_REMOVED, key, old_val, NULL) != 0) {
          return -1;
        }
      } else if (strcmp(old_val, new_val) != 0) {
        if (proto_diff_push(diff, PROTO_DIFF_CHANGED, key, old_val, new_val) != 0) {
          return -1;
        }
      }
    }
  }
  if (n) {
    for (size_t j = 0; j < n->count; j++) {
      const char *key = n->entries[j].key;
      if (!o || !proto_store_get(o, key)) {
        if (proto_diff_push(diff, PROTO_DIFF_ADDED, key, NULL,
                              n->entries[j].value) != 0) {
          return -1;
        }
      }
    }
  }
  return 0;
}

size_t proto_diff_count(const proto_diff_t *diff) {
  return diff ? diff->count : 0;
}

const proto_diff_entry_t *proto_diff_at(const proto_diff_t *diff, size_t idx) {
  if (!diff || idx >= diff->count) {
    return NULL;
  }
  return &diff->entries[idx];
}

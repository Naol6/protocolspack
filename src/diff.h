#ifndef PROTO_DIFF_H
#define PROTO_DIFF_H

#include "protocolspack/proto_types.h"

typedef enum proto_diff_kind {
  PROTO_DIFF_ADDED = 0,
  PROTO_DIFF_REMOVED,
  PROTO_DIFF_CHANGED
} proto_diff_kind_t;

typedef struct proto_diff_entry {
  proto_diff_kind_t kind;
  const char *key;
  const char *old_value;
  const char *new_value;
} proto_diff_entry_t;

typedef struct proto_diff {
  proto_diff_entry_t *entries;
  size_t count;
  size_t cap;
} proto_diff_t;

proto_diff_t *proto_diff_create(void);
void proto_diff_free(proto_diff_t *diff);
int proto_diff_documents(const proto_doc_t *old_doc, const proto_doc_t *new_doc,
                           proto_diff_t *diff);
size_t proto_diff_count(const proto_diff_t *diff);
const proto_diff_entry_t *proto_diff_at(const proto_diff_t *diff, size_t idx);

#endif /* PROTO_DIFF_H */

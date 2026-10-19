#ifndef PROTO_STORE_H
#define PROTO_STORE_H

#include "arena.h"
#include "protocolspack/proto_types.h"
#include "protocolspack/protocol.h"

typedef struct proto_entry {
  char *key;
  char *value;
  int exported;
} proto_entry_t;

typedef struct proto_row_table {
  proto_row_t *items;
  size_t count;
  size_t cap;
  long active;
} proto_row_table_t;

typedef struct proto_doc {
  proto_entry_t *entries;
  proto_row_table_t rows;
  size_t count;
  size_t cap;
  char *active_profile;
  proto_arena_t arena;
} proto_doc_impl_t;

proto_doc_t *proto_doc_create(void);
void proto_doc_destroy(proto_doc_t *doc);
int proto_set_entry(proto_doc_impl_t *doc, const char *key, char *value,
                      int exported);
const char *proto_store_get(const proto_doc_impl_t *doc, const char *key);

#endif /* PROTO_STORE_H */

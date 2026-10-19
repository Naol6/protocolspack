#ifndef PROTOCOLSPACK_PROTOCOL_H
#define PROTOCOLSPACK_PROTOCOL_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct proto_row {
  char *name;
  int number;
  char *aliases;
  uint32_t flags;
} proto_row_t;

typedef struct proto_doc proto_doc_t;

void proto_row_init(proto_doc_t *doc);
int proto_row_begin(proto_doc_t *doc, const char *name);
int proto_row_set_number(proto_doc_t *doc, int number);
int proto_row_add_alias(proto_doc_t *doc, const char *alias);
size_t proto_row_count(const proto_doc_t *doc);
const proto_row_t *proto_row_get(const proto_doc_t *doc, size_t idx);

#ifdef __cplusplus
}
#endif

#endif

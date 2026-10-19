#ifndef PROTO_INCLUDE_STACK_H
#define PROTO_INCLUDE_STACK_H

#include <stddef.h>

typedef struct proto_import_stack {
  char **paths;
  size_t count;
  size_t cap;
} proto_import_stack_t;

void proto_import_stack_init(proto_import_stack_t *st);
void proto_import_stack_free(proto_import_stack_t *st);
int proto_import_stack_push(proto_import_stack_t *st, const char *path);
void proto_import_stack_pop(proto_import_stack_t *st);
int proto_import_stack_has(proto_import_stack_t *st, const char *path);

#endif /* PROTO_INCLUDE_STACK_H */

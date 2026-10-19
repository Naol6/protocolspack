#ifndef PROTO_ARENA_H
#define PROTO_ARENA_H

#include <stddef.h>

typedef struct proto_arena_block {
  struct proto_arena_block *next;
  size_t cap;
  size_t used;
  char data[1];
} proto_arena_block_t;

typedef struct proto_arena {
  proto_arena_block_t *head;
  size_t block_size;
} proto_arena_t;

void proto_arena_init(proto_arena_t *a, size_t block_size);
void proto_arena_free(proto_arena_t *a);
void *proto_arena_alloc(proto_arena_t *a, size_t size, size_t align);
char *proto_arena_strdup(proto_arena_t *a, const char *s);
char *proto_arena_strndup(proto_arena_t *a, const char *s, size_t n);

#endif /* PROTO_ARENA_H */

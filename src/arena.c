#include "arena.h"

#include <stdlib.h>
#include <string.h>

#define PROTO_ARENA_DEFAULT_BLOCK 4096

static size_t proto_align_up(size_t n, size_t align) {
  return (n + align - 1) & ~(align - 1);
}

void proto_arena_init(proto_arena_t *a, size_t block_size) {
  a->head = NULL;
  a->block_size = block_size ? block_size : PROTO_ARENA_DEFAULT_BLOCK;
}

static proto_arena_block_t *proto_arena_new_block(size_t payload) {
  size_t cap = payload < PROTO_ARENA_DEFAULT_BLOCK ? PROTO_ARENA_DEFAULT_BLOCK
                                                   : payload;
  size_t total = sizeof(proto_arena_block_t) - 1 + cap;
  proto_arena_block_t *b = (proto_arena_block_t *)malloc(total);
  if (!b) {
    return NULL;
  }
  b->next = NULL;
  b->cap = cap;
  b->used = 0;
  return b;
}

void proto_arena_free(proto_arena_t *a) {
  proto_arena_block_t *b = a->head;
  while (b) {
    proto_arena_block_t *n = b->next;
    free(b);
    b = n;
  }
  a->head = NULL;
}

void *proto_arena_alloc(proto_arena_t *a, size_t size, size_t align) {
  if (align == 0 || (align & (align - 1)) != 0) {
    align = sizeof(void *);
  }
  if (size == 0) {
    size = 1;
  }
  proto_arena_block_t *b = a->head;
  if (!b) {
    b = proto_arena_new_block(a->block_size);
    if (!b) {
      return NULL;
    }
    a->head = b;
  }
  size_t off = proto_align_up(b->used, align);
  if (off + size > b->cap) {
    proto_arena_block_t *nb = proto_arena_new_block(size + align);
    if (!nb) {
      return NULL;
    }
    nb->next = b->next;
    b->next = nb;
    b = nb;
    off = 0;
  }
  void *p = b->data + off;
  b->used = off + size;
  return p;
}

char *proto_arena_strdup(proto_arena_t *a, const char *s) {
  size_t n = strlen(s);
  char *p = (char *)proto_arena_alloc(a, n + 1, 1);
  if (!p) {
    return NULL;
  }
  memcpy(p, s, n + 1);
  return p;
}

char *proto_arena_strndup(proto_arena_t *a, const char *s, size_t n) {
  char *p = (char *)proto_arena_alloc(a, n + 1, 1);
  if (!p) {
    return NULL;
  }
  memcpy(p, s, n);
  p[n] = '\0';
  return p;
}

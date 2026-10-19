#include "import_stack.h"

#include "protocolspack_internal.h"

#include <stdlib.h>
#include <string.h>

void proto_import_stack_init(proto_import_stack_t *st) {
  st->paths = NULL;
  st->count = 0;
  st->cap = 0;
}

void proto_import_stack_free(proto_import_stack_t *st) {
  for (size_t i = 0; i < st->count; i++) {
    free(st->paths[i]);
  }
  free(st->paths);
  st->paths = NULL;
  st->count = 0;
  st->cap = 0;
}

int proto_import_stack_push(proto_import_stack_t *st, const char *path) {
  if (st->count >= st->cap) {
    size_t new_cap = st->cap ? st->cap * 2 : 8;
    char **p = (char **)realloc(st->paths, new_cap * sizeof(char *));
    if (!p) {
      return -1;
    }
    st->paths = p;
    st->cap = new_cap;
  }
  st->paths[st->count] = proto_strdup(path);
  if (!st->paths[st->count]) {
    return -1;
  }
  st->count++;
  return 0;
}

void proto_import_stack_pop(proto_import_stack_t *st) {
  if (st->count == 0) {
    return;
  }
  st->count--;
  free(st->paths[st->count]);
  st->paths[st->count] = NULL;
}

int proto_import_stack_has(proto_import_stack_t *st, const char *path) {
  for (size_t i = 0; i < st->count; i++) {
    if (strcmp(st->paths[i], path) == 0) {
      return 1;
    }
  }
  return 0;
}

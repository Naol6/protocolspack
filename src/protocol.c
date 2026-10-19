#include "protocolspack/protocol.h"

#include "store.h"

#include <stdlib.h>
#include <string.h>

static proto_row_table_t *rows(proto_doc_t *doc) {
  proto_doc_impl_t *d = (proto_doc_impl_t *)doc;
  return &d->rows;
}

static int grow(proto_row_table_t *t) {
  size_t cap = t->cap ? t->cap * 2 : 4;
  proto_row_t *next = (proto_row_t *)realloc(t->items, cap * sizeof(*next));
  if (!next) {
    return -1;
  }
  t->items = next;
  t->cap = cap;
  return 0;
}

void proto_row_init(proto_doc_t *doc) {
  proto_row_table_t *t = rows(doc);
  t->items = NULL;
  t->count = 0;
  t->cap = 0;
  t->active = -1;
}

int proto_row_begin(proto_doc_t *doc, const char *name) {
  proto_row_table_t *t = rows(doc);
  proto_row_t *r;
  if (!doc || !name) {
    return -1;
  }
  if (t->count >= t->cap && grow(t) != 0) {
    return -1;
  }
  r = &t->items[t->count++];
  memset(r, 0, sizeof(*r));
  r->name = strdup(name);
  if (!r->name) {
    t->count--;
    return -1;
  }
  t->active = (ssize_t)(t->count - 1);
  return 0;
}

int proto_row_set_number(proto_doc_t *doc, int number) {
  proto_row_table_t *t = rows(doc);
  proto_row_t *r;
  if (!doc || t->active < 0 || (size_t)t->active >= t->count) {
    return -1;
  }
  r = &t->items[t->active];
  r->number = number;
  return 0;
}

int proto_row_add_alias(proto_doc_t *doc, const char *alias) {
  proto_row_table_t *t = rows(doc);
  proto_row_t *r;
  char *next;
  size_t alen;
  if (!doc || !alias || t->active < 0 || (size_t)t->active >= t->count) {
    return -1;
  }
  r = &t->items[t->active];
  alen = strlen(alias);
  if (!r->aliases || r->aliases[0] == '\0') {
    free(r->aliases);
    r->aliases = strdup(alias);
    return r->aliases ? 0 : -1;
  }
  next = (char *)realloc(r->aliases, strlen(r->aliases) + alen + 2);
  if (!next) {
    return -1;
  }
  r->aliases = next;
  strcat(r->aliases, " ");
  strcat(r->aliases, alias);
  return 0;
}

size_t proto_row_count(const proto_doc_t *doc) {
  const proto_row_table_t *t = rows((proto_doc_t *)doc);
  return doc ? t->count : 0;
}

const proto_row_t *proto_row_get(const proto_doc_t *doc, size_t idx) {
  const proto_row_table_t *t = rows((proto_doc_t *)doc);
  if (!doc || idx >= t->count) {
    return NULL;
  }
  return &t->items[idx];
}

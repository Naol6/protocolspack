#include "query.h"

#include "protocolspack_internal.h"
#include "store.h"
#include "strutil.h"
#include "walk.h"

#include <stdlib.h>
#include <string.h>

size_t proto_query_prefix(const proto_doc_t *doc, const char *prefix,
                            const char ***out_keys, size_t *out_count) {
  const proto_doc_impl_t *d = (const proto_doc_impl_t *)doc;
  if (!d || !prefix || !out_keys || !out_count) {
    return 0;
  }
  size_t plen = strlen(prefix);
  size_t n = 0;
  for (size_t i = 0; i < d->count; i++) {
    const char *k = d->entries[i].key;
    if (strncmp(k, prefix, plen) == 0 && (plen == 0 || k[plen] == '.' || k[plen] == '\0')) {
      n++;
    }
  }
  if (n == 0) {
    *out_keys = NULL;
    *out_count = 0;
    return 0;
  }
  const char **keys = (const char **)malloc(n * sizeof(char *));
  if (!keys) {
    return 0;
  }
  size_t j = 0;
  for (size_t i = 0; i < d->count; i++) {
    const char *k = d->entries[i].key;
    if (strncmp(k, prefix, plen) == 0 && (plen == 0 || k[plen] == '.' || k[plen] == '\0')) {
      keys[j++] = k;
    }
  }
  *out_keys = keys;
  *out_count = n;
  return n;
}

const char *proto_query_first(const proto_doc_t *doc, const char *prefix) {
  const proto_doc_impl_t *d = (const proto_doc_impl_t *)doc;
  if (!d || !prefix) {
    return NULL;
  }
  size_t plen = strlen(prefix);
  for (size_t i = 0; i < d->count; i++) {
    const char *k = d->entries[i].key;
    if (strncmp(k, prefix, plen) == 0 && (plen == 0 || k[plen] == '.' || k[plen] == '\0')) {
      return d->entries[i].value;
    }
  }
  return NULL;
}

int proto_query_has_prefix(const proto_doc_t *doc, const char *prefix) {
  return proto_query_first(doc, prefix) != NULL ||
         (proto_count_entries(doc) > 0 && prefix && prefix[0] == '\0');
}

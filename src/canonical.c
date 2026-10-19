#include "canonical.h"

#include "store.h"

#include <ctype.h>
#include <string.h>

int proto_canonicalize_key_inplace(char *key) {
  if (!key) {
    return -1;
  }
  for (char *p = key; *p; p++) {
    *p = (char)toupper((unsigned char)*p);
  }
  return 0;
}

int proto_canonicalize_keys(proto_doc_t *doc) {
  proto_doc_impl_t *d = (proto_doc_impl_t *)doc;
  if (!d) {
    return -1;
  }
  for (size_t i = 0; i < d->count; i++) {
    if (proto_canonicalize_key_inplace(d->entries[i].key) != 0) {
      return -1;
    }
  }
  return 0;
}

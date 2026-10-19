#include "validate.h"

#include "store.h"
#include "strutil.h"

#include <string.h>

proto_validate_code_t proto_validate_doc(const proto_doc_t *doc) {
  const proto_doc_impl_t *d = (const proto_doc_impl_t *)doc;
  if (!d) {
    return PROTO_VALIDATE_OK;
  }

  for (size_t i = 0; i < d->count; i++) {
    const char *key = d->entries[i].key;
    if (!key || key[0] == '\0') {
      return PROTO_VALIDATE_EMPTY_KEY;
    }
    if (!proto_is_key_start(key[0])) {
      return PROTO_VALIDATE_INVALID_KEY;
    }
    for (size_t j = 0; key[j]; j++) {
      if (!proto_is_key_char(key[j])) {
        return PROTO_VALIDATE_INVALID_KEY;
      }
    }
    for (size_t j = i + 1; j < d->count; j++) {
      if (strcmp(key, d->entries[j].key) == 0) {
        return PROTO_VALIDATE_DUPLICATE_KEY;
      }
    }
  }
  return PROTO_VALIDATE_OK;
}

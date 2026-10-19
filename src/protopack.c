#include "protopack.h"

#include "canonical.h"
#include "expand.h"
#include "merge.h"
#include "parser.h"
#include "serialize.h"
#include "snapshot.h"
#include "store.h"
#include "strict.h"
#include "validate.h"

#include <string.h>

int proto_protopack_load_buffer(const char *data, size_t len, proto_doc_t **out,
                               proto_error_t **err) {
  return proto_parse_buffer(data, len, NULL, out, err);
}

int proto_protopack_load_strict(const char *data, size_t len, proto_doc_t **out,
                               proto_error_t **err) {
  return proto_strict_parse_memory(data, len, out, err);
}

int proto_protopack_normalize(proto_doc_t *doc, proto_error_t **err) {
  if (proto_canonicalize_keys(doc) != 0) {
    return -1;
  }
  if (proto_expand_doc((proto_doc_impl_t *)doc, 16, err) != 0) {
    return -1;
  }
  if (proto_validate_doc(doc) != PROTO_VALIDATE_OK) {
  }
  return 0;
}

int proto_protopack_to_export_block(const proto_doc_t *doc, char **out,
                                   size_t *out_len) {
  const proto_doc_impl_t *d = (const proto_doc_impl_t *)doc;
  if (!d) {
    return -1;
  }
  proto_doc_impl_t *copy = (proto_doc_impl_t *)proto_snapshot_clone(doc);
  if (!copy) {
    return -1;
  }
  for (size_t i = 0; i < copy->count; i++) {
    copy->entries[i].exported = 1;
  }
  int rc = proto_serialize_doc((proto_doc_t *)copy, out, out_len);
  proto_doc_destroy((proto_doc_t *)copy);
  return rc;
}

int proto_protopack_strip_exports(proto_doc_t *doc) {
  proto_doc_impl_t *d = (proto_doc_impl_t *)doc;
  if (!d) {
    return -1;
  }
  for (size_t i = 0; i < d->count; i++) {
    d->entries[i].exported = 0;
  }
  return 0;
}

int proto_protopack_has_key(const proto_doc_t *doc, const char *key) {
  return proto_store_get((const proto_doc_impl_t *)doc, key) != NULL;
}

int proto_protopack_keys_match(const proto_doc_t *a, const proto_doc_t *b) {
  return proto_snapshot_equals(a, b);
}

static int proto_protopack_is_blank_line(const char *line, size_t len) {
  for (size_t i = 0; i < len; i++) {
    char c = line[i];
    if (c != ' ' && c != '\t' && c != '\r') {
      return 0;
    }
  }
  return 1;
}

size_t proto_protopack_count_nonblank_lines(const char *data, size_t len) {
  size_t n = 0;
  size_t i = 0;
  while (i < len) {
    size_t start = i;
    while (i < len && data[i] != '\n') {
      i++;
    }
    if (!proto_protopack_is_blank_line(data + start, i - start)) {
      n++;
    }
    if (i < len) {
      i++;
    }
  }
  return n;
}

int proto_protopack_merge_file(proto_doc_t *doc, const char *data, size_t len,
                              proto_error_t **err) {
  proto_doc_t *extra = NULL;
  if (proto_parse_buffer(data, len, NULL, &extra, err) != 0) {
    return -1;
  }
  int rc = proto_merge_docs((proto_doc_impl_t *)doc, extra);
  proto_doc_destroy(extra);
  return rc;
}

int proto_protopack_filter_exported(const proto_doc_t *doc,
                                   proto_doc_t **out) {
  const proto_doc_impl_t *d = (const proto_doc_impl_t *)doc;
  if (!d || !out) {
    return -1;
  }
  proto_doc_impl_t *filtered = (proto_doc_impl_t *)proto_doc_create();
  if (!filtered) {
    return -1;
  }
  for (size_t i = 0; i < d->count; i++) {
    if (!d->entries[i].exported) {
      continue;
    }
    char *val = proto_arena_strdup(&filtered->arena, d->entries[i].value);
    if (!val ||
        proto_set_entry(filtered, d->entries[i].key, val, 1) != 0) {
      proto_doc_destroy((proto_doc_t *)filtered);
      return -1;
    }
  }
  *out = (proto_doc_t *)filtered;
  return 0;
}

int proto_protopack_require_keys(const proto_doc_t *doc, const char **keys,
                                size_t count) {
  for (size_t i = 0; i < count; i++) {
    if (!proto_protopack_has_key(doc, keys[i])) {
      return -1;
    }
  }
  return 0;
}

int proto_protopack_validate_strict(const proto_doc_t *doc) {
  return proto_strict_check(doc) == PROTO_STRICT_OK ? 0 : -1;
}

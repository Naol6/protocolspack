#include "protocolspack/proto.h"

#include "coerce.h"
#include "protomap.h"
#include "error.h"
#include "expand.h"
#include "merge.h"
#include "parser.h"
#include "pretty.h"
#include "profile.h"
#include "serialize.h"
#include "store.h"
#include "validate.h"
#include "walk.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

proto_options_t proto_default_options(void) {
  proto_options_t opt;
  opt.strict = 0;
  return opt;
}

int proto_parse_memory(const char *data, size_t len,
                         const proto_options_t *opt,
                         proto_doc_t **out_doc, proto_error_t **out_err) {
  return proto_parse_buffer(data, len, opt, out_doc, out_err);
}

int proto_parse_memory_with_includes(
    const char *data, size_t len, const proto_options_t *opt,
    proto_read_include_fn read_fn, void *read_ctx,
    proto_doc_t **out_doc, proto_error_t **out_err) {
  return proto_parse_buffer_with_includes(data, len, opt, read_fn, read_ctx,
                                            out_doc, out_err);
}

int proto_parse_file(const char *path, const proto_options_t *opt,
                       proto_doc_t **out_doc, proto_error_t **out_err) {
  FILE *f = fopen(path, "rb");
  if (!f) {
    if (out_err) {
      *out_err = proto_error_new("cannot open file", 0, 0);
    }
    return -1;
  }
  if (fseek(f, 0, SEEK_END) != 0) {
    fclose(f);
    return -1;
  }
  long sz = ftell(f);
  if (sz < 0) {
    fclose(f);
    return -1;
  }
  if (fseek(f, 0, SEEK_SET) != 0) {
    fclose(f);
    return -1;
  }
  char *buf = (char *)malloc((size_t)sz + 1);
  if (!buf) {
    fclose(f);
    return -1;
  }
  size_t n = fread(buf, 1, (size_t)sz, f);
  fclose(f);
  buf[n] = '\0';
  int rc = proto_parse_buffer(buf, n, opt, out_doc, out_err);
  free(buf);
  return rc;
}

void proto_doc_free(proto_doc_t *doc) { proto_doc_destroy(doc); }

void proto_error_free(proto_error_t *err) { proto_error_destroy(err); }

const char *proto_error_message(const proto_error_t *err) {
  return err && err->message ? err->message : "";
}

int proto_error_line(const proto_error_t *err) {
  return err ? err->line : 0;
}

int proto_error_column(const proto_error_t *err) {
  return err ? err->column : 0;
}

size_t proto_entry_count(const proto_doc_t *doc) {
  return proto_count_entries(doc);
}

const char *proto_entry_key(const proto_doc_t *doc, size_t idx) {
  const proto_doc_impl_t *d = (const proto_doc_impl_t *)doc;
  if (!d || idx >= d->count) {
    return NULL;
  }
  return d->entries[idx].key;
}

const char *proto_entry_value(const proto_doc_t *doc, size_t idx) {
  const proto_doc_impl_t *d = (const proto_doc_impl_t *)doc;
  if (!d || idx >= d->count) {
    return NULL;
  }
  return d->entries[idx].value;
}

int proto_entry_exported(const proto_doc_t *doc, size_t idx) {
  const proto_doc_impl_t *d = (const proto_doc_impl_t *)doc;
  if (!d || idx >= d->count) {
    return 0;
  }
  return d->entries[idx].exported;
}

const char *proto_get(const proto_doc_t *doc, const char *key) {
  return proto_store_get((const proto_doc_impl_t *)doc, key);
}

const char *proto_get_profile(const proto_doc_t *doc, const char *profile,
                                const char *key) {
  return proto_profile_get((const proto_doc_impl_t *)doc, profile, key);
}

int proto_serialize(const proto_doc_t *doc, char **out_buf, size_t *out_len) {
  return proto_serialize_doc(doc, out_buf, out_len);
}

int proto_pretty_print(const proto_doc_t *doc, char **out_buf,
                         size_t *out_len) {
  return proto_format_pretty(doc, out_buf, out_len);
}

int proto_merge(proto_doc_t *dst, const proto_doc_t *src) {
  return proto_merge_docs(dst, src);
}

proto_validate_code_t proto_validate(const proto_doc_t *doc) {
  return proto_validate_doc(doc);
}

int proto_expand_all(proto_doc_t *doc, int max_depth, proto_error_t **err) {
  return proto_expand_doc((proto_doc_impl_t *)doc, max_depth, err);
}

int proto_coerce_bool_value(const char *value, int *out) {
  return proto_coerce_bool(value, out);
}

int proto_coerce_int_value(const char *value, long long *out) {
  return proto_coerce_int(value, out);
}

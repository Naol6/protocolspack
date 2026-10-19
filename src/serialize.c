#include "serialize.h"

#include "buffer.h"
#include "store.h"

#include <stdlib.h>
#include <string.h>

static int proto_needs_quotes(const char *s) {
  for (const char *p = s; *p; p++) {
    char c = *p;
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '#' ||
        c == '"' || c == '\'' || c == '\\' || c == '=') {
      return 1;
    }
  }
  return 0;
}

static int proto_append_escaped(proto_buffer_t *buf, const char *s) {
  if (proto_buffer_append_char(buf, '"') != 0) {
    return -1;
  }
  for (const char *p = s; *p; p++) {
    char c = *p;
    if (c == '"' || c == '\\') {
      if (proto_buffer_append_char(buf, '\\') != 0) {
        return -1;
      }
    }
    if (c == '\n') {
      if (proto_buffer_append_cstr(buf, "\\n") != 0) {
        return -1;
      }
      continue;
    }
    if (c == '\t') {
      if (proto_buffer_append_cstr(buf, "\\t") != 0) {
        return -1;
      }
      continue;
    }
    if (c == '\r') {
      if (proto_buffer_append_cstr(buf, "\\r") != 0) {
        return -1;
      }
      continue;
    }
    if (proto_buffer_append_char(buf, c) != 0) {
      return -1;
    }
  }
  if (proto_buffer_append_char(buf, '"') != 0) {
    return -1;
  }
  return 0;
}

int proto_serialize_doc(const proto_doc_t *doc, char **out_buf,
                          size_t *out_len) {
  const proto_doc_impl_t *d = (const proto_doc_impl_t *)doc;
  if (!d || !out_buf || !out_len) {
    return -1;
  }

  proto_buffer_t buf;
  proto_buffer_init(&buf);

  for (size_t i = 0; i < d->count; i++) {
    if (d->entries[i].exported) {
      if (proto_buffer_append_cstr(&buf, "export ") != 0) {
        goto fail;
      }
    }
    if (proto_buffer_append(&buf, d->entries[i].key,
                              strlen(d->entries[i].key)) != 0) {
      goto fail;
    }
    if (proto_buffer_append_cstr(&buf, "=") != 0) {
      goto fail;
    }
    const char *val = d->entries[i].value ? d->entries[i].value : "";
    if (proto_needs_quotes(val)) {
      if (proto_append_escaped(&buf, val) != 0) {
        goto fail;
      }
    } else {
      if (proto_buffer_append_cstr(&buf, val) != 0) {
        goto fail;
      }
    }
    if (proto_buffer_append_char(&buf, '\n') != 0) {
      goto fail;
    }
  }

  *out_buf = (char *)malloc(buf.len + 1);
  if (!*out_buf) {
    goto fail;
  }
  memcpy(*out_buf, buf.data, buf.len + 1);
  *out_len = buf.len;
  proto_buffer_free(&buf);
  return 0;

fail:
  proto_buffer_free(&buf);
  return -1;
}

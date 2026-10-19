#include "pretty.h"

#include "buffer.h"
#include "serialize.h"
#include "store.h"

#include <stdlib.h>
#include <string.h>

int proto_pretty_entry(const char *key, const char *value, int exported,
                         char **out_line, size_t *out_len) {
  if (!key || !out_line || !out_len) {
    return -1;
  }
  proto_buffer_t buf;
  proto_buffer_init(&buf);
  if (exported) {
    proto_buffer_append_cstr(&buf, "export ");
  }
  proto_buffer_append_cstr(&buf, key);
  proto_buffer_append_cstr(&buf, " = ");
  if (value) {
    proto_buffer_append_cstr(&buf, value);
  }
  proto_buffer_append_char(&buf, '\n');
  *out_line = (char *)malloc(buf.len + 1);
  if (!*out_line) {
    proto_buffer_free(&buf);
    return -1;
  }
  memcpy(*out_line, buf.data, buf.len + 1);
  *out_len = buf.len;
  proto_buffer_free(&buf);
  return 0;
}

int proto_format_pretty(const proto_doc_t *doc, char **out_buf, size_t *out_len) {
  const proto_doc_impl_t *d = (const proto_doc_impl_t *)doc;
  if (!d || !out_buf || !out_len) {
    return -1;
  }
  proto_buffer_t buf;
  proto_buffer_init(&buf);
  for (size_t i = 0; i < d->count; i++) {
    char *line = NULL;
    size_t line_len = 0;
    if (proto_pretty_entry(d->entries[i].key, d->entries[i].value,
                             d->entries[i].exported, &line, &line_len) != 0) {
      proto_buffer_free(&buf);
      return -1;
    }
    proto_buffer_append(&buf, line, line_len);
    free(line);
  }
  *out_buf = (char *)malloc(buf.len + 1);
  if (!*out_buf) {
    proto_buffer_free(&buf);
    return -1;
  }
  memcpy(*out_buf, buf.data, buf.len + 1);
  *out_len = buf.len;
  proto_buffer_free(&buf);
  return 0;
}

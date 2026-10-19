#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "protocolspack/proto.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  if (!data || size == 0) {
    return 0;
  }

  const char *root = (const char *)data;
  size_t root_len = strnlen(root, size);
  const uint8_t *tail_start = data;
  size_t tail_size = 0;
  if (root_len + 1 <= size) {
    tail_start = data + root_len + 1;
    tail_size = size - (root_len + 1);
  }

  proto_doc_t *primary = NULL;
  proto_doc_t *secondary = NULL;
  proto_error_t *err = NULL;
  proto_options_t opt = proto_default_options();

  proto_parse_memory(root, root_len, &opt, &primary, &err);
  proto_error_free(err);
  err = NULL;

  if (tail_size > 0) {
    proto_parse_memory((const char *)tail_start, tail_size, &opt, &secondary,
                         &err);
    proto_error_free(err);
    err = NULL;
  }

  if (primary && secondary) {
    proto_merge(primary, secondary);
    proto_validate(primary);
  }

  if (primary) {
    char *out = NULL;
    size_t out_len = 0;
    proto_serialize(primary, &out, &out_len);
    free(out);
    proto_doc_free(primary);
  }
  if (secondary) {
    proto_doc_free(secondary);
  }
  return 0;
}

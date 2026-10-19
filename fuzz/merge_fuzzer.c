#include "protocolspack/proto.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  size_t split;
  proto_doc_t *base = NULL;
  proto_doc_t *overlay = NULL;
  proto_error_t *err = NULL;

  if (!data || size < 2 || size > 65536) {
    return 0;
  }
  split = data[0] % (size - 1);
  if (split == 0) {
    split = 1;
  }
  if (proto_parse_memory((const char *)data + 1, split - 1, NULL, &base, &err) != 0) {
    proto_error_free(err);
    return 0;
  }
  err = NULL;
  if (proto_parse_memory((const char *)data + split, size - split, NULL, &overlay, &err) == 0) {
    proto_merge(base, overlay);
    proto_doc_free(overlay);
  }
  proto_error_free(err);
  proto_doc_free(base);
  return 0;
}

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "protocolspack/proto.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  if (!data) {
    return 0;
  }
  proto_doc_t *doc = NULL;
  proto_error_t *err = NULL;
  proto_options_t opt = proto_default_options();
  proto_parse_memory((const char *)data, size, &opt, &doc, &err);
  proto_error_free(err);
  if (doc) {
    proto_validate(doc);
    char *out = NULL;
    size_t out_len = 0;
    if (proto_serialize(doc, &out, &out_len) == 0 && out) {
      proto_doc_t *again = NULL;
      proto_error_t *err2 = NULL;
      proto_parse_memory(out, out_len, &opt, &again, &err2);
      proto_error_free(err2);
      proto_doc_free(again);
    }
    free(out);
    proto_doc_free(doc);
  }
  return 0;
}

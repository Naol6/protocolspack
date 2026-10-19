#include "protocolspack/alias.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  proto_alias_t *m;
  size_t i;

  if (!data || size == 0 || size > 4096) {
    return 0;
  }
  m = proto_alias_create();
  if (!m) {
    return 0;
  }
  proto_alias_begin(m, "batch");
  for (i = 0; i < size; i++) {
    size_t n = (size_t)(data[i] % 12) + 1;
    if (i + n > size) {
      n = size - i;
    }
    proto_alias_append_token(m, (const char *)data + i, n);
    i += n > 0 ? n - 1 : 0;
  }
  (void)proto_alias_finalize_digest(m);
  proto_alias_destroy(m);
  return 0;
}

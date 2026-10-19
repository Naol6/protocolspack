#include "protocolspack/proto.h"
#include "unity.h"

#include <stdlib.h>
#include <string.h>

void test_serialize_roundtrip(void) {
  const char *src = "export HOST=\"127.0.0.1\"\nPORT=3000\n";
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));

  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  TEST_ASSERT_NOT_NULL(out);

  proto_doc_t *again = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &again, NULL));
  TEST_ASSERT_EQUAL_INT(2, (int)proto_entry_count(again));
  TEST_ASSERT_EQUAL_STRING("127.0.0.1", proto_get(again, "HOST"));
  TEST_ASSERT_EQUAL_STRING("3000", proto_get(again, "PORT"));

  free(out);
  proto_doc_free(doc);
  proto_doc_free(again);
}

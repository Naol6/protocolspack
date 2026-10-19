#include "protocolspack/proto.h"
#include "unity.h"

#include <string.h>
#include <string.h>

void test_validate_ok(void) {
  const char *src = "VALID_KEY=value\n";
  proto_doc_t *doc = NULL;
  proto_parse_memory(src, strlen(src), NULL, &doc, NULL);
  TEST_ASSERT_EQUAL_INT(PROTO_VALIDATE_OK, proto_validate(doc));
  proto_doc_free(doc);
}

void test_validate_last_key_wins(void) {
  const char *src = "KEY=a\nKEY=b\n";
  proto_doc_t *doc = NULL;
  proto_parse_memory(src, strlen(src), NULL, &doc, NULL);
  TEST_ASSERT_EQUAL_INT(PROTO_VALIDATE_OK, proto_validate(doc));
  TEST_ASSERT_EQUAL_STRING("b", proto_get(doc, "KEY"));
  proto_doc_free(doc);
}

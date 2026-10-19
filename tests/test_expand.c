#include "protocolspack/proto.h"
#include "unity.h"

#include <string.h>

void test_expand_simple(void) {
  const char *src = "BASE=hello\nMSG=${BASE}_world\n";
  proto_doc_t *doc = NULL;
  proto_error_t *err = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_expand_all(doc, 4, &err));
  proto_error_free(err);
  TEST_ASSERT_EQUAL_STRING("hello_world", proto_get(doc, "MSG"));
  proto_doc_free(doc);
}

void test_expand_dollar_var(void) {
  const char *src = "HOST=localhost\nURL=$HOST\n";
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_expand_all(doc, 4, NULL));
  TEST_ASSERT_EQUAL_STRING("localhost", proto_get(doc, "URL"));
  proto_doc_free(doc);
}

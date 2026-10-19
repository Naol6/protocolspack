#include "protocolspack/proto.h"
#include "unity.h"

#include <string.h>
void test_parse_minimal_assignment(void) {
  const char *src = "PORT=8080\n";
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_NOT_NULL(doc);
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  TEST_ASSERT_EQUAL_STRING("PORT", proto_entry_key(doc, 0));
  TEST_ASSERT_EQUAL_STRING("8080", proto_entry_value(doc, 0));
  proto_doc_free(doc);
}

void test_parse_export_and_comment(void) {
  const char *src = "# comment\nexport DATABASE_URL=postgres\n";
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  TEST_ASSERT_EQUAL_STRING("DATABASE_URL", proto_entry_key(doc, 0));
  proto_doc_free(doc);
}

void test_parse_quoted_value(void) {
  const char *src = "MSG=\"hello world\"\n";
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_STRING("hello world", proto_entry_value(doc, 0));
  proto_doc_free(doc);
}

void test_get_lookup(void) {
  const char *src = "FOO=bar\nBAZ=qux\n";
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_NOT_NULL(doc);
  TEST_ASSERT_EQUAL_STRING("bar", proto_get(doc, "FOO"));
  TEST_ASSERT_EQUAL_STRING("qux", proto_get(doc, "BAZ"));
  TEST_ASSERT_NULL(proto_get(doc, "MISSING"));
  proto_doc_free(doc);
}

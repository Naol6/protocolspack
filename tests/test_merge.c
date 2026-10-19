#include "protocolspack/proto.h"
#include "unity.h"

#include <string.h>
#include <string.h>

void test_merge_overlay(void) {
  const char *base = "A=1\nB=old\n";
  const char *overlay = "B=new\nC=3\n";
  proto_doc_t *doc = NULL;
  proto_doc_t *over = NULL;
  proto_parse_memory(base, strlen(base), NULL, &doc, NULL);
  proto_parse_memory(overlay, strlen(overlay), NULL, &over, NULL);
  TEST_ASSERT_EQUAL_INT(0, proto_merge(doc, over));
  TEST_ASSERT_EQUAL_STRING("1", proto_get(doc, "A"));
  TEST_ASSERT_EQUAL_STRING("new", proto_get(doc, "B"));
  TEST_ASSERT_EQUAL_STRING("3", proto_get(doc, "C"));
  proto_doc_free(doc);
  proto_doc_free(over);
}

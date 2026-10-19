#include "protocolspack/protocol.h"
#include "protocolspack/proto.h"
#include "unity/unity.h"

void test_protocol_row(void) {
  proto_doc_t *doc = proto_doc_create();
  TEST_ASSERT_NOT_NULL(doc);
  TEST_ASSERT_EQUAL(0, proto_row_begin(doc, "tcp"));
  TEST_ASSERT_EQUAL(0, proto_row_set_number(doc, 6));
  TEST_ASSERT_EQUAL(1, proto_row_count(doc));
  proto_doc_destroy(doc);
}

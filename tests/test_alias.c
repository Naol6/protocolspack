#include "protocolspack/alias.h"
#include "unity/unity.h"

void test_alias_tokens(void) {
  proto_alias_t *m = proto_alias_create();
  TEST_ASSERT_NOT_NULL(m);
  TEST_ASSERT_EQUAL(0, proto_alias_begin(m, "batch"));
  TEST_ASSERT_EQUAL(0, proto_alias_append_token(m, "TCP", 3));
  proto_alias_destroy(m);
}

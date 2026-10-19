#include "protocolspack/proto.h"
#include "unity.h"

#include <string.h>
void test_coerce_bool_true(void) {
  int v = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_coerce_bool_value("true", &v));
  TEST_ASSERT_EQUAL_INT(1, v);
}

void test_coerce_bool_false(void) {
  int v = 1;
  TEST_ASSERT_EQUAL_INT(0, proto_coerce_bool_value("off", &v));
  TEST_ASSERT_EQUAL_INT(0, v);
}

void test_coerce_int_value(void) {
  long long v = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_coerce_int_value("42", &v));
  TEST_ASSERT_EQUAL_INT(42, (int)v);
}

void test_coerce_from_doc(void) {
  const char *src = "PORT=9090\nDEBUG=true\n";
  proto_doc_t *doc = NULL;
  proto_parse_memory(src, strlen(src), NULL, &doc, NULL);
  long long port = 0;
  int dbg = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_coerce_int_value(proto_get(doc, "PORT"), &port));
  TEST_ASSERT_EQUAL_INT(0, proto_coerce_bool_value(proto_get(doc, "DEBUG"), &dbg));
  TEST_ASSERT_EQUAL_INT(9090, (int)port);
  TEST_ASSERT_EQUAL_INT(1, dbg);
  proto_doc_free(doc);
}

#include "unity.h"

extern void test_parse_minimal_assignment(void);
extern void test_parse_export_and_comment(void);
extern void test_parse_quoted_value(void);
extern void test_get_lookup(void);
extern void test_serialize_roundtrip(void);
extern void test_merge_overlay(void);
extern void test_validate_ok(void);
extern void test_validate_last_key_wins(void);
extern void test_expand_simple(void);
extern void test_expand_dollar_var(void);
extern void test_coerce_bool_true(void);
extern void test_coerce_bool_false(void);
extern void test_coerce_int_value(void);
extern void test_coerce_from_doc(void);

extern void run_scenario_tests(void);
extern void run_integration_tests(void);
extern void run_parser_deep_tests(void);
extern void run_lexer_exhaustive_tests(void);

int main(void) {
  UnityBegin("protocolspack");
  RUN_TEST(test_parse_minimal_assignment);
  RUN_TEST(test_parse_export_and_comment);
  RUN_TEST(test_parse_quoted_value);
  RUN_TEST(test_get_lookup);
  RUN_TEST(test_serialize_roundtrip);
  RUN_TEST(test_merge_overlay);
  RUN_TEST(test_validate_ok);
  RUN_TEST(test_validate_last_key_wins);
  RUN_TEST(test_expand_simple);
  RUN_TEST(test_expand_dollar_var);
  RUN_TEST(test_coerce_bool_true);
  RUN_TEST(test_coerce_bool_false);
  RUN_TEST(test_coerce_int_value);
  RUN_TEST(test_coerce_from_doc);
  run_scenario_tests();
  run_integration_tests();
  run_parser_deep_tests();
  run_lexer_exhaustive_tests();
  return UnityEnd();
}

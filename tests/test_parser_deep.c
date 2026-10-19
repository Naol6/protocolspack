#include "unity.h"
#include <stdio.h>
#include <string.h>
#include "protocolspack/proto.h"


void test_parser_deep_export_000(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_0=value_0\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_001(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_1=value_1\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_002(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_2=value_2\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_003(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_3=value_3\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_004(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_4=value_4\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_005(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_5=value_5\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_006(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_6=value_6\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_007(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_7=value_7\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_008(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_8=value_8\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_009(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_9=value_9\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_010(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_10=value_10\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_011(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_11=value_11\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_012(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_12=value_12\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_013(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_13=value_13\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_014(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_14=value_14\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_015(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_15=value_15\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_016(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_16=value_16\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_017(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_17=value_17\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_018(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_18=value_18\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_019(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_19=value_19\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_020(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_20=value_20\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_021(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_21=value_21\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_022(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_22=value_22\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_023(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_23=value_23\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_024(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_24=value_24\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_025(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_25=value_25\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_026(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_26=value_26\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_027(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_27=value_27\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_028(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_28=value_28\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_029(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_29=value_29\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_030(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_30=value_30\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_031(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_31=value_31\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_032(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_32=value_32\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_033(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_33=value_33\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_034(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_34=value_34\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_035(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_35=value_35\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_036(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_36=value_36\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_037(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_37=value_37\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_038(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_38=value_38\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_039(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_39=value_39\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_040(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_40=value_40\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_041(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_41=value_41\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_042(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_42=value_42\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_043(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_43=value_43\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_044(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_44=value_44\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_045(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_45=value_45\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_046(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_46=value_46\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_047(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_47=value_47\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_048(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_48=value_48\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_049(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_49=value_49\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_050(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_50=value_50\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_051(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_51=value_51\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_052(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_52=value_52\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_053(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_53=value_53\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_054(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_54=value_54\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_055(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_55=value_55\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_056(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_56=value_56\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_057(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_57=value_57\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_058(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_58=value_58\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_059(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_59=value_59\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_060(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_60=value_60\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_061(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_61=value_61\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_062(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_62=value_62\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_063(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_63=value_63\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_064(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_64=value_64\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_065(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_65=value_65\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_066(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_66=value_66\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_067(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_67=value_67\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_068(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_68=value_68\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_069(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_69=value_69\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_070(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_70=value_70\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_071(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_71=value_71\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_072(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_72=value_72\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_073(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_73=value_73\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_074(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_74=value_74\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_075(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_75=value_75\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_076(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_76=value_76\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_077(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_77=value_77\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_078(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_78=value_78\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_079(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_79=value_79\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_080(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_80=value_80\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_081(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_81=value_81\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_082(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_82=value_82\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_083(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_83=value_83\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_084(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_84=value_84\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_085(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_85=value_85\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_086(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_86=value_86\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_087(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_87=value_87\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_088(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_88=value_88\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_089(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_89=value_89\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_090(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_90=value_90\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_091(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_91=value_91\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_092(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_92=value_92\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_093(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_93=value_93\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_094(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_94=value_94\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_095(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_95=value_95\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_096(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_96=value_96\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_097(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_97=value_97\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_098(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_98=value_98\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}


void test_parser_deep_export_099(void) {
  char src[256];
  snprintf(src, sizeof(src), "export VAR_99=value_99\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, proto_entry_exported(doc, 0));
  proto_doc_free(doc);
}

void run_parser_deep_tests(void) {
  RUN_TEST(test_parser_deep_export_000);
  RUN_TEST(test_parser_deep_export_001);
  RUN_TEST(test_parser_deep_export_002);
  RUN_TEST(test_parser_deep_export_003);
  RUN_TEST(test_parser_deep_export_004);
  RUN_TEST(test_parser_deep_export_005);
  RUN_TEST(test_parser_deep_export_006);
  RUN_TEST(test_parser_deep_export_007);
  RUN_TEST(test_parser_deep_export_008);
  RUN_TEST(test_parser_deep_export_009);
  RUN_TEST(test_parser_deep_export_010);
  RUN_TEST(test_parser_deep_export_011);
  RUN_TEST(test_parser_deep_export_012);
  RUN_TEST(test_parser_deep_export_013);
  RUN_TEST(test_parser_deep_export_014);
  RUN_TEST(test_parser_deep_export_015);
  RUN_TEST(test_parser_deep_export_016);
  RUN_TEST(test_parser_deep_export_017);
  RUN_TEST(test_parser_deep_export_018);
  RUN_TEST(test_parser_deep_export_019);
  RUN_TEST(test_parser_deep_export_020);
  RUN_TEST(test_parser_deep_export_021);
  RUN_TEST(test_parser_deep_export_022);
  RUN_TEST(test_parser_deep_export_023);
  RUN_TEST(test_parser_deep_export_024);
  RUN_TEST(test_parser_deep_export_025);
  RUN_TEST(test_parser_deep_export_026);
  RUN_TEST(test_parser_deep_export_027);
  RUN_TEST(test_parser_deep_export_028);
  RUN_TEST(test_parser_deep_export_029);
  RUN_TEST(test_parser_deep_export_030);
  RUN_TEST(test_parser_deep_export_031);
  RUN_TEST(test_parser_deep_export_032);
  RUN_TEST(test_parser_deep_export_033);
  RUN_TEST(test_parser_deep_export_034);
  RUN_TEST(test_parser_deep_export_035);
  RUN_TEST(test_parser_deep_export_036);
  RUN_TEST(test_parser_deep_export_037);
  RUN_TEST(test_parser_deep_export_038);
  RUN_TEST(test_parser_deep_export_039);
  RUN_TEST(test_parser_deep_export_040);
  RUN_TEST(test_parser_deep_export_041);
  RUN_TEST(test_parser_deep_export_042);
  RUN_TEST(test_parser_deep_export_043);
  RUN_TEST(test_parser_deep_export_044);
  RUN_TEST(test_parser_deep_export_045);
  RUN_TEST(test_parser_deep_export_046);
  RUN_TEST(test_parser_deep_export_047);
  RUN_TEST(test_parser_deep_export_048);
  RUN_TEST(test_parser_deep_export_049);
  RUN_TEST(test_parser_deep_export_050);
  RUN_TEST(test_parser_deep_export_051);
  RUN_TEST(test_parser_deep_export_052);
  RUN_TEST(test_parser_deep_export_053);
  RUN_TEST(test_parser_deep_export_054);
  RUN_TEST(test_parser_deep_export_055);
  RUN_TEST(test_parser_deep_export_056);
  RUN_TEST(test_parser_deep_export_057);
  RUN_TEST(test_parser_deep_export_058);
  RUN_TEST(test_parser_deep_export_059);
  RUN_TEST(test_parser_deep_export_060);
  RUN_TEST(test_parser_deep_export_061);
  RUN_TEST(test_parser_deep_export_062);
  RUN_TEST(test_parser_deep_export_063);
  RUN_TEST(test_parser_deep_export_064);
  RUN_TEST(test_parser_deep_export_065);
  RUN_TEST(test_parser_deep_export_066);
  RUN_TEST(test_parser_deep_export_067);
  RUN_TEST(test_parser_deep_export_068);
  RUN_TEST(test_parser_deep_export_069);
  RUN_TEST(test_parser_deep_export_070);
  RUN_TEST(test_parser_deep_export_071);
  RUN_TEST(test_parser_deep_export_072);
  RUN_TEST(test_parser_deep_export_073);
  RUN_TEST(test_parser_deep_export_074);
  RUN_TEST(test_parser_deep_export_075);
  RUN_TEST(test_parser_deep_export_076);
  RUN_TEST(test_parser_deep_export_077);
  RUN_TEST(test_parser_deep_export_078);
  RUN_TEST(test_parser_deep_export_079);
  RUN_TEST(test_parser_deep_export_080);
  RUN_TEST(test_parser_deep_export_081);
  RUN_TEST(test_parser_deep_export_082);
  RUN_TEST(test_parser_deep_export_083);
  RUN_TEST(test_parser_deep_export_084);
  RUN_TEST(test_parser_deep_export_085);
  RUN_TEST(test_parser_deep_export_086);
  RUN_TEST(test_parser_deep_export_087);
  RUN_TEST(test_parser_deep_export_088);
  RUN_TEST(test_parser_deep_export_089);
  RUN_TEST(test_parser_deep_export_090);
  RUN_TEST(test_parser_deep_export_091);
  RUN_TEST(test_parser_deep_export_092);
  RUN_TEST(test_parser_deep_export_093);
  RUN_TEST(test_parser_deep_export_094);
  RUN_TEST(test_parser_deep_export_095);
  RUN_TEST(test_parser_deep_export_096);
  RUN_TEST(test_parser_deep_export_097);
  RUN_TEST(test_parser_deep_export_098);
  RUN_TEST(test_parser_deep_export_099);
}
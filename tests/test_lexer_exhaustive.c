#include "unity.h"
#include <stdio.h>
#include <string.h>
#include "protocolspack/proto.h"


void test_lexer_comment_000(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 0\nKEY_0=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_001(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 1\nKEY_1=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_002(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 2\nKEY_2=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_003(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 3\nKEY_3=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_004(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 4\nKEY_4=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_005(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 5\nKEY_5=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_006(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 6\nKEY_6=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_007(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 7\nKEY_7=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_008(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 8\nKEY_8=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_009(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 9\nKEY_9=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_010(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 10\nKEY_10=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_011(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 11\nKEY_11=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_012(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 12\nKEY_12=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_013(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 13\nKEY_13=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_014(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 14\nKEY_14=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_015(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 15\nKEY_15=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_016(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 16\nKEY_16=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_017(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 17\nKEY_17=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_018(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 18\nKEY_18=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_019(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 19\nKEY_19=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_020(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 20\nKEY_20=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_021(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 21\nKEY_21=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_022(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 22\nKEY_22=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_023(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 23\nKEY_23=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_024(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 24\nKEY_24=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_025(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 25\nKEY_25=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_026(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 26\nKEY_26=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_027(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 27\nKEY_27=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_028(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 28\nKEY_28=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_029(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 29\nKEY_29=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_030(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 30\nKEY_30=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_031(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 31\nKEY_31=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_032(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 32\nKEY_32=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_033(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 33\nKEY_33=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_034(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 34\nKEY_34=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_035(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 35\nKEY_35=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_036(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 36\nKEY_36=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_037(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 37\nKEY_37=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_038(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 38\nKEY_38=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_039(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 39\nKEY_39=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_040(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 40\nKEY_40=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_041(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 41\nKEY_41=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_042(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 42\nKEY_42=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_043(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 43\nKEY_43=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_044(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 44\nKEY_44=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_045(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 45\nKEY_45=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_046(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 46\nKEY_46=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_047(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 47\nKEY_47=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_048(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 48\nKEY_48=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_049(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 49\nKEY_49=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_050(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 50\nKEY_50=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_051(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 51\nKEY_51=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_052(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 52\nKEY_52=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_053(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 53\nKEY_53=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_054(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 54\nKEY_54=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_055(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 55\nKEY_55=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_056(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 56\nKEY_56=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_057(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 57\nKEY_57=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_058(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 58\nKEY_58=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_059(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 59\nKEY_59=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_060(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 60\nKEY_60=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_061(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 61\nKEY_61=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_062(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 62\nKEY_62=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_063(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 63\nKEY_63=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_064(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 64\nKEY_64=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_065(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 65\nKEY_65=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_066(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 66\nKEY_66=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_067(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 67\nKEY_67=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_068(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 68\nKEY_68=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_069(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 69\nKEY_69=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_070(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 70\nKEY_70=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_071(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 71\nKEY_71=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_072(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 72\nKEY_72=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_073(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 73\nKEY_73=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_074(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 74\nKEY_74=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_075(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 75\nKEY_75=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_076(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 76\nKEY_76=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_077(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 77\nKEY_77=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_078(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 78\nKEY_78=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_079(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 79\nKEY_79=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_080(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 80\nKEY_80=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_081(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 81\nKEY_81=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_082(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 82\nKEY_82=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_083(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 83\nKEY_83=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_084(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 84\nKEY_84=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_085(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 85\nKEY_85=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_086(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 86\nKEY_86=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_087(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 87\nKEY_87=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_088(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 88\nKEY_88=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_089(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 89\nKEY_89=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_090(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 90\nKEY_90=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_091(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 91\nKEY_91=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_092(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 92\nKEY_92=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_093(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 93\nKEY_93=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_094(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 94\nKEY_94=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_095(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 95\nKEY_95=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_096(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 96\nKEY_96=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_097(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 97\nKEY_97=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_098(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 98\nKEY_98=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_099(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 99\nKEY_99=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_100(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 100\nKEY_100=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_101(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 101\nKEY_101=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_102(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 102\nKEY_102=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_103(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 103\nKEY_103=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_104(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 104\nKEY_104=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_105(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 105\nKEY_105=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_106(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 106\nKEY_106=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_107(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 107\nKEY_107=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_108(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 108\nKEY_108=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_109(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 109\nKEY_109=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_110(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 110\nKEY_110=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_111(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 111\nKEY_111=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_112(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 112\nKEY_112=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_113(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 113\nKEY_113=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_114(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 114\nKEY_114=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_115(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 115\nKEY_115=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_116(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 116\nKEY_116=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_117(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 117\nKEY_117=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_118(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 118\nKEY_118=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_119(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 119\nKEY_119=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_120(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 120\nKEY_120=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_121(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 121\nKEY_121=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_122(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 122\nKEY_122=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_123(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 123\nKEY_123=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_124(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 124\nKEY_124=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_125(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 125\nKEY_125=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_126(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 126\nKEY_126=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_127(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 127\nKEY_127=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_128(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 128\nKEY_128=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_129(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 129\nKEY_129=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_130(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 130\nKEY_130=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_131(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 131\nKEY_131=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_132(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 132\nKEY_132=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_133(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 133\nKEY_133=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_134(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 134\nKEY_134=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_135(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 135\nKEY_135=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_136(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 136\nKEY_136=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_137(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 137\nKEY_137=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_138(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 138\nKEY_138=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_139(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 139\nKEY_139=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_140(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 140\nKEY_140=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_141(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 141\nKEY_141=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_142(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 142\nKEY_142=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_143(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 143\nKEY_143=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_144(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 144\nKEY_144=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_145(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 145\nKEY_145=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_146(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 146\nKEY_146=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_147(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 147\nKEY_147=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_148(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 148\nKEY_148=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_149(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 149\nKEY_149=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_150(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 150\nKEY_150=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_151(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 151\nKEY_151=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_152(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 152\nKEY_152=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_153(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 153\nKEY_153=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_154(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 154\nKEY_154=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_155(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 155\nKEY_155=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_156(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 156\nKEY_156=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_157(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 157\nKEY_157=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_158(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 158\nKEY_158=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}


void test_lexer_comment_159(void) {
  char src[128];
  snprintf(src, sizeof(src), "# comment 159\nKEY_159=val\n");
  proto_doc_t *doc = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(1, (int)proto_entry_count(doc));
  proto_doc_free(doc);
}

void run_lexer_exhaustive_tests(void) {
  RUN_TEST(test_lexer_comment_000);
  RUN_TEST(test_lexer_comment_001);
  RUN_TEST(test_lexer_comment_002);
  RUN_TEST(test_lexer_comment_003);
  RUN_TEST(test_lexer_comment_004);
  RUN_TEST(test_lexer_comment_005);
  RUN_TEST(test_lexer_comment_006);
  RUN_TEST(test_lexer_comment_007);
  RUN_TEST(test_lexer_comment_008);
  RUN_TEST(test_lexer_comment_009);
  RUN_TEST(test_lexer_comment_010);
  RUN_TEST(test_lexer_comment_011);
  RUN_TEST(test_lexer_comment_012);
  RUN_TEST(test_lexer_comment_013);
  RUN_TEST(test_lexer_comment_014);
  RUN_TEST(test_lexer_comment_015);
  RUN_TEST(test_lexer_comment_016);
  RUN_TEST(test_lexer_comment_017);
  RUN_TEST(test_lexer_comment_018);
  RUN_TEST(test_lexer_comment_019);
  RUN_TEST(test_lexer_comment_020);
  RUN_TEST(test_lexer_comment_021);
  RUN_TEST(test_lexer_comment_022);
  RUN_TEST(test_lexer_comment_023);
  RUN_TEST(test_lexer_comment_024);
  RUN_TEST(test_lexer_comment_025);
  RUN_TEST(test_lexer_comment_026);
  RUN_TEST(test_lexer_comment_027);
  RUN_TEST(test_lexer_comment_028);
  RUN_TEST(test_lexer_comment_029);
  RUN_TEST(test_lexer_comment_030);
  RUN_TEST(test_lexer_comment_031);
  RUN_TEST(test_lexer_comment_032);
  RUN_TEST(test_lexer_comment_033);
  RUN_TEST(test_lexer_comment_034);
  RUN_TEST(test_lexer_comment_035);
  RUN_TEST(test_lexer_comment_036);
  RUN_TEST(test_lexer_comment_037);
  RUN_TEST(test_lexer_comment_038);
  RUN_TEST(test_lexer_comment_039);
  RUN_TEST(test_lexer_comment_040);
  RUN_TEST(test_lexer_comment_041);
  RUN_TEST(test_lexer_comment_042);
  RUN_TEST(test_lexer_comment_043);
  RUN_TEST(test_lexer_comment_044);
  RUN_TEST(test_lexer_comment_045);
  RUN_TEST(test_lexer_comment_046);
  RUN_TEST(test_lexer_comment_047);
  RUN_TEST(test_lexer_comment_048);
  RUN_TEST(test_lexer_comment_049);
  RUN_TEST(test_lexer_comment_050);
  RUN_TEST(test_lexer_comment_051);
  RUN_TEST(test_lexer_comment_052);
  RUN_TEST(test_lexer_comment_053);
  RUN_TEST(test_lexer_comment_054);
  RUN_TEST(test_lexer_comment_055);
  RUN_TEST(test_lexer_comment_056);
  RUN_TEST(test_lexer_comment_057);
  RUN_TEST(test_lexer_comment_058);
  RUN_TEST(test_lexer_comment_059);
  RUN_TEST(test_lexer_comment_060);
  RUN_TEST(test_lexer_comment_061);
  RUN_TEST(test_lexer_comment_062);
  RUN_TEST(test_lexer_comment_063);
  RUN_TEST(test_lexer_comment_064);
  RUN_TEST(test_lexer_comment_065);
  RUN_TEST(test_lexer_comment_066);
  RUN_TEST(test_lexer_comment_067);
  RUN_TEST(test_lexer_comment_068);
  RUN_TEST(test_lexer_comment_069);
  RUN_TEST(test_lexer_comment_070);
  RUN_TEST(test_lexer_comment_071);
  RUN_TEST(test_lexer_comment_072);
  RUN_TEST(test_lexer_comment_073);
  RUN_TEST(test_lexer_comment_074);
  RUN_TEST(test_lexer_comment_075);
  RUN_TEST(test_lexer_comment_076);
  RUN_TEST(test_lexer_comment_077);
  RUN_TEST(test_lexer_comment_078);
  RUN_TEST(test_lexer_comment_079);
  RUN_TEST(test_lexer_comment_080);
  RUN_TEST(test_lexer_comment_081);
  RUN_TEST(test_lexer_comment_082);
  RUN_TEST(test_lexer_comment_083);
  RUN_TEST(test_lexer_comment_084);
  RUN_TEST(test_lexer_comment_085);
  RUN_TEST(test_lexer_comment_086);
  RUN_TEST(test_lexer_comment_087);
  RUN_TEST(test_lexer_comment_088);
  RUN_TEST(test_lexer_comment_089);
  RUN_TEST(test_lexer_comment_090);
  RUN_TEST(test_lexer_comment_091);
  RUN_TEST(test_lexer_comment_092);
  RUN_TEST(test_lexer_comment_093);
  RUN_TEST(test_lexer_comment_094);
  RUN_TEST(test_lexer_comment_095);
  RUN_TEST(test_lexer_comment_096);
  RUN_TEST(test_lexer_comment_097);
  RUN_TEST(test_lexer_comment_098);
  RUN_TEST(test_lexer_comment_099);
  RUN_TEST(test_lexer_comment_100);
  RUN_TEST(test_lexer_comment_101);
  RUN_TEST(test_lexer_comment_102);
  RUN_TEST(test_lexer_comment_103);
  RUN_TEST(test_lexer_comment_104);
  RUN_TEST(test_lexer_comment_105);
  RUN_TEST(test_lexer_comment_106);
  RUN_TEST(test_lexer_comment_107);
  RUN_TEST(test_lexer_comment_108);
  RUN_TEST(test_lexer_comment_109);
  RUN_TEST(test_lexer_comment_110);
  RUN_TEST(test_lexer_comment_111);
  RUN_TEST(test_lexer_comment_112);
  RUN_TEST(test_lexer_comment_113);
  RUN_TEST(test_lexer_comment_114);
  RUN_TEST(test_lexer_comment_115);
  RUN_TEST(test_lexer_comment_116);
  RUN_TEST(test_lexer_comment_117);
  RUN_TEST(test_lexer_comment_118);
  RUN_TEST(test_lexer_comment_119);
  RUN_TEST(test_lexer_comment_120);
  RUN_TEST(test_lexer_comment_121);
  RUN_TEST(test_lexer_comment_122);
  RUN_TEST(test_lexer_comment_123);
  RUN_TEST(test_lexer_comment_124);
  RUN_TEST(test_lexer_comment_125);
  RUN_TEST(test_lexer_comment_126);
  RUN_TEST(test_lexer_comment_127);
  RUN_TEST(test_lexer_comment_128);
  RUN_TEST(test_lexer_comment_129);
  RUN_TEST(test_lexer_comment_130);
  RUN_TEST(test_lexer_comment_131);
  RUN_TEST(test_lexer_comment_132);
  RUN_TEST(test_lexer_comment_133);
  RUN_TEST(test_lexer_comment_134);
  RUN_TEST(test_lexer_comment_135);
  RUN_TEST(test_lexer_comment_136);
  RUN_TEST(test_lexer_comment_137);
  RUN_TEST(test_lexer_comment_138);
  RUN_TEST(test_lexer_comment_139);
  RUN_TEST(test_lexer_comment_140);
  RUN_TEST(test_lexer_comment_141);
  RUN_TEST(test_lexer_comment_142);
  RUN_TEST(test_lexer_comment_143);
  RUN_TEST(test_lexer_comment_144);
  RUN_TEST(test_lexer_comment_145);
  RUN_TEST(test_lexer_comment_146);
  RUN_TEST(test_lexer_comment_147);
  RUN_TEST(test_lexer_comment_148);
  RUN_TEST(test_lexer_comment_149);
  RUN_TEST(test_lexer_comment_150);
  RUN_TEST(test_lexer_comment_151);
  RUN_TEST(test_lexer_comment_152);
  RUN_TEST(test_lexer_comment_153);
  RUN_TEST(test_lexer_comment_154);
  RUN_TEST(test_lexer_comment_155);
  RUN_TEST(test_lexer_comment_156);
  RUN_TEST(test_lexer_comment_157);
  RUN_TEST(test_lexer_comment_158);
  RUN_TEST(test_lexer_comment_159);
}
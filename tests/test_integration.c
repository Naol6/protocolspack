#include "unity.h"
#include <stdlib.h>
#include <string.h>
#include "protocolspack/proto.h"


void test_integration_roundtrip_000(void) {
  const char *src =
      "PORT=8080\n"
      "SECRET_KEY=redis\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("8080", proto_get(doc2, "PORT"));
  TEST_ASSERT_EQUAL_STRING("redis", proto_get(doc2, "SECRET_KEY"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_001(void) {
  const char *src =
      "HOST=localhost\n"
      "LOG_LEVEL=abc123\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("localhost", proto_get(doc2, "HOST"));
  TEST_ASSERT_EQUAL_STRING("abc123", proto_get(doc2, "LOG_LEVEL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_002(void) {
  const char *src =
      "DATABASE_URL=postgres\n"
      "DEBUG=true\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("postgres", proto_get(doc2, "DATABASE_URL"));
  TEST_ASSERT_EQUAL_STRING("true", proto_get(doc2, "DEBUG"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_003(void) {
  const char *src =
      "REDIS_URL=redis\n"
      "NODE_ENV=false\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("redis", proto_get(doc2, "REDIS_URL"));
  TEST_ASSERT_EQUAL_STRING("false", proto_get(doc2, "NODE_ENV"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_004(void) {
  const char *src =
      "API_KEY=abc123\n"
      "APP_NAME=production\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("abc123", proto_get(doc2, "API_KEY"));
  TEST_ASSERT_EQUAL_STRING("production", proto_get(doc2, "APP_NAME"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_005(void) {
  const char *src =
      "SECRET_KEY=true\n"
      "WORKERS=development\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("true", proto_get(doc2, "SECRET_KEY"));
  TEST_ASSERT_EQUAL_STRING("development", proto_get(doc2, "WORKERS"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_006(void) {
  const char *src =
      "LOG_LEVEL=false\n"
      "TIMEOUT=30\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("false", proto_get(doc2, "LOG_LEVEL"));
  TEST_ASSERT_EQUAL_STRING("30", proto_get(doc2, "TIMEOUT"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_007(void) {
  const char *src =
      "DEBUG=production\n"
      "POOL_SIZE=3600\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("production", proto_get(doc2, "DEBUG"));
  TEST_ASSERT_EQUAL_STRING("3600", proto_get(doc2, "POOL_SIZE"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_008(void) {
  const char *src =
      "NODE_ENV=development\n"
      "CACHE_TTL=plain\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("development", proto_get(doc2, "NODE_ENV"));
  TEST_ASSERT_EQUAL_STRING("plain", proto_get(doc2, "CACHE_TTL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_009(void) {
  const char *src =
      "APP_NAME=30\n"
      "JWT_SECRET=path\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("30", proto_get(doc2, "APP_NAME"));
  TEST_ASSERT_EQUAL_STRING("path", proto_get(doc2, "JWT_SECRET"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_010(void) {
  const char *src =
      "WORKERS=3600\n"
      "SMTP_HOST=user\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("3600", proto_get(doc2, "WORKERS"));
  TEST_ASSERT_EQUAL_STRING("user", proto_get(doc2, "SMTP_HOST"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_011(void) {
  const char *src =
      "TIMEOUT=plain\n"
      "SMTP_PORT=v1\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("plain", proto_get(doc2, "TIMEOUT"));
  TEST_ASSERT_EQUAL_STRING("v1", proto_get(doc2, "SMTP_PORT"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_012(void) {
  const char *src =
      "POOL_SIZE=path\n"
      "AWS_REGION=0.0.0.0\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("path", proto_get(doc2, "POOL_SIZE"));
  TEST_ASSERT_EQUAL_STRING("0.0.0.0", proto_get(doc2, "AWS_REGION"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_013(void) {
  const char *src =
      "CACHE_TTL=user\n"
      "S3_BUCKET=warn\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("user", proto_get(doc2, "CACHE_TTL"));
  TEST_ASSERT_EQUAL_STRING("warn", proto_get(doc2, "S3_BUCKET"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_014(void) {
  const char *src =
      "JWT_SECRET=v1\n"
      "CDN_URL=info\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("v1", proto_get(doc2, "JWT_SECRET"));
  TEST_ASSERT_EQUAL_STRING("info", proto_get(doc2, "CDN_URL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_015(void) {
  const char *src =
      "SMTP_HOST=0.0.0.0\n"
      "FEATURE_FLAG=debug\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("0.0.0.0", proto_get(doc2, "SMTP_HOST"));
  TEST_ASSERT_EQUAL_STRING("debug", proto_get(doc2, "FEATURE_FLAG"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_016(void) {
  const char *src =
      "SMTP_PORT=warn\n"
      "MAX_UPLOAD=enabled\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("warn", proto_get(doc2, "SMTP_PORT"));
  TEST_ASSERT_EQUAL_STRING("enabled", proto_get(doc2, "MAX_UPLOAD"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_017(void) {
  const char *src =
      "AWS_REGION=info\n"
      "SESSION_TTL=disabled\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("info", proto_get(doc2, "AWS_REGION"));
  TEST_ASSERT_EQUAL_STRING("disabled", proto_get(doc2, "SESSION_TTL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_018(void) {
  const char *src =
      "S3_BUCKET=debug\n"
      "CORS_ORIGIN=8080\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("debug", proto_get(doc2, "S3_BUCKET"));
  TEST_ASSERT_EQUAL_STRING("8080", proto_get(doc2, "CORS_ORIGIN"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_019(void) {
  const char *src =
      "CDN_URL=enabled\n"
      "RATE_LIMIT=localhost\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("enabled", proto_get(doc2, "CDN_URL"));
  TEST_ASSERT_EQUAL_STRING("localhost", proto_get(doc2, "RATE_LIMIT"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_020(void) {
  const char *src =
      "FEATURE_FLAG=disabled\n"
      "BACKUP_PATH=postgres\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("disabled", proto_get(doc2, "FEATURE_FLAG"));
  TEST_ASSERT_EQUAL_STRING("postgres", proto_get(doc2, "BACKUP_PATH"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_021(void) {
  const char *src =
      "MAX_UPLOAD=8080\n"
      "SSL_MODE=redis\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("8080", proto_get(doc2, "MAX_UPLOAD"));
  TEST_ASSERT_EQUAL_STRING("redis", proto_get(doc2, "SSL_MODE"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_022(void) {
  const char *src =
      "SESSION_TTL=localhost\n"
      "METRICS_PORT=abc123\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("localhost", proto_get(doc2, "SESSION_TTL"));
  TEST_ASSERT_EQUAL_STRING("abc123", proto_get(doc2, "METRICS_PORT"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_023(void) {
  const char *src =
      "CORS_ORIGIN=postgres\n"
      "HEALTH_PATH=true\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("postgres", proto_get(doc2, "CORS_ORIGIN"));
  TEST_ASSERT_EQUAL_STRING("true", proto_get(doc2, "HEALTH_PATH"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_024(void) {
  const char *src =
      "RATE_LIMIT=redis\n"
      "BUILD_VERSION=false\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("redis", proto_get(doc2, "RATE_LIMIT"));
  TEST_ASSERT_EQUAL_STRING("false", proto_get(doc2, "BUILD_VERSION"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_025(void) {
  const char *src =
      "BACKUP_PATH=abc123\n"
      "PORT=production\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("abc123", proto_get(doc2, "BACKUP_PATH"));
  TEST_ASSERT_EQUAL_STRING("production", proto_get(doc2, "PORT"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_026(void) {
  const char *src =
      "SSL_MODE=true\n"
      "HOST=development\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("true", proto_get(doc2, "SSL_MODE"));
  TEST_ASSERT_EQUAL_STRING("development", proto_get(doc2, "HOST"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_027(void) {
  const char *src =
      "METRICS_PORT=false\n"
      "DATABASE_URL=30\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("false", proto_get(doc2, "METRICS_PORT"));
  TEST_ASSERT_EQUAL_STRING("30", proto_get(doc2, "DATABASE_URL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_028(void) {
  const char *src =
      "HEALTH_PATH=production\n"
      "REDIS_URL=3600\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("production", proto_get(doc2, "HEALTH_PATH"));
  TEST_ASSERT_EQUAL_STRING("3600", proto_get(doc2, "REDIS_URL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_029(void) {
  const char *src =
      "BUILD_VERSION=development\n"
      "API_KEY=plain\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("development", proto_get(doc2, "BUILD_VERSION"));
  TEST_ASSERT_EQUAL_STRING("plain", proto_get(doc2, "API_KEY"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_030(void) {
  const char *src =
      "PORT=30\n"
      "SECRET_KEY=path\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("30", proto_get(doc2, "PORT"));
  TEST_ASSERT_EQUAL_STRING("path", proto_get(doc2, "SECRET_KEY"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_031(void) {
  const char *src =
      "HOST=3600\n"
      "LOG_LEVEL=user\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("3600", proto_get(doc2, "HOST"));
  TEST_ASSERT_EQUAL_STRING("user", proto_get(doc2, "LOG_LEVEL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_032(void) {
  const char *src =
      "DATABASE_URL=plain\n"
      "DEBUG=v1\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("plain", proto_get(doc2, "DATABASE_URL"));
  TEST_ASSERT_EQUAL_STRING("v1", proto_get(doc2, "DEBUG"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_033(void) {
  const char *src =
      "REDIS_URL=path\n"
      "NODE_ENV=0.0.0.0\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("path", proto_get(doc2, "REDIS_URL"));
  TEST_ASSERT_EQUAL_STRING("0.0.0.0", proto_get(doc2, "NODE_ENV"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_034(void) {
  const char *src =
      "API_KEY=user\n"
      "APP_NAME=warn\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("user", proto_get(doc2, "API_KEY"));
  TEST_ASSERT_EQUAL_STRING("warn", proto_get(doc2, "APP_NAME"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_035(void) {
  const char *src =
      "SECRET_KEY=v1\n"
      "WORKERS=info\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("v1", proto_get(doc2, "SECRET_KEY"));
  TEST_ASSERT_EQUAL_STRING("info", proto_get(doc2, "WORKERS"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_036(void) {
  const char *src =
      "LOG_LEVEL=0.0.0.0\n"
      "TIMEOUT=debug\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("0.0.0.0", proto_get(doc2, "LOG_LEVEL"));
  TEST_ASSERT_EQUAL_STRING("debug", proto_get(doc2, "TIMEOUT"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_037(void) {
  const char *src =
      "DEBUG=warn\n"
      "POOL_SIZE=enabled\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("warn", proto_get(doc2, "DEBUG"));
  TEST_ASSERT_EQUAL_STRING("enabled", proto_get(doc2, "POOL_SIZE"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_038(void) {
  const char *src =
      "NODE_ENV=info\n"
      "CACHE_TTL=disabled\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("info", proto_get(doc2, "NODE_ENV"));
  TEST_ASSERT_EQUAL_STRING("disabled", proto_get(doc2, "CACHE_TTL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_039(void) {
  const char *src =
      "APP_NAME=debug\n"
      "JWT_SECRET=8080\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("debug", proto_get(doc2, "APP_NAME"));
  TEST_ASSERT_EQUAL_STRING("8080", proto_get(doc2, "JWT_SECRET"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_040(void) {
  const char *src =
      "WORKERS=enabled\n"
      "SMTP_HOST=localhost\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("enabled", proto_get(doc2, "WORKERS"));
  TEST_ASSERT_EQUAL_STRING("localhost", proto_get(doc2, "SMTP_HOST"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_041(void) {
  const char *src =
      "TIMEOUT=disabled\n"
      "SMTP_PORT=postgres\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("disabled", proto_get(doc2, "TIMEOUT"));
  TEST_ASSERT_EQUAL_STRING("postgres", proto_get(doc2, "SMTP_PORT"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_042(void) {
  const char *src =
      "POOL_SIZE=8080\n"
      "AWS_REGION=redis\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("8080", proto_get(doc2, "POOL_SIZE"));
  TEST_ASSERT_EQUAL_STRING("redis", proto_get(doc2, "AWS_REGION"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_043(void) {
  const char *src =
      "CACHE_TTL=localhost\n"
      "S3_BUCKET=abc123\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("localhost", proto_get(doc2, "CACHE_TTL"));
  TEST_ASSERT_EQUAL_STRING("abc123", proto_get(doc2, "S3_BUCKET"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_044(void) {
  const char *src =
      "JWT_SECRET=postgres\n"
      "CDN_URL=true\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("postgres", proto_get(doc2, "JWT_SECRET"));
  TEST_ASSERT_EQUAL_STRING("true", proto_get(doc2, "CDN_URL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_045(void) {
  const char *src =
      "SMTP_HOST=redis\n"
      "FEATURE_FLAG=false\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("redis", proto_get(doc2, "SMTP_HOST"));
  TEST_ASSERT_EQUAL_STRING("false", proto_get(doc2, "FEATURE_FLAG"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_046(void) {
  const char *src =
      "SMTP_PORT=abc123\n"
      "MAX_UPLOAD=production\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("abc123", proto_get(doc2, "SMTP_PORT"));
  TEST_ASSERT_EQUAL_STRING("production", proto_get(doc2, "MAX_UPLOAD"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_047(void) {
  const char *src =
      "AWS_REGION=true\n"
      "SESSION_TTL=development\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("true", proto_get(doc2, "AWS_REGION"));
  TEST_ASSERT_EQUAL_STRING("development", proto_get(doc2, "SESSION_TTL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_048(void) {
  const char *src =
      "S3_BUCKET=false\n"
      "CORS_ORIGIN=30\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("false", proto_get(doc2, "S3_BUCKET"));
  TEST_ASSERT_EQUAL_STRING("30", proto_get(doc2, "CORS_ORIGIN"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_049(void) {
  const char *src =
      "CDN_URL=production\n"
      "RATE_LIMIT=3600\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("production", proto_get(doc2, "CDN_URL"));
  TEST_ASSERT_EQUAL_STRING("3600", proto_get(doc2, "RATE_LIMIT"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_050(void) {
  const char *src =
      "FEATURE_FLAG=development\n"
      "BACKUP_PATH=plain\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("development", proto_get(doc2, "FEATURE_FLAG"));
  TEST_ASSERT_EQUAL_STRING("plain", proto_get(doc2, "BACKUP_PATH"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_051(void) {
  const char *src =
      "MAX_UPLOAD=30\n"
      "SSL_MODE=path\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("30", proto_get(doc2, "MAX_UPLOAD"));
  TEST_ASSERT_EQUAL_STRING("path", proto_get(doc2, "SSL_MODE"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_052(void) {
  const char *src =
      "SESSION_TTL=3600\n"
      "METRICS_PORT=user\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("3600", proto_get(doc2, "SESSION_TTL"));
  TEST_ASSERT_EQUAL_STRING("user", proto_get(doc2, "METRICS_PORT"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_053(void) {
  const char *src =
      "CORS_ORIGIN=plain\n"
      "HEALTH_PATH=v1\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("plain", proto_get(doc2, "CORS_ORIGIN"));
  TEST_ASSERT_EQUAL_STRING("v1", proto_get(doc2, "HEALTH_PATH"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_054(void) {
  const char *src =
      "RATE_LIMIT=path\n"
      "BUILD_VERSION=0.0.0.0\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("path", proto_get(doc2, "RATE_LIMIT"));
  TEST_ASSERT_EQUAL_STRING("0.0.0.0", proto_get(doc2, "BUILD_VERSION"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_055(void) {
  const char *src =
      "BACKUP_PATH=user\n"
      "PORT=warn\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("user", proto_get(doc2, "BACKUP_PATH"));
  TEST_ASSERT_EQUAL_STRING("warn", proto_get(doc2, "PORT"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_056(void) {
  const char *src =
      "SSL_MODE=v1\n"
      "HOST=info\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("v1", proto_get(doc2, "SSL_MODE"));
  TEST_ASSERT_EQUAL_STRING("info", proto_get(doc2, "HOST"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_057(void) {
  const char *src =
      "METRICS_PORT=0.0.0.0\n"
      "DATABASE_URL=debug\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("0.0.0.0", proto_get(doc2, "METRICS_PORT"));
  TEST_ASSERT_EQUAL_STRING("debug", proto_get(doc2, "DATABASE_URL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_058(void) {
  const char *src =
      "HEALTH_PATH=warn\n"
      "REDIS_URL=enabled\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("warn", proto_get(doc2, "HEALTH_PATH"));
  TEST_ASSERT_EQUAL_STRING("enabled", proto_get(doc2, "REDIS_URL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_059(void) {
  const char *src =
      "BUILD_VERSION=info\n"
      "API_KEY=disabled\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("info", proto_get(doc2, "BUILD_VERSION"));
  TEST_ASSERT_EQUAL_STRING("disabled", proto_get(doc2, "API_KEY"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_060(void) {
  const char *src =
      "PORT=debug\n"
      "SECRET_KEY=8080\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("debug", proto_get(doc2, "PORT"));
  TEST_ASSERT_EQUAL_STRING("8080", proto_get(doc2, "SECRET_KEY"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_061(void) {
  const char *src =
      "HOST=enabled\n"
      "LOG_LEVEL=localhost\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("enabled", proto_get(doc2, "HOST"));
  TEST_ASSERT_EQUAL_STRING("localhost", proto_get(doc2, "LOG_LEVEL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_062(void) {
  const char *src =
      "DATABASE_URL=disabled\n"
      "DEBUG=postgres\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("disabled", proto_get(doc2, "DATABASE_URL"));
  TEST_ASSERT_EQUAL_STRING("postgres", proto_get(doc2, "DEBUG"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_063(void) {
  const char *src =
      "REDIS_URL=8080\n"
      "NODE_ENV=redis\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("8080", proto_get(doc2, "REDIS_URL"));
  TEST_ASSERT_EQUAL_STRING("redis", proto_get(doc2, "NODE_ENV"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_064(void) {
  const char *src =
      "API_KEY=localhost\n"
      "APP_NAME=abc123\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("localhost", proto_get(doc2, "API_KEY"));
  TEST_ASSERT_EQUAL_STRING("abc123", proto_get(doc2, "APP_NAME"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_065(void) {
  const char *src =
      "SECRET_KEY=postgres\n"
      "WORKERS=true\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("postgres", proto_get(doc2, "SECRET_KEY"));
  TEST_ASSERT_EQUAL_STRING("true", proto_get(doc2, "WORKERS"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_066(void) {
  const char *src =
      "LOG_LEVEL=redis\n"
      "TIMEOUT=false\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("redis", proto_get(doc2, "LOG_LEVEL"));
  TEST_ASSERT_EQUAL_STRING("false", proto_get(doc2, "TIMEOUT"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_067(void) {
  const char *src =
      "DEBUG=abc123\n"
      "POOL_SIZE=production\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("abc123", proto_get(doc2, "DEBUG"));
  TEST_ASSERT_EQUAL_STRING("production", proto_get(doc2, "POOL_SIZE"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_068(void) {
  const char *src =
      "NODE_ENV=true\n"
      "CACHE_TTL=development\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("true", proto_get(doc2, "NODE_ENV"));
  TEST_ASSERT_EQUAL_STRING("development", proto_get(doc2, "CACHE_TTL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_069(void) {
  const char *src =
      "APP_NAME=false\n"
      "JWT_SECRET=30\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("false", proto_get(doc2, "APP_NAME"));
  TEST_ASSERT_EQUAL_STRING("30", proto_get(doc2, "JWT_SECRET"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_070(void) {
  const char *src =
      "WORKERS=production\n"
      "SMTP_HOST=3600\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("production", proto_get(doc2, "WORKERS"));
  TEST_ASSERT_EQUAL_STRING("3600", proto_get(doc2, "SMTP_HOST"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_071(void) {
  const char *src =
      "TIMEOUT=development\n"
      "SMTP_PORT=plain\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("development", proto_get(doc2, "TIMEOUT"));
  TEST_ASSERT_EQUAL_STRING("plain", proto_get(doc2, "SMTP_PORT"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_072(void) {
  const char *src =
      "POOL_SIZE=30\n"
      "AWS_REGION=path\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("30", proto_get(doc2, "POOL_SIZE"));
  TEST_ASSERT_EQUAL_STRING("path", proto_get(doc2, "AWS_REGION"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_073(void) {
  const char *src =
      "CACHE_TTL=3600\n"
      "S3_BUCKET=user\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("3600", proto_get(doc2, "CACHE_TTL"));
  TEST_ASSERT_EQUAL_STRING("user", proto_get(doc2, "S3_BUCKET"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_074(void) {
  const char *src =
      "JWT_SECRET=plain\n"
      "CDN_URL=v1\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("plain", proto_get(doc2, "JWT_SECRET"));
  TEST_ASSERT_EQUAL_STRING("v1", proto_get(doc2, "CDN_URL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_075(void) {
  const char *src =
      "SMTP_HOST=path\n"
      "FEATURE_FLAG=0.0.0.0\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("path", proto_get(doc2, "SMTP_HOST"));
  TEST_ASSERT_EQUAL_STRING("0.0.0.0", proto_get(doc2, "FEATURE_FLAG"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_076(void) {
  const char *src =
      "SMTP_PORT=user\n"
      "MAX_UPLOAD=warn\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("user", proto_get(doc2, "SMTP_PORT"));
  TEST_ASSERT_EQUAL_STRING("warn", proto_get(doc2, "MAX_UPLOAD"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_077(void) {
  const char *src =
      "AWS_REGION=v1\n"
      "SESSION_TTL=info\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("v1", proto_get(doc2, "AWS_REGION"));
  TEST_ASSERT_EQUAL_STRING("info", proto_get(doc2, "SESSION_TTL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_078(void) {
  const char *src =
      "S3_BUCKET=0.0.0.0\n"
      "CORS_ORIGIN=debug\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("0.0.0.0", proto_get(doc2, "S3_BUCKET"));
  TEST_ASSERT_EQUAL_STRING("debug", proto_get(doc2, "CORS_ORIGIN"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_079(void) {
  const char *src =
      "CDN_URL=warn\n"
      "RATE_LIMIT=enabled\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("warn", proto_get(doc2, "CDN_URL"));
  TEST_ASSERT_EQUAL_STRING("enabled", proto_get(doc2, "RATE_LIMIT"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_080(void) {
  const char *src =
      "FEATURE_FLAG=info\n"
      "BACKUP_PATH=disabled\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("info", proto_get(doc2, "FEATURE_FLAG"));
  TEST_ASSERT_EQUAL_STRING("disabled", proto_get(doc2, "BACKUP_PATH"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_081(void) {
  const char *src =
      "MAX_UPLOAD=debug\n"
      "SSL_MODE=8080\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("debug", proto_get(doc2, "MAX_UPLOAD"));
  TEST_ASSERT_EQUAL_STRING("8080", proto_get(doc2, "SSL_MODE"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_082(void) {
  const char *src =
      "SESSION_TTL=enabled\n"
      "METRICS_PORT=localhost\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("enabled", proto_get(doc2, "SESSION_TTL"));
  TEST_ASSERT_EQUAL_STRING("localhost", proto_get(doc2, "METRICS_PORT"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_083(void) {
  const char *src =
      "CORS_ORIGIN=disabled\n"
      "HEALTH_PATH=postgres\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("disabled", proto_get(doc2, "CORS_ORIGIN"));
  TEST_ASSERT_EQUAL_STRING("postgres", proto_get(doc2, "HEALTH_PATH"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_084(void) {
  const char *src =
      "RATE_LIMIT=8080\n"
      "BUILD_VERSION=redis\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("8080", proto_get(doc2, "RATE_LIMIT"));
  TEST_ASSERT_EQUAL_STRING("redis", proto_get(doc2, "BUILD_VERSION"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_085(void) {
  const char *src =
      "BACKUP_PATH=localhost\n"
      "PORT=abc123\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("localhost", proto_get(doc2, "BACKUP_PATH"));
  TEST_ASSERT_EQUAL_STRING("abc123", proto_get(doc2, "PORT"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_086(void) {
  const char *src =
      "SSL_MODE=postgres\n"
      "HOST=true\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("postgres", proto_get(doc2, "SSL_MODE"));
  TEST_ASSERT_EQUAL_STRING("true", proto_get(doc2, "HOST"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_087(void) {
  const char *src =
      "METRICS_PORT=redis\n"
      "DATABASE_URL=false\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("redis", proto_get(doc2, "METRICS_PORT"));
  TEST_ASSERT_EQUAL_STRING("false", proto_get(doc2, "DATABASE_URL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_088(void) {
  const char *src =
      "HEALTH_PATH=abc123\n"
      "REDIS_URL=production\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("abc123", proto_get(doc2, "HEALTH_PATH"));
  TEST_ASSERT_EQUAL_STRING("production", proto_get(doc2, "REDIS_URL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_089(void) {
  const char *src =
      "BUILD_VERSION=true\n"
      "API_KEY=development\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("true", proto_get(doc2, "BUILD_VERSION"));
  TEST_ASSERT_EQUAL_STRING("development", proto_get(doc2, "API_KEY"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_090(void) {
  const char *src =
      "PORT=false\n"
      "SECRET_KEY=30\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("false", proto_get(doc2, "PORT"));
  TEST_ASSERT_EQUAL_STRING("30", proto_get(doc2, "SECRET_KEY"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_091(void) {
  const char *src =
      "HOST=production\n"
      "LOG_LEVEL=3600\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("production", proto_get(doc2, "HOST"));
  TEST_ASSERT_EQUAL_STRING("3600", proto_get(doc2, "LOG_LEVEL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_092(void) {
  const char *src =
      "DATABASE_URL=development\n"
      "DEBUG=plain\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("development", proto_get(doc2, "DATABASE_URL"));
  TEST_ASSERT_EQUAL_STRING("plain", proto_get(doc2, "DEBUG"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_093(void) {
  const char *src =
      "REDIS_URL=30\n"
      "NODE_ENV=path\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("30", proto_get(doc2, "REDIS_URL"));
  TEST_ASSERT_EQUAL_STRING("path", proto_get(doc2, "NODE_ENV"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_094(void) {
  const char *src =
      "API_KEY=3600\n"
      "APP_NAME=user\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("3600", proto_get(doc2, "API_KEY"));
  TEST_ASSERT_EQUAL_STRING("user", proto_get(doc2, "APP_NAME"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_095(void) {
  const char *src =
      "SECRET_KEY=plain\n"
      "WORKERS=v1\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("plain", proto_get(doc2, "SECRET_KEY"));
  TEST_ASSERT_EQUAL_STRING("v1", proto_get(doc2, "WORKERS"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_096(void) {
  const char *src =
      "LOG_LEVEL=path\n"
      "TIMEOUT=0.0.0.0\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("path", proto_get(doc2, "LOG_LEVEL"));
  TEST_ASSERT_EQUAL_STRING("0.0.0.0", proto_get(doc2, "TIMEOUT"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_097(void) {
  const char *src =
      "DEBUG=user\n"
      "POOL_SIZE=warn\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("user", proto_get(doc2, "DEBUG"));
  TEST_ASSERT_EQUAL_STRING("warn", proto_get(doc2, "POOL_SIZE"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_098(void) {
  const char *src =
      "NODE_ENV=v1\n"
      "CACHE_TTL=info\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("v1", proto_get(doc2, "NODE_ENV"));
  TEST_ASSERT_EQUAL_STRING("info", proto_get(doc2, "CACHE_TTL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_099(void) {
  const char *src =
      "APP_NAME=0.0.0.0\n"
      "JWT_SECRET=debug\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("0.0.0.0", proto_get(doc2, "APP_NAME"));
  TEST_ASSERT_EQUAL_STRING("debug", proto_get(doc2, "JWT_SECRET"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_100(void) {
  const char *src =
      "WORKERS=warn\n"
      "SMTP_HOST=enabled\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("warn", proto_get(doc2, "WORKERS"));
  TEST_ASSERT_EQUAL_STRING("enabled", proto_get(doc2, "SMTP_HOST"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_101(void) {
  const char *src =
      "TIMEOUT=info\n"
      "SMTP_PORT=disabled\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("info", proto_get(doc2, "TIMEOUT"));
  TEST_ASSERT_EQUAL_STRING("disabled", proto_get(doc2, "SMTP_PORT"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_102(void) {
  const char *src =
      "POOL_SIZE=debug\n"
      "AWS_REGION=8080\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("debug", proto_get(doc2, "POOL_SIZE"));
  TEST_ASSERT_EQUAL_STRING("8080", proto_get(doc2, "AWS_REGION"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_103(void) {
  const char *src =
      "CACHE_TTL=enabled\n"
      "S3_BUCKET=localhost\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("enabled", proto_get(doc2, "CACHE_TTL"));
  TEST_ASSERT_EQUAL_STRING("localhost", proto_get(doc2, "S3_BUCKET"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_104(void) {
  const char *src =
      "JWT_SECRET=disabled\n"
      "CDN_URL=postgres\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("disabled", proto_get(doc2, "JWT_SECRET"));
  TEST_ASSERT_EQUAL_STRING("postgres", proto_get(doc2, "CDN_URL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_105(void) {
  const char *src =
      "SMTP_HOST=8080\n"
      "FEATURE_FLAG=redis\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("8080", proto_get(doc2, "SMTP_HOST"));
  TEST_ASSERT_EQUAL_STRING("redis", proto_get(doc2, "FEATURE_FLAG"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_106(void) {
  const char *src =
      "SMTP_PORT=localhost\n"
      "MAX_UPLOAD=abc123\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("localhost", proto_get(doc2, "SMTP_PORT"));
  TEST_ASSERT_EQUAL_STRING("abc123", proto_get(doc2, "MAX_UPLOAD"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_107(void) {
  const char *src =
      "AWS_REGION=postgres\n"
      "SESSION_TTL=true\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("postgres", proto_get(doc2, "AWS_REGION"));
  TEST_ASSERT_EQUAL_STRING("true", proto_get(doc2, "SESSION_TTL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_108(void) {
  const char *src =
      "S3_BUCKET=redis\n"
      "CORS_ORIGIN=false\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("redis", proto_get(doc2, "S3_BUCKET"));
  TEST_ASSERT_EQUAL_STRING("false", proto_get(doc2, "CORS_ORIGIN"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_109(void) {
  const char *src =
      "CDN_URL=abc123\n"
      "RATE_LIMIT=production\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("abc123", proto_get(doc2, "CDN_URL"));
  TEST_ASSERT_EQUAL_STRING("production", proto_get(doc2, "RATE_LIMIT"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_110(void) {
  const char *src =
      "FEATURE_FLAG=true\n"
      "BACKUP_PATH=development\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("true", proto_get(doc2, "FEATURE_FLAG"));
  TEST_ASSERT_EQUAL_STRING("development", proto_get(doc2, "BACKUP_PATH"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_111(void) {
  const char *src =
      "MAX_UPLOAD=false\n"
      "SSL_MODE=30\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("false", proto_get(doc2, "MAX_UPLOAD"));
  TEST_ASSERT_EQUAL_STRING("30", proto_get(doc2, "SSL_MODE"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_112(void) {
  const char *src =
      "SESSION_TTL=production\n"
      "METRICS_PORT=3600\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("production", proto_get(doc2, "SESSION_TTL"));
  TEST_ASSERT_EQUAL_STRING("3600", proto_get(doc2, "METRICS_PORT"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_113(void) {
  const char *src =
      "CORS_ORIGIN=development\n"
      "HEALTH_PATH=plain\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("development", proto_get(doc2, "CORS_ORIGIN"));
  TEST_ASSERT_EQUAL_STRING("plain", proto_get(doc2, "HEALTH_PATH"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_114(void) {
  const char *src =
      "RATE_LIMIT=30\n"
      "BUILD_VERSION=path\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("30", proto_get(doc2, "RATE_LIMIT"));
  TEST_ASSERT_EQUAL_STRING("path", proto_get(doc2, "BUILD_VERSION"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_115(void) {
  const char *src =
      "BACKUP_PATH=3600\n"
      "PORT=user\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("3600", proto_get(doc2, "BACKUP_PATH"));
  TEST_ASSERT_EQUAL_STRING("user", proto_get(doc2, "PORT"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_116(void) {
  const char *src =
      "SSL_MODE=plain\n"
      "HOST=v1\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("plain", proto_get(doc2, "SSL_MODE"));
  TEST_ASSERT_EQUAL_STRING("v1", proto_get(doc2, "HOST"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_117(void) {
  const char *src =
      "METRICS_PORT=path\n"
      "DATABASE_URL=0.0.0.0\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("path", proto_get(doc2, "METRICS_PORT"));
  TEST_ASSERT_EQUAL_STRING("0.0.0.0", proto_get(doc2, "DATABASE_URL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_118(void) {
  const char *src =
      "HEALTH_PATH=user\n"
      "REDIS_URL=warn\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("user", proto_get(doc2, "HEALTH_PATH"));
  TEST_ASSERT_EQUAL_STRING("warn", proto_get(doc2, "REDIS_URL"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}


void test_integration_roundtrip_119(void) {
  const char *src =
      "BUILD_VERSION=v1\n"
      "API_KEY=info\n";
  proto_doc_t *doc = NULL;
  char *out = NULL;
  size_t out_len = 0;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(src, strlen(src), NULL, &doc, NULL));
  TEST_ASSERT_EQUAL_INT(0, proto_serialize(doc, &out, &out_len));
  proto_doc_t *doc2 = NULL;
  TEST_ASSERT_EQUAL_INT(0, proto_parse_memory(out, out_len, NULL, &doc2, NULL));
  TEST_ASSERT_EQUAL_STRING("v1", proto_get(doc2, "BUILD_VERSION"));
  TEST_ASSERT_EQUAL_STRING("info", proto_get(doc2, "API_KEY"));
  free(out);
  proto_doc_free(doc);
  proto_doc_free(doc2);
}

void run_integration_tests(void) {
  RUN_TEST(test_integration_roundtrip_000);
  RUN_TEST(test_integration_roundtrip_001);
  RUN_TEST(test_integration_roundtrip_002);
  RUN_TEST(test_integration_roundtrip_003);
  RUN_TEST(test_integration_roundtrip_004);
  RUN_TEST(test_integration_roundtrip_005);
  RUN_TEST(test_integration_roundtrip_006);
  RUN_TEST(test_integration_roundtrip_007);
  RUN_TEST(test_integration_roundtrip_008);
  RUN_TEST(test_integration_roundtrip_009);
  RUN_TEST(test_integration_roundtrip_010);
  RUN_TEST(test_integration_roundtrip_011);
  RUN_TEST(test_integration_roundtrip_012);
  RUN_TEST(test_integration_roundtrip_013);
  RUN_TEST(test_integration_roundtrip_014);
  RUN_TEST(test_integration_roundtrip_015);
  RUN_TEST(test_integration_roundtrip_016);
  RUN_TEST(test_integration_roundtrip_017);
  RUN_TEST(test_integration_roundtrip_018);
  RUN_TEST(test_integration_roundtrip_019);
  RUN_TEST(test_integration_roundtrip_020);
  RUN_TEST(test_integration_roundtrip_021);
  RUN_TEST(test_integration_roundtrip_022);
  RUN_TEST(test_integration_roundtrip_023);
  RUN_TEST(test_integration_roundtrip_024);
  RUN_TEST(test_integration_roundtrip_025);
  RUN_TEST(test_integration_roundtrip_026);
  RUN_TEST(test_integration_roundtrip_027);
  RUN_TEST(test_integration_roundtrip_028);
  RUN_TEST(test_integration_roundtrip_029);
  RUN_TEST(test_integration_roundtrip_030);
  RUN_TEST(test_integration_roundtrip_031);
  RUN_TEST(test_integration_roundtrip_032);
  RUN_TEST(test_integration_roundtrip_033);
  RUN_TEST(test_integration_roundtrip_034);
  RUN_TEST(test_integration_roundtrip_035);
  RUN_TEST(test_integration_roundtrip_036);
  RUN_TEST(test_integration_roundtrip_037);
  RUN_TEST(test_integration_roundtrip_038);
  RUN_TEST(test_integration_roundtrip_039);
  RUN_TEST(test_integration_roundtrip_040);
  RUN_TEST(test_integration_roundtrip_041);
  RUN_TEST(test_integration_roundtrip_042);
  RUN_TEST(test_integration_roundtrip_043);
  RUN_TEST(test_integration_roundtrip_044);
  RUN_TEST(test_integration_roundtrip_045);
  RUN_TEST(test_integration_roundtrip_046);
  RUN_TEST(test_integration_roundtrip_047);
  RUN_TEST(test_integration_roundtrip_048);
  RUN_TEST(test_integration_roundtrip_049);
  RUN_TEST(test_integration_roundtrip_050);
  RUN_TEST(test_integration_roundtrip_051);
  RUN_TEST(test_integration_roundtrip_052);
  RUN_TEST(test_integration_roundtrip_053);
  RUN_TEST(test_integration_roundtrip_054);
  RUN_TEST(test_integration_roundtrip_055);
  RUN_TEST(test_integration_roundtrip_056);
  RUN_TEST(test_integration_roundtrip_057);
  RUN_TEST(test_integration_roundtrip_058);
  RUN_TEST(test_integration_roundtrip_059);
  RUN_TEST(test_integration_roundtrip_060);
  RUN_TEST(test_integration_roundtrip_061);
  RUN_TEST(test_integration_roundtrip_062);
  RUN_TEST(test_integration_roundtrip_063);
  RUN_TEST(test_integration_roundtrip_064);
  RUN_TEST(test_integration_roundtrip_065);
  RUN_TEST(test_integration_roundtrip_066);
  RUN_TEST(test_integration_roundtrip_067);
  RUN_TEST(test_integration_roundtrip_068);
  RUN_TEST(test_integration_roundtrip_069);
  RUN_TEST(test_integration_roundtrip_070);
  RUN_TEST(test_integration_roundtrip_071);
  RUN_TEST(test_integration_roundtrip_072);
  RUN_TEST(test_integration_roundtrip_073);
  RUN_TEST(test_integration_roundtrip_074);
  RUN_TEST(test_integration_roundtrip_075);
  RUN_TEST(test_integration_roundtrip_076);
  RUN_TEST(test_integration_roundtrip_077);
  RUN_TEST(test_integration_roundtrip_078);
  RUN_TEST(test_integration_roundtrip_079);
  RUN_TEST(test_integration_roundtrip_080);
  RUN_TEST(test_integration_roundtrip_081);
  RUN_TEST(test_integration_roundtrip_082);
  RUN_TEST(test_integration_roundtrip_083);
  RUN_TEST(test_integration_roundtrip_084);
  RUN_TEST(test_integration_roundtrip_085);
  RUN_TEST(test_integration_roundtrip_086);
  RUN_TEST(test_integration_roundtrip_087);
  RUN_TEST(test_integration_roundtrip_088);
  RUN_TEST(test_integration_roundtrip_089);
  RUN_TEST(test_integration_roundtrip_090);
  RUN_TEST(test_integration_roundtrip_091);
  RUN_TEST(test_integration_roundtrip_092);
  RUN_TEST(test_integration_roundtrip_093);
  RUN_TEST(test_integration_roundtrip_094);
  RUN_TEST(test_integration_roundtrip_095);
  RUN_TEST(test_integration_roundtrip_096);
  RUN_TEST(test_integration_roundtrip_097);
  RUN_TEST(test_integration_roundtrip_098);
  RUN_TEST(test_integration_roundtrip_099);
  RUN_TEST(test_integration_roundtrip_100);
  RUN_TEST(test_integration_roundtrip_101);
  RUN_TEST(test_integration_roundtrip_102);
  RUN_TEST(test_integration_roundtrip_103);
  RUN_TEST(test_integration_roundtrip_104);
  RUN_TEST(test_integration_roundtrip_105);
  RUN_TEST(test_integration_roundtrip_106);
  RUN_TEST(test_integration_roundtrip_107);
  RUN_TEST(test_integration_roundtrip_108);
  RUN_TEST(test_integration_roundtrip_109);
  RUN_TEST(test_integration_roundtrip_110);
  RUN_TEST(test_integration_roundtrip_111);
  RUN_TEST(test_integration_roundtrip_112);
  RUN_TEST(test_integration_roundtrip_113);
  RUN_TEST(test_integration_roundtrip_114);
  RUN_TEST(test_integration_roundtrip_115);
  RUN_TEST(test_integration_roundtrip_116);
  RUN_TEST(test_integration_roundtrip_117);
  RUN_TEST(test_integration_roundtrip_118);
  RUN_TEST(test_integration_roundtrip_119);
}
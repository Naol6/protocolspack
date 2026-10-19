#include "unity.h"

#include <string.h>

struct UnityStorage Unity;

void UnityBegin(const char *suite) {
  (void)suite;
  Unity.failures = 0;
}

int UnityEnd(void) {
  if (Unity.failures == 0) {
    printf("-----------------------\n%d Tests 0 Failures 0 Ignored\nOK\n",
           Unity.failures);
  } else {
    printf("-----------------------\nFAILURES: %d\n", Unity.failures);
  }
  return Unity.failures;
}

void UnityConcludeTest(void) {}

void UnityFail(const char *msg, const char *file, int line) {
  Unity.failures++;
  Unity.file = file;
  Unity.line = line;
  printf("\n  %s:%d: %s\n", file, line, msg ? msg : "fail");
  TEST_ABORT();
}

/* Unity Test Framework - Copyright (c) 2007 Mike Karlesky, Mark VanderVoord, Greg Williams */
#ifndef UNITY_H
#define UNITY_H

#include <setjmp.h>
#include <stdio.h>
#include <string.h>

#define UNITY_VERSION_MAJOR 2
#define UNITY_VERSION_MINOR 5

struct UnityStorage {
  jmp_buf jmp;
  int failures;
  const char *file;
  int line;
};

extern struct UnityStorage Unity;

#define TEST_PROTECT() (setjmp(Unity.jmp) == 0)
#define TEST_ABORT() longjmp(Unity.jmp, 1)

void UnityBegin(const char *suite);
int UnityEnd(void);
void UnityConcludeTest(void);

#define TEST_ASSERT(condition)                                                   \
  do {                                                                           \
    if (!(condition)) {                                                          \
      UnityFail("Expected TRUE", __FILE__, __LINE__);                            \
    }                                                                            \
  } while (0)

#define TEST_ASSERT_FALSE(condition) TEST_ASSERT(!(condition))
#define TEST_ASSERT_TRUE(condition) TEST_ASSERT(condition)
#define TEST_ASSERT_NULL(p) TEST_ASSERT((p) == NULL)
#define TEST_ASSERT_NOT_NULL(p) TEST_ASSERT((p) != NULL)
#define TEST_ASSERT_EQUAL_INT(expected, actual)                                  \
  do {                                                                           \
    int _e = (expected);                                                         \
    int _a = (actual);                                                           \
    if (_e != _a) {                                                              \
      char _msg[128];                                                            \
      snprintf(_msg, sizeof(_msg), "Expected %d Was %d", _e, _a);                \
      UnityFail(_msg, __FILE__, __LINE__);                                       \
    }                                                                            \
  } while (0)

#define TEST_ASSERT_EQUAL_INT64(expected, actual)                                  \
  do {                                                                           \
    long long _e = (expected);                                                   \
    long long _a = (actual);                                                     \
    if (_e != _a) {                                                              \
      UnityFail("int64 not equal", __FILE__, __LINE__);                          \
    }                                                                            \
  } while (0)

#define TEST_ASSERT_EQUAL_STRING(expected, actual)                               \
  do {                                                                           \
    const char *_e = (expected);                                                 \
    const char *_a = (actual);                                                   \
    if (!_e || !_a || strcmp(_e, _a) != 0) {                                     \
      UnityFail("strings not equal", __FILE__, __LINE__);                        \
    }                                                                            \
  } while (0)

#define TEST_ASSERT_EQUAL_PTR(expected, actual)                                  \
  TEST_ASSERT((expected) == (actual))

#define RUN_TEST(func)                                                           \
  do {                                                                           \
    printf("  %s ... ", #func);                                                  \
    fflush(stdout);                                                              \
    if (TEST_PROTECT()) {                                                        \
      func();                                                                    \
      UnityConcludeTest();                                                       \
      printf("PASS\n");                                                          \
    } else {                                                                     \
      printf("FAIL\n");                                                          \
    }                                                                            \
  } while (0)

void UnityFail(const char *msg, const char *file, int line);

#endif

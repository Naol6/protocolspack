#include "strutil.h"

#include "protocolspack_internal.h"

#include <ctype.h>

int proto_is_key_char(char c) {
  return (unsigned char)c == '_' || isalnum((unsigned char)c);
}

int proto_is_key_start(char c) {
  return (unsigned char)c == '_' || isalpha((unsigned char)c);
}

int proto_str_ieq(const char *a, const char *b) {
  if (!a || !b) {
    return 0;
  }
  while (*a && *b) {
    char ca = (char)tolower((unsigned char)*a);
    char cb = (char)tolower((unsigned char)*b);
    if (ca != cb) {
      return 0;
    }
    a++;
    b++;
  }
  return *a == *b;
}

char *proto_strdup(const char *s) {
  size_t n = strlen(s);
  char *p = (char *)malloc(n + 1);
  if (!p) {
    return NULL;
  }
  memcpy(p, s, n + 1);
  return p;
}

char *proto_strndup(const char *s, size_t n) {
  char *p = (char *)malloc(n + 1);
  if (!p) {
    return NULL;
  }
  memcpy(p, s, n);
  p[n] = '\0';
  return p;
}

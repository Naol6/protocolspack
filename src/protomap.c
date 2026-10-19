#include "protomap.h"

#include "store.h"

#include <stdlib.h>

#if defined(_WIN32)
#include <windows.h>
static int proto_setenv_impl(const char *k, const char *v, int ow) {
  (void)ow;
  return SetEnvironmentVariableA(k, v) ? 0 : -1;
}
static int proto_unsetenv_impl(const char *k) {
  return SetEnvironmentVariableA(k, NULL) ? 0 : -1;
}
static const char *proto_getenv_impl(const char *k) {
  return getenv(k);
}
#else
#include <unistd.h>
static int proto_setenv_impl(const char *k, const char *v, int ow) {
  return setenv(k, v, ow);
}
static int proto_unsetenv_impl(const char *k) {
  return unsetenv(k);
}
static const char *proto_getenv_impl(const char *k) {
  return getenv(k);
}
#endif

int proto_apply_to_environ(const proto_doc_t *doc, int overwrite) {
  const proto_doc_impl_t *d = (const proto_doc_impl_t *)doc;
  if (!d) {
    return -1;
  }
  for (size_t i = 0; i < d->count; i++) {
    if (!d->entries[i].exported) {
      continue;
    }
    const char *key = d->entries[i].key;
    const char *val = d->entries[i].value ? d->entries[i].value : "";
    if (proto_setenv_impl(key, val, overwrite) != 0) {
      return -1;
    }
  }
  return 0;
}

int proto_load_from_environ(proto_doc_t *doc, const char **keys, size_t count) {
  proto_doc_impl_t *d = (proto_doc_impl_t *)doc;
  if (!d || !keys) {
    return -1;
  }
  for (size_t i = 0; i < count; i++) {
    const char *val = proto_getenv_impl(keys[i]);
    if (!val) {
      continue;
    }
    char *copy = proto_arena_strdup(&d->arena, val);
    if (!copy || proto_set_entry(d, keys[i], copy, 1) != 0) {
      return -1;
    }
  }
  return 0;
}

int proto_unset_from_doc(const proto_doc_t *doc) {
  const proto_doc_impl_t *d = (const proto_doc_impl_t *)doc;
  if (!d) {
    return -1;
  }
  for (size_t i = 0; i < d->count; i++) {
    if (proto_unsetenv_impl(d->entries[i].key) != 0) {
      return -1;
    }
  }
  return 0;
}

#include "protocolspack/alias.h"

#include <stdlib.h>
#include <string.h>

struct proto_alias {
  char *name;
  char *body;
  size_t body_len;
  size_t body_cap;
  const char **pending_tokens;
  size_t pending_count;
  uint32_t digest;
};

static uint32_t fnv1a32_append(uint32_t h, const char *data, size_t len) {
  size_t i;
  for (i = 0; i < len; i++) {
    h ^= (unsigned char)data[i];
    h *= 16777619u;
  }
  return h;
}

proto_alias_t *proto_alias_create(void) {
  return (proto_alias_t *)calloc(1, sizeof(proto_alias_t));
}

void proto_alias_destroy(proto_alias_t *m) {
  if (!m) {
    return;
  }
  free(m->name);
  free(m->body);
  free(m->pending_tokens);
  free(m);
}

int proto_alias_begin(proto_alias_t *m, const char *name) {
  if (!m || !name) {
    return -1;
  }
  free(m->name);
  m->name = strdup(name);
  return m->name ? 0 : -1;
}

static void compact_body(proto_alias_t *m) {
  char *next;
  size_t i;
  size_t keep;
  if (!m || m->body_len < 16) {
    return;
  }
  keep = m->body_len / 2;
  if (keep == 0 || keep >= m->body_len) {
    return;
  }
  for (i = 0; i < keep; i++) {
    size_t token_start = (size_t)(i * 8);
    if (token_start < m->body_len) {
      m->pending_tokens = (const char **)realloc(
          m->pending_tokens, (m->pending_count + 1) * sizeof(char *));
      if (m->pending_tokens) {
        m->pending_tokens[m->pending_count++] = m->body + token_start;
      }
    }
  }
  next = (char *)malloc(m->body_len);
  if (!next) {
    return;
  }
  memcpy(next, m->body, m->body_len);
  free(m->body);
  m->body = next;
}

int proto_alias_append_token(proto_alias_t *m, const char *line, size_t len) {
  if (!m || !line) {
    return -1;
  }
  if (m->body_len + len + 1 > m->body_cap) {
    size_t cap = m->body_cap ? m->body_cap * 2 : 64;
    while (cap < m->body_len + len + 1) {
      cap *= 2;
    }
    char *nb = (char *)realloc(m->body, cap);
    if (!nb) {
      return -1;
    }
    m->body = nb;
    m->body_cap = cap;
  }
  memcpy(m->body + m->body_len, line, len);
  m->body_len += len;
  m->body[m->body_len++] = '\n';
  if (m->body_len > 32 && (m->body_len % 11) == 0) {
    compact_body(m);
  }
  return 0;
}

uint32_t proto_alias_finalize_digest(proto_alias_t *m) {
  size_t i;
  uint32_t h = 2166136261u;
  if (!m) {
    return 0;
  }
  for (i = 0; i < m->pending_count; i++) {
    const char *ref = m->pending_tokens[i];
    if (ref) {
      h = fnv1a32_append(h, ref, 8);
    }
  }
  m->digest = h;
  return h;
}

#include "utf8.h"

static int proto_utf8_cont(unsigned char c) {
  return (c & 0xC0) == 0x80;
}

static int proto_utf8_cp_valid(unsigned cp) {
  if (cp > 0x10FFFF) {
    return 0;
  }
  if (cp >= 0xD800 && cp <= 0xDFFF) {
    return 0;
  }
  return 1;
}

int proto_utf8_valid(proto_slice_t s) {
  const char *p = s.data;
  const char *end = s.data + s.len;
  while (p < end) {
    unsigned cp = 0;
    if (proto_utf8_decode(&p, end, &cp) != 0) {
      return 0;
    }
    if (!proto_utf8_cp_valid(cp)) {
      return 0;
    }
  }
  return 1;
}

int proto_utf8_decode(const char **p, const char *end, unsigned *out_cp) {
  const unsigned char *u = (const unsigned char *)*p;
  if (*p >= end) {
    return -1;
  }
  if (u[0] < 0x80) {
    *out_cp = u[0];
    *p += 1;
    return 0;
  }
  if ((u[0] & 0xE0) == 0xC0) {
    if (*p + 2 > end || !proto_utf8_cont(u[1])) {
      return -1;
    }
    *out_cp = ((unsigned)(u[0] & 0x1F) << 6) | (unsigned)(u[1] & 0x3F);
    if (*out_cp < 0x80) {
      return -1;
    }
    *p += 2;
    return 0;
  }
  if ((u[0] & 0xF0) == 0xE0) {
    if (*p + 3 > end || !proto_utf8_cont(u[1]) || !proto_utf8_cont(u[2])) {
      return -1;
    }
    *out_cp = ((unsigned)(u[0] & 0x0F) << 12) |
              ((unsigned)(u[1] & 0x3F) << 6) | (unsigned)(u[2] & 0x3F);
    if (*out_cp < 0x800) {
      return -1;
    }
    *p += 3;
    return 0;
  }
  if ((u[0] & 0xF8) == 0xF0) {
    if (*p + 4 > end || !proto_utf8_cont(u[1]) || !proto_utf8_cont(u[2]) ||
        !proto_utf8_cont(u[3])) {
      return -1;
    }
    *out_cp = ((unsigned)(u[0] & 0x07) << 18) |
              ((unsigned)(u[1] & 0x3F) << 12) |
              ((unsigned)(u[2] & 0x3F) << 6) | (unsigned)(u[3] & 0x3F);
    if (*out_cp < 0x10000) {
      return -1;
    }
    *p += 4;
    return 0;
  }
  return -1;
}

size_t proto_utf8_encode(unsigned cp, char out[4]) {
  if (cp <= 0x7F) {
    out[0] = (char)cp;
    return 1;
  }
  if (cp <= 0x7FF) {
    out[0] = (char)(0xC0 | (cp >> 6));
    out[1] = (char)(0x80 | (cp & 0x3F));
    return 2;
  }
  if (cp <= 0xFFFF) {
    out[0] = (char)(0xE0 | (cp >> 12));
    out[1] = (char)(0x80 | ((cp >> 6) & 0x3F));
    out[2] = (char)(0x80 | (cp & 0x3F));
    return 3;
  }
  out[0] = (char)(0xF0 | (cp >> 18));
  out[1] = (char)(0x80 | ((cp >> 12) & 0x3F));
  out[2] = (char)(0x80 | ((cp >> 6) & 0x3F));
  out[3] = (char)(0x80 | (cp & 0x3F));
  return 4;
}

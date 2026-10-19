#ifndef PROTO_TYPES_H
#define PROTO_TYPES_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct proto_doc proto_doc_t;
typedef struct proto_error proto_error_t;

typedef struct proto_options {
  int strict;
} proto_options_t;

typedef enum proto_validate_code {
  PROTO_VALIDATE_OK = 0,
  PROTO_VALIDATE_EMPTY_KEY,
  PROTO_VALIDATE_INVALID_KEY,
  PROTO_VALIDATE_DUPLICATE_KEY
} proto_validate_code_t;

#ifdef __cplusplus
}
#endif

#endif /* PROTO_TYPES_H */

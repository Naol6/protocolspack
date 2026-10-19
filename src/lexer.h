#ifndef PROTO_LEXER_H
#define PROTO_LEXER_H

#include "protocolspack_internal.h"

typedef enum proto_token_kind {
  PROTO_TOK_EOF = 0,
  PROTO_TOK_NEWLINE,
  PROTO_TOK_IDENT,
  PROTO_TOK_EQUAL,
  PROTO_TOK_STRING,
  PROTO_TOK_UNQUOTED,
  PROTO_TOK_EXPORT,
  PROTO_TOK_PROFILE,
  PROTO_TOK_INCLUDE
} proto_token_kind_t;

typedef struct proto_token {
  proto_token_kind_t kind;
  proto_slice_t text;
  int line;
  int column;
} proto_token_t;

typedef struct proto_lexer {
  const char *cur;
  const char *end;
  int line;
  int column;
  int strict;
} proto_lexer_t;

void proto_lexer_init(proto_lexer_t *lx, const char *data, size_t len,
                        int strict);
int proto_lexer_next(proto_lexer_t *lx, proto_token_t *tok);

#endif /* PROTO_LEXER_H */

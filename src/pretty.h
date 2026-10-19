#ifndef PROTO_PRETTY_H
#define PROTO_PRETTY_H

#include "protocolspack/proto_types.h"

int proto_format_pretty(const proto_doc_t *doc, char **out_buf, size_t *out_len);
int proto_pretty_entry(const char *key, const char *value, int exported,
                         char **out_line, size_t *out_len);

#endif /* PROTO_PRETTY_H */

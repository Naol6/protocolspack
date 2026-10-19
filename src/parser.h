#ifndef PROTO_PARSER_H
#define PROTO_PARSER_H

#include "protocolspack/proto_types.h"
#include "import_ctx.h"

int proto_parse_buffer(const char *data, size_t len,
                         const proto_options_t *opt,
                         proto_doc_t **out_doc, proto_error_t **out_err);

int proto_parse_buffer_with_includes(
    const char *data, size_t len, const proto_options_t *opt,
    proto_read_include_fn read_fn, void *read_ctx,
    proto_doc_t **out_doc, proto_error_t **out_err);

#endif /* PROTO_PARSER_H */

#include "protocolspack/proto.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int cmd_parse(const char *path) {
  proto_doc_t *doc = NULL;
  proto_error_t *err = NULL;
  if (proto_parse_file(path, NULL, &doc, &err) != 0) {
    fprintf(stderr, "parse error: %s\n",
            err ? proto_error_message(err) : "unknown");
    proto_error_free(err);
    return 1;
  }
  printf("OK: %s (%zu entries)\n", path, proto_entry_count(doc));
  for (size_t i = 0; i < proto_entry_count(doc); i++) {
    printf("  %s%s=%s\n", proto_entry_exported(doc, i) ? "export " : "",
           proto_entry_key(doc, i), proto_entry_value(doc, i));
  }
  proto_doc_free(doc);
  return 0;
}

int main(int argc, char **argv) {
  if (argc < 3 || strcmp(argv[1], "parse") != 0) {
    fprintf(stderr, "usage: %s parse <file.protocols>\n", argv[0]);
    return 1;
  }
  return cmd_parse(argv[2]);
}

# protocolspack

protocolspack is a C11 library for parsing, merging, and serializing **`/etc/protocols`** service protocol tables: whitespace-separated rows of protocol name, IANA number, and optional aliases, with `@import` overlays and quoted alias unescape.

## Features

- **Protocol rows** — `tcp 6 TCP`, `udp 17 UDP`, comment lines
- **Alias batch capture** — multiline alias token batches with digest finalization
- **@import** — layered protocol table includes via reader callback
- **Merge, serialize, validate** — round-trip and overlay composition
- ClusterFuzzLite harnesses: `parse_fuzzer`, `merge_fuzzer`, `import_fuzzer`, `alias_fuzzer`

## Build

```bash
bash build/wsl_build.sh
make test
```

## Quick start

```c
#include "protocolspack/proto.h"

const char *src =
  "tcp 6 TCP\n"
  "udp 17 UDP\n";
proto_doc_t *doc = NULL;
proto_parse_memory(src, strlen(src), NULL, &doc, NULL);
proto_doc_free(doc);
```

## License

MIT — see LICENSE.

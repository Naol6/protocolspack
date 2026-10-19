#!/bin/bash
set -eu
cd "$(dirname "$0")/.."
export SRC="$PWD"
export OUT=/tmp/protocolspack_out
mkdir -p "$OUT"
rm -f *.o

if command -v clang >/dev/null 2>&1; then
  export CC=clang
  export CXX=clang++
  export CFLAGS="-O1 -g -std=c11 -Wall -D_GNU_SOURCE -fsanitize=address"
  export CXXFLAGS="-O1 -g -std=c++17 -fsanitize=address"
  export LIB_FUZZING_ENGINE=-fsanitize=fuzzer
  bash .clusterfuzzlite/build.sh
else
  echo "clang required" >&2
  exit 1
fi
ls -la "$OUT"
echo "Build OK — fuzzers in $OUT"

CC ?= gcc
CXX ?= g++
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -Iinclude -Isrc -g -O1
LDFLAGS ?=

SRC_MODULES = buffer strutil error arena utf8 store unescape lexer parser serialize \
              validate merge expand coerce walk query diff pretty import_stack \
              import_ctx path filter protomap profile canonical strict readutil \
              snapshot protopack protocolspack
SRC_OBJS = $(SRC_MODULES:%=build/%.o)

LIB = build/libprotocolspack.a
CLI = build/protocolspackrc
TEST_BIN = build/proto_tests

UNITY = tests/unity/unity.c

.PHONY: all clean test generate-tests

all: $(LIB) $(CLI)

generate-tests:
	python3 tools/gen_proto_tests.py

$(LIB): $(SRC_OBJS)
	ar rcs $@ $^

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

build/protocolspackrc: cli/protocolspackrc.c $(LIB)
	$(CC) $(CFLAGS) $< -Lbuild -lprotocolspack -o $@

TEST_SRCS = tests/test_runner.c tests/test_basic.c tests/test_serialize.c \
            tests/test_merge.c tests/test_validate.c tests/test_expand.c \
            tests/test_coerce.c tests/test_scenarios.c tests/test_integration.c \
            tests/test_parser_deep.c tests/test_lexer_exhaustive.c

$(TEST_BIN): $(TEST_SRCS) $(UNITY) $(LIB)
	@mkdir -p build
	$(CC) $(CFLAGS) -Itests/unity $(TEST_SRCS) $(UNITY) -Lbuild -lprotocolspack -o $@

test: $(TEST_BIN)
	./$(TEST_BIN)

clean:
	rm -rf build

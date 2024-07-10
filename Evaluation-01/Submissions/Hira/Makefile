# TODO: Create a Makefile with the following targets:
# - all: Build the project
# - division: Compile the C program
# - test: Run the basic C testbench
# - clean: Remove build artifacts
# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall

# Debug flags
DEBUG_FLAGS = -g

# Object files
OBJS = $(SRCS:.c=.o)

# Debug target to compile with debugging symbols
debug: CFLAGS += $(DEBUG_FLAGS)
debug: clean all
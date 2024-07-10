# Author: Hamza
# Date: 10 July 2024
# Makefile for C and TCL program
 
# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Source files
SRCS = $(wildcard *.c)

# Executable name
TARGET = divisionProgram

.PHONY: all


# Default target
all: $(TARGET)

# Build target
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

run:
	./$(TARGET)

test:
	tclsh test.tcl

# Clean target
clean:
	rm -f *.o $(TARGET)

# Variables
CC = gcc
CFLAGS = -Wall -Werror -g
TARGET = division_program
SOURCES = division_program.c
TCL_SCRIPT = test.tcl

# Default target
all: build run_tests

# Target to build the C program
build: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# Target to run the TCL-based tests
run_tests: $(TARGET)
	tclsh $(TCL_SCRIPT)

# Target to run the compiled program
run: $(TARGET)
	./$(TARGET)

# Target to clean the build artifacts
clean:
	rm -f $(TARGET) test_cases.txt generated_results.txt summary_report.txt

# Phony targets
.PHONY: all build run_tests run clean

# TODO: Create a Makefile with the following targets:
# - all: Build the project
# - division: Compile the C program
# - test: Run the basic C testbench
# - clean: Remove build artifacts


# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Source file
SRC = division.c

# Output executable
TARGET = mydivision

# Default rule
all: $(TARGET)
#   tcl run
	tclsh test.tcl
	./$(TARGET)

# Rule to compile the source file into the executable
$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) 

# Rule to run the program
run: $(TARGET)
	./$(TARGET)

# Clean rule to remove the compiled executable
clean:
	rm -f $(TARGET)

# PHONY targets
.PHONY: all run clean



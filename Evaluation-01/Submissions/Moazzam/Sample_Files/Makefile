# TODO: Create a Makefile with the following targets:
# - all: Build the project
# - division: Compile the C program
# - test: Run the basic C testbench
# - clean: Remove build artifacts

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall 

# Target executable
TARGET = myprogram

# Source and Object files
SRCE = division.c
OBJS = division.o


# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJS): $(SRCE)
	$(CC) $(CFLAGS) -c $(SRCE)

# - test: Run the basic C testbench
test : $(TARGET)
	./$(TARGET)
# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
#.PHONY: all clean


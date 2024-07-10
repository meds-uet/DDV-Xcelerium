# Makefile for compiling a single C file

# Target executable name
TARGET = divider

# Compiler to use
CC = gcc

#src
SRC = divider.c

# Compile the program
$(TARGET): divider.c
	$(CC) -o $(TARGET) $(SRC)

	
run:
	./$(TARGET)

# Clean the built files
clean:
	rm -f $(TARGET)


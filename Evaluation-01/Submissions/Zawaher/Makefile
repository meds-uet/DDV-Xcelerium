#author : Zawaher Bin Asim
#Date : 10 Jul 2024
#This file is the Makefile to automate the testing of the division file writte in c






# TODO: Create a Makefile with the following targets:
# - all: Build the project
# - division: Compile the C program
# - test: Run the basic C testbench
# - clean: Remove build artifacts

CC = gcc
CFLAGES = -g

# Define directories for the C FILES
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# Find all source files and corresponding object files
SOURCES := $(wildcard $(SRC_DIR)/*.c)   #Uses the wildcard function to find all .c

OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
# Uses the patsubst function to convert each .c file path in SOURCES to a corresponding .o file path in the obj directory and assigns them to the OBJECTS variable.

EXECUTABLES := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%, $(SOURCES))

#////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////#


all: $(EXECUTABLES)  #this will build the project

division : $(OBJECTS) # this will compile the project

test : $(EXECUTABLES)
	cd bin
	./division

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $< to $@"
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# Rule to link object files into executables
$(BIN_DIR)/%: $(OBJ_DIR)/%.o
	@echo "Linking $< to $@"
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	@echo "Cleaning for C Compilation"
	@echo ""
	rm -rf $(OBJ_DIR) $(BIN_DIR)

#Phony targets
.PHONY : all division test clean


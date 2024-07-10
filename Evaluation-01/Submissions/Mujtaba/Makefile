# TODO: Create a Makefile with the following targets:
# - all: Build the project
# - division: Compile the C program
# - test: Run the basic C testbench
# - clean: Remove build artifacts
# _*_ Makfile _*_

all: division

division: division.c
	@gcc division.c -o  division

# test: 

.PHONY: all clean run
run: 
	@./division
clean:
	@rm *.o division
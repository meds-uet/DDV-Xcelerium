# TODO: Create a Makefile with the following targets:
# - all: Build the project
# - division: Compile the C program
# - test: Run the basic C testbench
# - clean: Remove build artifacts

SRC:=$(wildcard ./src/*.c)

all: run compile

division: $(SRC)
	rm -rf obj
	mkdir obj
	gcc -o ./obj/division ./src/division.c

test: compile
	./obj/division

debug:
	rm -rf obj
	mkdir obj
	gcc -g -o ./obj/division ./src/division.c
	gdb -tui ./obj/division

clean:
	rm -rf ./obj *.o ./src/*.swap

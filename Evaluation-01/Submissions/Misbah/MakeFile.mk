all: execute
	@echo "Done!"
execute: division.o
	gcc division.o -o execute
main.o: division.c
	gcc -c division.c -o division.o
clean:
	rm -f execute division.o

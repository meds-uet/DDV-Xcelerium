CC = gcc
CFLAGS = -Wall

target = division.o

all: main

run : 
	./division

main: $(target)
	$(CC) -o division division.o

$(target): division.c
	$(CC) $(CFLAGS) -c division.c

clean:
	rm -rf main division *.o
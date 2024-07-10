
# Define the variables
CC = gcc
CFLAGS = -Wall 
TARGET = division

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

run: $(TARGET)
	./$(TARGET)

tcl_tests: $(TARGET)
	tclsh test.tcl

clean:
	rm -f $(TARGET) *.o test_cases.txt

.PHONY: all run tcl_tests clean

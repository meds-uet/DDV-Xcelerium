TARGET=division
all:test
	@echo "Done!!"
$(TARGET):division.o
	gcc division.o -o $@
division.o:division.c
	gcc -c division.c -o division.o
test:$(TARGET)
	./$(TARGET)
clean:
	rm -r $(TARGET) division.o

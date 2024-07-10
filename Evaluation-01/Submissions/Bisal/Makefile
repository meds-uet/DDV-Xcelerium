#  ============================================================================
#  Filename:    Makefile
#  Description: File consists of code for  Makefile
#  Author:      Bisal Saeed
#  Date:        7/4/2024
#  ============================================================================
CC= gcc
CFLAGS=-Walls
TARGET=division
SRCS=$(wildcard ../*.c)

#to build target
all: $(TARGET) 

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

#COMPILATION
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

#CLEAN 
clean: rm -f $(TARGET) 
#not actual files but commands to execute 
.PHONY: all clean debug
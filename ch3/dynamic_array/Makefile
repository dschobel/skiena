CC=clang
CFLAGS=-c -Wall -g -O0

all: dynamic_array

dynamic_array: dynamic_array.o
	$(CC) dynamic_array.o -o dynamic_array

dynamic_array.o: dynamic_array.c
	$(CC) $(CFLAGS) dynamic_array.c

clean:
	rm -rf *o dynamic_array

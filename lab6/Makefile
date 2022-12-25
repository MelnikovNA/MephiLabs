SOURCES := str_lib.c cyclic_shift_right.c main.c
DEPS := lab6.h


all: main

OBJECTS := str_lib.o cyclic_shift_right.o main.o
CC=gcc
CFLAGS=-I.

main: $(OBJECTS)
	gcc $(OBJECTS) -g -o $@


%.o: %.c $(DEPS)
	$(CC) -c -g -o $@ $< $(CFLAGS)


clean:
	rm $(OBJECTS)
SOURCES := detail.c details_cmp.c heap_sort.c shaker_sort.c sort_utilites.c main.c
DEPS := detail.h


all: main

OBJECTS := detail.o details_cmp.o heap_sort.o shaker_sort.o sort_utilites.o main.o
CC=gcc
CFLAGS=-I.

main: $(OBJECTS) 
	gcc $(OBJECTS) -g -o $@


%.o: %.c $(DEPS)
	$(CC) -c -g -o $@ $< $(CFLAGS)


clean:
	rm $(OBJECTS)

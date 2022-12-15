SOURCES := main.c arrylib.c lab3.c menu.c
DEPS := lab3.h


all: main

OBJECTS := main.o arrylib.o lab3.o menu.o
CC=gcc
CFLAGS=-I.

main: $(OBJECTS) 
	gcc $(OBJECTS) -o $@


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


clean:
	rm $(OBJECTS)

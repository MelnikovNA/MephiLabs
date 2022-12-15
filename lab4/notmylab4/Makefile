SOURCES := main.c personal_task.c strlib.c 
DEPS := lab4.h


all: main

OBJECTS := main.o personal_task.o strlib.o
CC=gcc
CFLAGS=-I.

main: $(OBJECTS) 
	gcc $(OBJECTS) -o $@ -lreadline


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


clean:
	rm $(OBJECTS)

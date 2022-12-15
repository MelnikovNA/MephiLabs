SOURCES := main.c strlib.c personal_task.c 
DEPS := lib4.h


all: main

OBJECTS := main.o strlib.o personal_task.o
CC=gcc
CFLAGS=-I.

main: $(OBJECTS) 
	gcc $(OBJECTS) -o $@ -lreadline


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


clean:
	rm $(OBJECTS)

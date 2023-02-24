CC = gcc
CFLAGS = -g -Wall --std=c99
OBJECTS = main.o queue.o

queue: $(OBJECTS)
	$(CC) $(CFLAGS) -o queue $(OBJECTS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

my_string.o: queue.c queue.h logger.h Status.h
	$(CC) $(CFLAGS) -c queue.c -o queue.o

clean:
	rm queue $(OBJECTS)



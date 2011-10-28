CC = gcc
CFLAGS = -ansi -c -Wall

all: main

main: main.o instructions_table.o
	$(CC) -o main main.o instructions_table.o

main.o: main.c
	$(CC) $(CFLAGS) main.c
	
instructions_table.o: instructions_table.c
	$(CC) $(CFLAGS) instructions_table.c

clean:
	rm -rf hello *.o *~
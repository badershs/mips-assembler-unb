CC = gcc
CFLAGS = -ansi -c -Wall

all: hello

hello: lexical_analyzer.o
	$(CC) -o hello lexical_analyzer.o

lexical_analyzer.o: lexical_analyzer.c mips_assembler.h
	$(CC) $(CFLAGS) lexical_analyzer.c

clean:
	rm -rf hello *.o *~
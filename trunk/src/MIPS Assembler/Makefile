all: hello

hello: test.o
	gcc -o hello test.o

test.o: test.c mips_assembler.h
	gcc -c test.c

clean:
	rm -rf *o hello
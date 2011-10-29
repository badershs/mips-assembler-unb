CC = gcc
CFLAGS = -ansi -c -Wall

all: main_lex

main_lex: string_man.o lexical_analyzer.o main_lex.o mips_assembler.o
	$(CC) -o main_lex main_lex.o string_man.o lexical_analyzer.o mips_assembler.o

main_lex.o: main_lex.c 
	$(CC) $(CFLAGS) main_lex.c

lexical_analyzer.o: lexical_analyzer.c 
	$(CC) $(CFLAGS) lexical_analyzer.c

string_man.o: string_man.c 
	$(CC) $(CFLAGS) string_man.c

mips_assembler.o: mips_assembler.c 
	$(CC) $(CFLAGS) mips_assembler.c





clean:
	rm -rf main_lex *.o *~
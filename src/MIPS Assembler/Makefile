CC = gcc
CFLAGS = -ansi -c -Wall
TABLES = instructions_table.o register_table.o

all: main_lex

main_lex: main_lex.o lexical_analyzer.o mips_assembler.o string_man.o $(TABLES)
	$(CC) $(TABLES) -o main_lex main_lex.o lexical_analyzer.o mips_assembler.o string_man.o

main_lex.o: main_lex.c 
	$(CC) $(CFLAGS) main_lex.c


register_table.o: register_table.c 
	$(CC) $(CFLAGS) register_table.c

instructions_table.o: instructions_table.c 
	$(CC) $(CFLAGS) instructions_table.c

mips_assembler.o: mips_assembler.c 
	$(CC) $(CFLAGS) mips_assembler.c

string_man.o: string_man.c 
	$(CC) $(CFLAGS) string_man.c

lexical_analyzer.o: lexical_analyzer.c 
	$(CC) $(CFLAGS) lexical_analyzer.c




clean:
	rm -rf main_lex *.o *~
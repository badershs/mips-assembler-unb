CC = gcc
CFLAGS = -ansi -c -Wall
TABLES = instructions_table.o register_table.o

all: gmag

gmag: $(TABLES) gmag.o lexical_analyzer.o mips_assembler.o string_man.o  parser.o directives.o
	$(CC) $(TABLES) -o gmag gmag.o lexical_analyzer.o mips_assembler.o string_man.o parser.o directives.o

gmag.o: gmag.c 
	$(CC) $(CFLAGS) gmag.c

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

parser.o: parser.c 
	$(CC) $(CFLAGS) parser.c
	
directives.o: directives.c
	$(CC) $(CFLAGS) directives.c



clean:
	rm -rf gmag *.o *~
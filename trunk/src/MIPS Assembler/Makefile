CC = gcc
CFLAGS = -ansi -c -Wall
TABLES = instructions_table.o register_table.o

all: gmag

gmag: gmag.o $(TABLES) mips_assembler.o directives.o lexical_analyzer.o  parser.o  semantic_analyzer.o code_generator.o string_man.o
	$(CC) -o gmag gmag.o $(TABLES) mips_assembler.o directives.o lexical_analyzer.o  parser.o  semantic_analyzer.o code_generator.o string_man.o

gmag.o: gmag.c 
	$(CC) $(CFLAGS) gmag.c

register_table.o: register_table.c 
	$(CC) $(CFLAGS) register_table.c

instructions_table.o: instructions_table.c 
	$(CC) $(CFLAGS) instructions_table.c

mips_assembler.o: mips_assembler.c 
	$(CC) $(CFLAGS) mips_assembler.c

directives.o: directives.c
	$(CC) $(CFLAGS) directives.c

lexical_analyzer.o: lexical_analyzer.c 
	$(CC) $(CFLAGS) lexical_analyzer.c

parser.o: parser.c 
	$(CC) $(CFLAGS) parser.c
	
semantic_analyzer.o: semantic_analyzer.c
	$(CC) $(CFLAGS) semantic_analyzer.c

code_generator.o: code_generator.c
	$(CC) $(CFLAGS) code_generator.c

string_man.o: string_man.c 
	$(CC) $(CFLAGS) string_man.c
	
comparer: comparer.o
	$(CC) -o comparer comparer.o
	
comparer.o: comparer.c 
	$(CC) $(CFLAGS) comparer.c


clean:
	rm -rf gmag *.o *~
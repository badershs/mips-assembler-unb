/* -----------------------------------------------------------------------------
**  MIPS Assembler UnB - Main (Debug file)
**
**  Description: This is just a debug main file, to test isolated functions
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** ---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "string_man.h"
#include "directives.h"
#include "lexical_analyzer.h"
#include "parser.h"
#include "mips_assembler.h"

int code_generator(inst_list* i_list, FILE* output_file) {return 0;}

int main(int argc, char *argv[]){
	int res;
	token_list* tk_list;
	inst_list* il_test;
	symbols_table* s_table;
	
	if((res = set_options(argc, argv)) != ERR_NO_ERROR)
		print_error_msg(0, res);
	return 0;
	
	FILE* input_file = fopen("Testbench.s","r");
	if(input_file != NULL){
		
		lexical_analysis(input_file, &tk_list, &s_table);
		fclose(input_file);
		
		print_line_list(tk_list);
		print_symbols_table(s_table);
		
		parsing(tk_list, &il_test);
		
		/*FILE* output_file = fopen("TestCode.bin","rw");
		if(output_file != NULL){
			code_generator(il_test, output_file);
		}
		else
			printf("Error opening output file\n");*/
	}
	else
		printf("Error opening input file\n");
    
    return 0;
}
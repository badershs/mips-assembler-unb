/* ---------------------------------------------------------------------------
**  MIPS Assembler UnB - Main (Debug file)
**
**  Description: This is just a debug main file, to test isolated functions
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** -------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "string_man.h"
#include "lexical_analyzer.h"

/* PARSING FUNCTION - It should take the token list and perform the syntactic analysis
	In the case, there is no error it should generate a list of instructions and sotre
	in inst_list */
int parsing(token_list* tk_list, void** inst_list) {return 0;}

/* CODE GENERATOR FUNCTION - It should take the list of instructions and write the binary data
	to the output file*/
int code_generator(void* inst_list, FILE* output_file) {return 0;}

int main(){
	token_list* tk_list;
	void* inst_list;
	
	FILE* input_file = fopen("Testbench.s","r");
	if(input_file != NULL){
		
		lexical_analysis(input_file, &tk_list);
		fclose(input_file);
		
		parsing(tk_list, &inst_list);
		
		FILE* output_file = fopen("Testbench.bin","rw");
		if(output_file != NULL){
			code_generator(inst_list, output_file);
		}
		else
			printf("Error opening output file\n");
	}
	else
		printf("Error opening input file\n");
    
    return 0;
}
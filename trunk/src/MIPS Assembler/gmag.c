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

#include "mips_assembler.h"
#include "directives.h"
#include "lexical_analyzer.h"
#include "parser.h"
#include "semantic_analyzer.h"
#include "code_generator.h"
#include "string_man.h"

/* -----------------------------------------------------------------------------
**								GLOBAL VARIABLES
** ---------------------------------------------------------------------------*/
extern uint8_t gflag_analyze_only; 		/* Analyze only, do not mount */
extern uint8_t gflag_warnings;			/* Display warning messages */
extern uint8_t gflag_binary;			/* Generate output in binary format */
						/* when not set, output is generated in binary text */
extern char* g_input_file_name;			/* Input file name */
extern char* g_output_file_name;		/* Output file name */
extern string_list* g_path;	 			/* Where to search for the input file*/

int main(int argc, char *argv[]){
	int res;
	char input_file_name[128];
	token_list* tk_list;
	inst_list* il_list;
	symbols_table* s_table;
	FILE *input_file, *output_file;
	
	/* Analyze main's arguments and set global flags */ 
	if((res = set_options(argc, argv)) != ERR_NO_ERROR)
		print_error_msg(0, res);
	
	/* Open input file */
	strcpy(input_file_name, g_input_file_name);
	input_file = fopen(input_file_name,"r");
	while(input_file == NULL){
		if(g_path == NULL)
			print_error_msg(0, ERR_INV_FILE);
		
		strcpy(input_file_name, g_path->string);
		strcat(input_file_name, "/");
		strcat(input_file_name, g_input_file_name);
		input_file = fopen(input_file_name,"r");
		
		g_path = g_path->next;
	}
	
	/* Lexical Analysis */ 
	lexical_analysis(input_file, &tk_list, &s_table);
	fclose(input_file);
	/*print_line_list(tk_list);*/

	/* Parsing */
	parsing(tk_list, &il_list);
	/*print_inst(il_list);*/
		
	/* Semantic Analysis*/
	semantic_analysis(il_list, s_table);
	
	if(!gflag_analyze_only){
		
		/* Open output file */	
		output_file = fopen(g_output_file_name,"w");
		if(output_file != NULL){
			
			/* Generate output file */
			code_generator(il_list, output_file);
			fclose(output_file);
		}
		else
			print_error_msg(0, ERR_INV_OUT_FILE);
	}
	else
		print_error_msg(0, ERR_ANALYZE_DONE);
	
    return 0;
}
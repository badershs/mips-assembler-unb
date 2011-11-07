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
#include "semantic_analyzer.h"


void binario (int32_t dec, char** bin){
	int i;
	*bin=calloc(33,sizeof(char)); 
	for(i=0;i<32;i++){
		if ((dec & 0x80000000) == 0x80000000)
			(*bin)[i]='1';
		else
			(*bin)[i]='0';
		dec<<=1;
	}
	(*bin)[32]='\0';
}

/*TODO*/
int code_generator(inst_list* i_list, FILE* output_file) {
	char* bin;
	inst_list* p;
	p=i_list;

	while(p!=NULL)
	{

		switch(p->type){
			case 1:
				binario((p->values).op, &bin);
				fprintf(output_file,"%s",&(bin[26]));
				binario((p->values).rs, &bin);
				fprintf(output_file,"%s",&(bin[27]));
				binario((p->values).rt, &bin);
				fprintf(output_file,"%s",&(bin[27]));
				binario((p->values).rd, &bin);
				fprintf(output_file,"%s",&(bin[27]));
				binario((p->values).imm, &bin);
				fprintf(output_file,"%s",&(bin[27]));
				binario((p->values).funct, &bin);
				fprintf(output_file,"%s",&(bin[26]));
			break;
			case 2:
				binario((p->values).op, &bin);
				fprintf(output_file,"%s",&(bin[26]));
				binario((p->values).rs, &bin);
				fprintf(output_file,"%s",&(bin[27]));
				binario((p->values).rt, &bin);
				fprintf(output_file,"%s",&(bin[27]));
				binario((p->values).imm, &bin);
				fprintf(output_file,"%s",&(bin[16]));
			break;
			case 3:
				binario((p->values).op, &bin);
				fprintf(output_file,"%s",&(bin[26]));
				binario((p->values).imm, &bin);
				fprintf(output_file,"%s",&(bin[6]));
			break;
		}
		fprintf(output_file,"\n");
		p=p->next;
	}
	return 0;
}


int main(int argc, char *argv[]){
	int res;
	token_list* tk_list;
	inst_list* il_test;
	symbols_table* s_table;
	
	if((res = set_options(argc, argv)) != ERR_NO_ERROR)
		print_error_msg(0, res);
	
	FILE* input_file = fopen("TestCode.s","r");
	if(input_file == NULL){
		/* Try looking at the g_path variable */
		printf("Error opening input file\n");
	}
	else {
		
		lexical_analysis(input_file, &tk_list, &s_table);
		fclose(input_file);
		
		print_line_list(tk_list);
		print_symbols_table(s_table);
		
		printf("%d\n",parsing(tk_list, &il_test));
		printf("%d\n",semantic_analysis(il_test,s_table));
		
		FILE* output_file = fopen("TestCode.txt","w");
		if(output_file != NULL){
			code_generator(il_test, output_file);
		}
		else
			printf("Error opening output file\n");
		fclose(output_file);
	}
    
    return 0;
}
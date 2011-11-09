/* -----------------------------------------------------------------------------
**  MIPS Assembler UnB - Lexical Analyzer
**
**  Description: 
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** ---------------------------------------------------------------------------*/

#include <stdlib.h>

#include "code_generator.h"
#include "mips_assembler.h"
#include "instructions_table.h"

extern uint8_t gflag_binary;

uint8_t first_line;

int code_generator(inst_list* i_list, FILE* output_file) {
	
	uint32_t inst;
	char* bin;
	inst_list* p;
	p=i_list;
	
	first_line = 1;
	
	while(p!=NULL)
	{
		inst = 0;
		switch(p->type){
			case TYPE_R:
				inst += (p->values).op 		<< 26;
				inst += (p->values).rs 		<< 21;
				inst += (p->values).rt 		<< 16;
				inst += (p->values).rd 		<< 11;
				inst += (p->values).imm 	<< 6;
				inst += (p->values).funct 	<< 0;
				break;
			case TYPE_I:
				inst += (p->values).op 		<< 26;
				inst += (p->values).rs 		<< 21;
				inst += (p->values).rt 		<< 16;
				inst += (uint16_t)(p->values).imm 	<< 0;
				break;
			case TYPE_J:
				inst += (p->values).op 		<< 26;
				inst += (p->values).imm 	<< 0;
				break;
		}
		if(gflag_binary)
			fwrite(&inst, 4, 1, output_file);
		else{
			binario(inst, &bin);
			if(first_line){
				first_line = 0;
				fprintf(output_file,"%s",bin);
			}
			else
				fprintf(output_file,"\n%s",bin);
		}
		p=p->next;
	}
	return 0;
}

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


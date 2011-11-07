/* ---------------------------------------------------------------------------
**  MIPS Assembler UnB - Parser
**
**  Description: 
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** -------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "instructions_table.h"
#include "mips_assembler.h"
#include "semantic_analyzer.h"

#define ERR_COUNT_0	(-0x10000)
#define ERR_COUNT_2	(-0x20000)

uint32_t semantic_analysis(inst_list *first_inst,symbols_table *sym_list)
{
	inst_list *cur_inst=first_inst;
	int32_t index_label;

	int f=1;

	/*printf("\nSemantic Analysis:\n");*/

	while(f)
	{
		/* Verification whether the register ZERO is tried to be modified */
		if( ( ((cur_inst->stype==STYPE_R1)||(cur_inst->stype==STYPE_R5)||(cur_inst->stype==STYPE_R6))&&(cur_inst->values.rd==0) ) ||
		( ((cur_inst->stype==STYPE_I1)||(cur_inst->stype==STYPE_I5)||(cur_inst->values.op==OP_LW)||(cur_inst->values.op==OP_LB)||
			(cur_inst->values.op==OP_LH)||(cur_inst->values.op==OP_LBU)||(cur_inst->values.op==OP_LHU))&&
			(cur_inst->values.rt==0) )) { return ERR_ZERO_REG;}
      
		/* Verification of the immediate size */
		if( ((cur_inst->stype==STYPE_R5) && ((cur_inst->values.imm<0)||(cur_inst->values.imm>31))) ||
		(((cur_inst->values.op==OP_ADDI)||(cur_inst->values.op==OP_ANDI)||(cur_inst->values.op==OP_ORI)||(cur_inst->values.op==OP_SLTI)||(cur_inst->values.op==OP_XORI)||(cur_inst->stype==STYPE_I3)) && ((cur_inst->values.imm<-32768)||(cur_inst->values.imm>32767))) ||
		(((cur_inst->values.op==OP_ADDIU)||(cur_inst->values.op==OP_SLTIU)) && ((cur_inst->values.imm<-0)||(cur_inst->values.imm>65535))) ||
		((cur_inst->stype==STYPE_J2)&&((cur_inst->values.imm<0)||(cur_inst->values.imm>67108863))) ) { return ERR_INV_IMM;}

		/* Verification of the validation of the label*/
		/* The code block bellow has been replaced by another one, because this
		version of the assembler does not allow memmory relocation */
		if( cur_inst->stype==STYPE_J1 ) 
		{
			cur_inst->values.imm_rel=labelvalue(cur_inst->values.symbol, sym_list);
			if( cur_inst->values.imm_rel==ERR_COUNT_0 ) { return ERR_NO_LABEL;}
			else if( cur_inst->values.imm_rel==ERR_COUNT_2 ) { return ERR_MANY_LABELS; }
		}
		/*if( cur_inst->stype==STYPE_J1 ) 
		{
			cur_inst->values.imm=labelvalue(cur_inst->values.symbol, sym_list);
			if( cur_inst->values.imm==ERR_COUNT_0 ) { return ERR_NO_LABEL;}
			else if( cur_inst->values.imm==ERR_COUNT_2 ) { return ERR_MANY_LABELS; }
		}*/
		
		if( (cur_inst->stype==STYPE_I2)||(cur_inst->stype==STYPE_I4) )
		{
			index_label=labelvalue(cur_inst->values.symbol, sym_list);
			cur_inst->values.imm=(index_label-(cur_inst->index+4))*0.25;
			if( index_label==ERR_COUNT_0 ) { return ERR_NO_LABEL;}
			else if( index_label==ERR_COUNT_2 ) { return ERR_MANY_LABELS; }
		}

		/* Next instruction */
		if( cur_inst->next!=NULL )
		cur_inst=cur_inst->next;
		else f=0;
	}
	return ERR_NO_ERROR;
}

int32_t labelvalue(char* label, symbols_table *sym_list) /*returns -0x10000 if the label was not declared and -0x20000 if the label is multi declared*/
{
	symbols_table *cur_sym=sym_list;
	int count=0, f=1;
	int32_t index;

	while(f)
	{
		if( strcmp(cur_sym->symbol,label)==0 )
		{
			count++;
			index=cur_sym->index;
		}
		if( cur_sym->next!=NULL ) { cur_sym=cur_sym->next; }
		else { f=0;}
	}
	if( count==0 ) { return ERR_COUNT_0; }
	else if( count>1 ) {return ERR_COUNT_2; }
	return index;
}
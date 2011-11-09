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

/* -----------------------------------------------------------------------------
**									DEFINES
** ---------------------------------------------------------------------------*/

/* ------------------------------ Parameters ---------------------------------*/
#define INV_LABEL_VALUE	(-1)

#define MAX_IMM_5		(31)
#define MAX_IMM_16		(65535)
#define MAX_IMM_26		(67108863)

/*#define MIN_IMMU_5		(0)
#define MAX_IMMU_5		(31)

#define MIN_IMMU_16		(0)
#define MAX_IMMU_16		(65535)

#define MIN_IMM_16		(-32768)
#define MAX_IMM_16		(32767)

#define MIN_IMMU_26		(0)
#define MAX_IMMU_26		(67108863)*/


uint32_t semantic_analysis(inst_list *first_inst, symbols_table *sym_list)
{
	uint8_t op, stype;
	uint32_t index_label;
	inst_list *cur_inst;
	
	/* Search for duplicated labels */
	verify_symbols_table(sym_list);
	
	cur_inst=first_inst;
	while(cur_inst != NULL)
	{
		/* State variables */
		op = cur_inst->values.op;
		stype = cur_inst->stype;
		
		/* Search and replace the label's matching address */
		/* Jump instructions */
		if( cur_inst->stype==STYPE_J1 ) 
		{
			index_label = labelvalue(cur_inst->values.symbol, sym_list);
			if(index_label == INV_LABEL_VALUE)
				print_error_msg(cur_inst->code_line, ERR_NO_LABEL);
			else
				cur_inst->values.imm=index_label*0.25;
		}
		
		/* Branch instructions */
		if( (cur_inst->stype==STYPE_I2)||(cur_inst->stype==STYPE_I4) )
		{
			index_label=labelvalue(cur_inst->values.symbol, sym_list);
			if(index_label == INV_LABEL_VALUE)
				print_error_msg(cur_inst->code_line, ERR_NO_LABEL);
			else
				cur_inst->values.imm=(index_label-(cur_inst->index+4))*0.25;
		}
		
		/* Verification whether the register ZERO is tried to be modified */
		if((stype==STYPE_R1)||(stype==STYPE_R5)||(stype==STYPE_R6)){
			if(cur_inst->values.rd==0)
				print_error_msg(cur_inst->code_line, ERR_ZERO_REG);
		}
		if((stype==STYPE_I1)||(stype==STYPE_I5)||(op==OP_LW)||(op==OP_LB)|| (op==OP_LH)||(op==OP_LBU)||(op==OP_LHU)){
			if(cur_inst->values.rt==0)
				print_error_msg(cur_inst->code_line, ERR_ZERO_REG);
		}
      
		/* Verification if the immediate is not out of bounds */		
		if(((op == OP_ADDIU) || (op == OP_SLTIU)) && cur_inst->values.imm < 0){
			print_error_msg(cur_inst->code_line, ERR_NEG_UNS);
		}
		
		if(cur_inst->stype==STYPE_R5){
			if(cur_inst->values.imm> MAX_IMM_5)
				print_error_msg(cur_inst->code_line, ERR_INV_IMM);
		}
		if((op == OP_ADDI) || (op == OP_ANDI) || (op == OP_ORI) || (op == OP_SLTI) || (op == OP_XORI) || (op == OP_ADDIU) || (op == OP_SLTIU) || (cur_inst->stype==STYPE_I3)){
			/*if(cur_inst->values.imm >> 16 != 0){
				if(cur_inst->values.imm >> 15 != 0x1FFFF)
					print_error_msg(cur_inst->code_line, ERR_INV_IMM);
			}*/
			if(((int16_t)cur_inst->values.imm != cur_inst->values.imm) && ((uint16_t)cur_inst->values.imm != cur_inst->values.imm))
				print_error_msg(cur_inst->code_line, ERR_INV_IMM);
		}
		if(cur_inst->stype==STYPE_J2){
			if(cur_inst->values.imm> MAX_IMM_26)
				print_error_msg(cur_inst->code_line, ERR_INV_IMM);
		}
		
		/* Take the next instruction */
		cur_inst=cur_inst->next;
	}
	return ERR_NO_ERROR;
}

uint32_t labelvalue(char* label, symbols_table *sym_list)
{
	while(sym_list != NULL)
	{
		if(strcmp(sym_list->symbol,label) == 0)
			return sym_list->index;
		sym_list = sym_list->next;		
	}
	return INV_LABEL_VALUE;
}

int verify_symbols_table(symbols_table* table)
{
	symbols_table *first, *second;
	
	first = table;
	while(first != NULL){
		second = first->next;
		while(second != NULL){
			if(strcmp(first->symbol, second->symbol) == 0){
				print_error_msg(first->code_line, ERR_DUP_LABEL);
			}
			second = second->next;
		}
		first = first->next;
	}
	
	return ERR_NO_ERROR;
}
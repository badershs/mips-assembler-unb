/* -----------------------------------------------------------------------------
**  MIPS Assembler UnB - MIPS Assembler General Purpose Functions
**
**  Description: 
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** ---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#include "mips_assembler.h"

void print_error_msg(uint32_t line, uint8_t error) 
{
	if(line > 0)
		printf("Line %d:\t",line);
	
	switch(error){
		case  ERR_TK_INV:
		case  ERR_TK_REG_INV:
		case  ERR_TK_IMM_INV:
		case  ERR_TK_SYMBOL_INV:
		case  ERR_MISA_BRACKET:
		case  ERR_MISP_BRACKET:
		case  ERR_MISP_COLON:
		case  ERR_MISS_BRACKET:
		case  ERR_EXTRA_BRACKET:
		case  ERR_MANY_ARG:
		case  ERR_FEW_ARG:
		case  ERR_TYPE_ARG:
		case  ERR_MISS_INST:
		case  ERR_INV_INST:
		case  ERR_MANY_LABELS:
		case  ERR_REP_LABEL:
		case  ERR_INV_DIRECT:
		case  ERR_HELP_MENU: 
			break;
		case  ERR_NO_OUT_NAME:
		case  ERR_NO_DIR:
		case  ERR_NO_FILE: 
			printf("no input file\n");
			break;
		case  ERR_MANY_FILE:
		default: printf("ERROR CODE = %d\n", error);
	}
	
	exit(1);
}

void print_line_list(token_list* list){
	while(list != NULL){
		printf("LINE %d :\n",list->index);
		if(list->first_token != NULL)
			print_token_list(list->first_token);
		list = list->next;
	}
	return;
}

void print_token_list(token* tk){
	while(tk != NULL){
		printf("Token: type = %d, value = %d, value_s = %s\n",tk->type, tk->value, tk->value_s);
		tk = tk->next;
	}
	return;
}

void print_symbols_table(symbols_table* table){
	while(table != NULL){
		printf("SYMBOL = %s, INDEX = %d\n",table->symbol, table->index);
		table = table->next;
	}
	return;
}
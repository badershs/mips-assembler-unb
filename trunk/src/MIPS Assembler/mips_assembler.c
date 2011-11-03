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
	switch(error){
		default: printf("Line %d: ERROR: error code = %d\n",line, error);
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
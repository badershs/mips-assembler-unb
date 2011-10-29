/* ---------------------------------------------------------------------------
**  MIPS Assembler UnB - Lexical Analyzer
**
**  Description: 
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** -------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "mips_assembler.h"
#include "lexical_analyzer.h"
#include "string_man.h"

const char delim[] = " ,\n\t";
const char opr[] = ":()";

uint8_t flag_enclosed;

int lexical_analysis(FILE* file)
{
	/* Declare variables */
	int res;
	uint16_t code_count;
	uint16_t inst_count;
	char line[MAX_LINE_LEN];	
	
	string_list* line_tokens;
	token *first_token, *cur_token, *next_token;
	token_list *list, *cur_list, *next_list;
	
	code_count = 1;
	inst_count = 0;
	flag_enclosed = 0;
	
	first_token = NULL;
	list = NULL;
	
	/* Read a whole line */
	while ( fgets ( line, sizeof line, file ) != NULL ){
		
		/* Divide it in a list of strings */
		line_tokens = string_tokenizer(line, (char*)delim, (char*)opr);
		
		/* For each string verify, clasify it an generate a token */
		while(line_tokens != NULL){
			
			/* Firstly, decode special operators */
			/* Colon - If the previous token was a symbol, make it a label, 
				otherwise an error is generated */
			if(*(line_tokens->string) == ':'){
				if(cur_token == NULL)
					print_error_msg(code_count, ERR_MISP_COLON);
				else{
					if(cur_token->type == TK_SYMBOL)
						cur_token->type = TK_LABEL;
					else
						print_error_msg(code_count, ERR_MISP_COLON);
				}
			}
			
			/* Opening bracket - Check if there is a matching closing bracket. 
				If yes, remove the closing bracket from the string listand set
				the 'encapsulated' flag */
			else if(*(line_tokens->string) == '('){
				if(*(line_tokens->next->next->string) == ')'){
					if(*(line_tokens->next->string) == '$'){
						line_tokens->next->next = line_tokens->next->next->next;
						flag_enclosed = 1;
					}
					else
						print_error_msg(code_count, ERR_MISP_BRACKET);
				}
				else
					print_error_msg(code_count, ERR_MISA_BRACKET);
			}
			
			/* Isolated closing bracket - error */
			else if(*(line_tokens->string) == ')'){
				print_error_msg(code_count, ERR_MISA_BRACKET);
			}
			
			/* Normal strings */
			else{				
				/* Generate a new token */
				next_token = (token*)malloc(sizeof(token));
				
				if((res = classify_token(line_tokens->string, next_token)) != ERR_NO_ERROR)
					print_error_msg(code_count, res);
				
				/* Classify the current string */
				/* The hard part:
					classify the token and fill its fields
					*/
				/*next_token->value_s = (char*)malloc(strlen(line_tokens->string) + 1);
				strcpy(next_token->value_s, line_tokens->string);
				next_token->value = 8;
				next_token->type = TK_SYMBOL;*/
				
				/* Adding the first token of the line */
				if(first_token == NULL)
					first_token = next_token;
				
				/* Connecting the token to the last one added */
				else
					cur_token->next = next_token;
				cur_token = next_token;
			}
			
			/* Take next string */
			line_tokens = line_tokens->next;
		}
		
		if(first_token != NULL){
			next_list = (token_list*)malloc(sizeof(token_list));
			next_list->index = inst_count++;
			next_list->first_token = first_token;
			
			if(list == NULL)
				list = next_list;
			
			else
				cur_list->next = next_list;
			
			cur_list = next_list;
			first_token = NULL;			
		}		
		code_count++;
	}
	
	print_line_list(list);

	return 0;
}

int classify_token(char* tok, token* token_item)
{
	int16_t imm_value;
	int res;
	uint8_t flag_negative = 0;
	
	if(*tok == '$'){
		/*************** TEMPORARY CODE *************************/
		/* Instead of if(1) it should search in the registers table */
		/* Instead of 12 it should put the correct value of the reg */
		if(1){
			token_item->value = 12;
		/*************** TEMPORARY CODE *************************/
			
			
			if(flag_enclosed){
				token_item->type = TK_REG_ENC;
				flag_enclosed = 0;
			}
			else
				token_item->type = TK_REG;
		}
		else
			return ERR_TK_REG_INV;
		
	}
	else if(*tok == '-' || isdigit(*tok)){
		if(*tok == '-'){
			flag_negative = 1;
			strcpy(tok, tok+1);
		}
		if(*tok == '0'){
			if(strlen(tok) == 1)
				imm_value = 0;
			else{
				if(*(tok+1) == 'x' || *(tok+1) == 'X')
					res = str_to_num(tok+2, &imm_value, 16);
				else if(*(tok+1) == 'b' || *(tok+1) == 'B')
					res = str_to_num(tok+2, &imm_value, 2);
				else
					res = str_to_num(tok+1, &imm_value, 8);
			}
		}
		else{
			res = str_to_num(tok, &imm_value, 10);
		}
		
		if(res == ERR_NO_ERROR){
			if(flag_negative){
				token_item->value = -imm_value;
				flag_negative = 0;
			}
			else
				token_item->value = imm_value;
			token_item->type = TK_IMM;
		}
		else
			return ERR_TK_IMM_INV;
	}
	else{
		
		/* classify tok into INST, SYMBOL or INV */
		
		token_item->value_s = (char*)malloc(strlen(tok)+1);
		strcpy(token_item->value_s, tok);
		token_item->value = 5;
		token_item->type = TK_SYMBOL;
	}
	
	return ERR_NO_ERROR;
}

void print_line_list(token_list* list){
	token_list* cur_list = list;
	while(cur_list != NULL){
		printf("LINE %d :\n",cur_list->index);
		if(cur_list->first_token != NULL)
			print_token_list(cur_list->first_token);
		cur_list = cur_list->next;
	}
	return;
}

void print_token_list(token* token_item){
	token* tk = token_item;
	while(tk != NULL){
		printf("Token: type = %d, value = %d, value_s = %s\n",tk->type, tk->value, tk->value_s);
		tk = tk->next;
	}
	
	return;
}
	
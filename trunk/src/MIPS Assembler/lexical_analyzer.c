/* -----------------------------------------------------------------------------
**  MIPS Assembler UnB - Lexical Analyzer
**
**  Description: 
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** ---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "mips_assembler.h"
#include "lexical_analyzer.h"
#include "string_man.h"

extern const register_name reg_table[];
extern const inst_info inst_table[];

const char delim[] = " ,\n\t";
const char opr[] = ":()#";

uint8_t flag_enclosed;

int lexical_analysis(FILE* file, token_list** list)
{
	/* Declare variables */
	int res;
	uint32_t code_count;
	uint32_t inst_count;
	char line[MAX_LINE_LEN];	
	
	string_list* line_tokens;
	token *first_token, *cur_token, *next_token;
	token_list *cur_list, *next_list;
	
	code_count = 1;
	inst_count = 0;
	flag_enclosed = 0;
	
	first_token = NULL;
	*list = NULL;
	
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
				If yes, remove the closing bracket from the string list and set
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
			
			/* Sharp sign - comments */
			else if(*(line_tokens->string) == '#'){
				break;
			}
			
			/* Normal strings */
			else{				
				/* Generate a new token */
				next_token = (token*)malloc(sizeof(token));
				
				/* Analyze the string and fill token information */
				if((res = classify_token(line_tokens->string, next_token)) != ERR_NO_ERROR)
					
					/* In case of error, print the error message on screen
						OBS: It also therminates the whole process */
					print_error_msg(code_count, res);
				
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
		
		/* If the line is not empty, add it to the lines list */
		if(first_token != NULL){
			next_list = (token_list*)malloc(sizeof(token_list));
			next_list->index = inst_count;
			next_list->first_token = first_token;
			
			/* If the line has only one token inst_count is not updated since
			it should be an isolated label token */
			if(first_token->next != NULL)
				inst_count += 4;
			
			/* Adding the first line of the list */
			if(*list == NULL)
				*list = next_list;
			
			/* Connecting the line to the last one added */
			else
				cur_list->next = next_list;
			
			cur_list = next_list;
			first_token = NULL;			
		}		
		code_count++;
	}
	
	print_line_list(*list);

	return 0;
}

int classify_token(char* tok, token* token_item)
{
	int i;
	int32_t imm_value;
	char* endptr;
	
	/* Cases TK_REG and TK_REG_ENC */
	if(*tok == '$'){
		for(i = 0; i < REG_TABLE_SIZE; i++){
			if(strcmp(tok, reg_table[i].name1) == 0 || strcmp(tok, reg_table[i].name2) == 0){
				token_item->value = i;
				
				/* Case TK_REG_ENC */
				if(flag_enclosed){
					token_item->type = TK_REG_ENC;
					flag_enclosed = 0;
				}
				
				/* Case TK_REG */
				else
					token_item->type = TK_REG;
				
				return ERR_NO_ERROR;
			}
		}
		
		/* Invalid register */
		return ERR_TK_REG_INV;		
	}
	
	/* Case TK_IMM */
	else if(*tok == '-' || isdigit(*tok)){
		imm_value = strtol(tok, &endptr, 0);
		if((tok + strlen(tok) - endptr) == 0){
			token_item->value = imm_value;
			token_item->type = TK_IMM;
		}
		else
			
			/* Invalid number */
			return ERR_TK_IMM_INV;
	}
	
	/* Cases TK_INST and TK_SYMBOL */
	else{
		for(i = 0; i < INST_TABLE_SIZE; i++){
			if(strcmp(tok, inst_table[i].name) == 0){
				
				/* Case TK_INST */
				token_item->value = i;
				token_item->type = TK_INST;
				
				return ERR_NO_ERROR;
			}			
		}
		
		if(strlen(tok) <= 31){
			for(i = 0; i < strlen(tok); i++){
				if(*(tok+i) != '.' && *(tok+i) != '_' && isalnum(*(tok+i)) == 0)
					return ERR_TK_INV;
			}
			
			/* Case TK_SYMBOL */
			token_item->value_s = (char*)malloc(strlen(tok)+1);
			strcpy(token_item->value_s, tok);
			token_item->type = TK_SYMBOL;
			
			return ERR_NO_ERROR;
		}
		else
			
			/* Invalid symbol */
			return ERR_TK_SYMBOL_INV;
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
	
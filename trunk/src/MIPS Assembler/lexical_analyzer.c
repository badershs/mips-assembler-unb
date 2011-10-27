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

#define MAX_LINE_LEN 128
#define MAX_REG_LEN 5

const char token_delim[] = " ,\n\t";

int lexical_analysis(FILE*);
int classify_token(char*, token**);
void print_line_list(token_list*);
void print_token_list(token*);

int main() {
    FILE* file = fopen("Testbench.s","r");
    if(file != NULL){
	lexical_analysis(file);
	fclose(file);
    }
    else
	printf("Error opening file\n");
    return 0;
}

int lexical_analysis(FILE* file) {
    
    /* Declare variables */
    int line_count = 0;
    char line[MAX_LINE_LEN];
    char* tok;
    uint8_t error;
    
    token *cur_token, *next_token;
    token_list *list, *cur_list, *next_list;
    
    list = NULL;
    
    /* Read a whole line */
    while ( fgets ( line, sizeof line, file ) != NULL ){
	
	/* Take the first token of the line */
	tok = strtok(line, token_delim);
	
	/* If the line is not null a new line struct should be created and
	linked with the lines list */
	if(tok != NULL){
	    next_list = (token_list*)malloc(sizeof(token_list));
	    
	    /* Creating the first line structure, nothing to link with */
	    if(list == NULL){
		list = next_list;
	    }
	    
	    /* Linking with the last added line */
	    else{
		cur_list->next = next_list;
	    }
	    
	    cur_list = next_list;
	    cur_list->index = line_count++;
	    
	    /* Classifying the first token and adding it to the line */
	    if((error = classify_token(tok, &next_token)) != 0){
		printf("ERROR: %d\n", error); break;
	    }
	    
	    cur_list->first_token = next_token;
	    cur_token = next_token;
	    
	    /* Analyzing following tokens */
	    tok = strtok(NULL, token_delim);
	    while(tok != NULL){
		if((error = classify_token(tok, &next_token)) != 0){
		    printf("ERROR: %d\n", error); break;
		}
		cur_token->next = next_token;
		cur_token = next_token;
		
		tok = strtok(NULL, token_delim);
	    }
	}
    }
    
    print_line_list(list);
    
    return 0;
}

int classify_token(char* tok, token** token_item){
    char reg_tok[MAX_REG_LEN];
    uint8_t reg_enc;
    
    /* Case TK_REG  and TK_REG_ENC */
    if(*tok == '(' || *tok == '$'){
	
	/* Case TK_REG_ENC - check if brackets are aligned and copy the
	register name to reg_tok */
	if(*tok == '('){
	    if(*(tok + strlen(tok) - 2) != ')')
		return ERR_MISA_BRACKET;
	    if(*(tok + 1) != '$')
		return ERR_MISU_BRACKET;
	    if(strlen(tok) > MAX_REG_LEN + 2)
		return ERR_TK_REG_INV;
	    else {
		strncpy(reg_tok, tok+2, strlen(tok) - 3);
		reg_enc = 1;
	    }
	}
	
	/* Case TK_REG - copy the register name to reg_tok */
	else{
	    if(strlen(tok) > MAX_REG_LEN)
		return ERR_TK_REG_INV;
	    else {
		strncpy(reg_tok, tok+1, strlen(tok) - 1);
		reg_enc = 0;
	    }
	}
	
	/* CHECK THE REGISTERS TABLE
	    This table should contain a list of all existing registers and
	    a code associated to each register*/
	
	/* If reg_tok is in the table */
	if(0)
	    return ERR_TK_REG_INV;   
	
	else{
	    (*token_item) = (token*)malloc(sizeof(token));
	    (*token_item)->value_s = (char*)malloc(strlen(reg_tok)+1);
	    strcpy((*token_item)->value_s, reg_tok);
	    (*token_item)->value = 2;	/* THIS VALUE SHOULD BE TAKEN FROM THE TABLE */
	    if(reg_enc)
		(*token_item)->type = TK_REG_ENC;
	    else
		(*token_item)->type = TK_REG;
	}	    
    } 
 
    /* Case TK_IMM */
    if(*tok == '-' || isdigit(*tok)){
	
	/* Convert number in different notations (binary, octal, decimal, hexadecimal */
	
	(*token_item) = (token*)malloc(sizeof(token));
	(*token_item)->value_s = (char*)malloc(strlen(tok)+1);
	strcpy((*token_item)->value_s, tok);
	(*token_item)->value = 8;
	(*token_item)->type = TK_IMM;
    
    }
    
    /* Case TK_INST, TK_SYMBOL and TK_LABEL */
    else{
	
	
	
	
	(*token_item) = (token*)malloc(sizeof(token));
	(*token_item)->value_s = (char*)malloc(strlen(tok)+1);
	strcpy((*token_item)->value_s, tok);
	(*token_item)->value = 5;
	(*token_item)->type = TK_SYMBOL;
    }
 
    return 0;
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

/* CLASSIFYING THE TOKEN 
    - If starts with number, try to cast it to int - it should be an IMM
    - If starts with $, check on the registers table - it should be a REG
    - If starts with (, check if there is a ) at the end, and check if the 
    string between them is a register - it should be a REG_BRACKET
    - If starts with a letter, check on the instructions table - if yes it is a INST
    - If it starts with a letter but is not on the instructions table it
    should be a SYMBOL
	    check for invalid characters
    - If it is a single :, check the previous token. If it is a SYMBOL, make it
    a LABEL
    - Otherwise, ERROR */
	
	
	
	
	
	
	
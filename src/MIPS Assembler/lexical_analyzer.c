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

#include "mips_assembler.h"

#define MAX_LINE_LENGHT 128

const char token_delim[] = " ,\n";

int lexical_analysis(FILE* file);

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
    char line[MAX_LINE_LENGHT];
    char* tok;
    
    token *cur_token, *next_token;
    token_list *list, *cur_list, *next_list;
    
    /* Read a whole line */
    while ( fgets ( line, sizeof line, file ) != NULL ){
	
	/* Take the first token of the line */
	tok = strtok(line, token_delim);
	
	/* If the line is not null a new line struct should be created and
	linked with the lines list */
	if(tok != NULL){
	    next_list = (token_list*)malloc(sizeof(token_list));
	    
	    /* Creating the first line structure, nothing to link with */
	    if(list == NULL)
		list = next_list;
	    
	    /* Linking with the last added line */
	    else
		cur_list->next = next_list;
	    
	    cur_list = next_list;
	    cur_list->index = line_count++;
	    
	    /* CLASSIFY THE TOKEN:
		If it is invalid, sign an error an abort the program
		If it is valid create a new token structure and do:
		    cur_list->first_token = cur_token */
	    
	    /* DONE ANALYZING THE FIRST TOKEN - GO AHEAD TO THE NEXT */
	    
	    tok = strtok(NULL, token_delim);
	    while(tok != NULL){
		/* CLASSIFY THE TOKEN:
		    If it is invalid, sign an error an abort the program
		    If it is valid create a new token structure and do:
			cur_token->next = next_token 
			cur_token = next_token */
		
		tok = strtok(NULL, token_delim);
	    }
	    
	}
    }
    return 0;
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
	
	
	
	
	
	
	
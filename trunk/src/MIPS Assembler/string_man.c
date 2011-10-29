/* ---------------------------------------------------------------------------
**  MIPS Assembler UnB - String Manipulator
**
**  Description: 
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** -------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "string_man.h"

void print_string_list(string_list* list) 
{
    printf("Printing string list\n");
    
    while(list != NULL){
		printf("%s - ",list->string);
		list = list->next;
    }
    
    printf("\nDone!\n");
    return;
}

string_list* string_tokenizer(char* str, char* delim, char* opr)
{
    char* tok;
    string_list* list = NULL;
    string_list *cur_list, *next_list;
    
    /* Extract a token from the string str*/
	tok = strtok(str, delim);
	
	while(tok != NULL){
		
		/* For each token, create a new node and insert it in the string list*/
		next_list = (string_list*)malloc(sizeof(string_list));
		next_list->string = (char*)malloc(strlen(tok) +1);
		strcpy(next_list->string, tok);
	
		/* Adding first token to the list */
		if(list == NULL) 
			list = next_list;
		/* Connecting the token to the last token of the list */
		else 
			cur_list->next = next_list;
		
		/* Updating state variables */
		cur_list = next_list;
		tok = strtok(NULL, delim);
    }
    
	/* Call string_tokenizer_opr to expand the current list breaking nodes that
	contain "operator" characters */
    string_tokenizer_opr(&list, opr);
    
    return list;
}

int string_tokenizer_opr(string_list** plist, char* opr)
{
    int i;
	int bsize, asize;
    char* pchr;
    string_list* virtual_list;    
    string_list* cur_list;
    string_list *list_before, *list_opr, *list_after;
    
    if(*plist != NULL){
	
		/* Create a virtual node whose next is the first node of the list */
		virtual_list = (string_list*)malloc(sizeof(string_list));
		virtual_list->next = *plist;
		
		/* Set the virtual node as the first node to run the algorithm */
		cur_list = virtual_list;
	
		/* For each "operator" character, search and analyze the whole list */
		for(i = 0; i < strlen(opr); i++){
			
			while(cur_list->next != NULL){
				
				/* If the current token contains an "operator" character:
					break the string in three new tokens:*/
				if((pchr = strchr(cur_list->next->string, *(opr+i))) != NULL){
					
					bsize = pchr - cur_list->next->string;
					asize = strlen(cur_list->next->string) - (bsize+1);
					
					/* (before the "operator") */
					if(bsize > 0){
						list_before = (string_list*)malloc(sizeof(string_list));
						list_before->string = (char*)malloc(bsize+1);
						strncpy(list_before->string, cur_list->next->string, bsize);
					}
					
					/* (the "operator" itself) */
					list_opr = (string_list*)malloc(sizeof(string_list));
					list_opr->string = (char*)malloc(2);
					strncpy(list_opr->string, pchr, 1);
					
					/* (after the "operator") */
					if(pchr < cur_list->next->string + strlen(cur_list->next->string) - 1){
						list_after = (string_list*)malloc(sizeof(string_list));
						list_after->string = (char*)malloc(asize+1);
						strcpy(list_after->string, pchr+1);
					}
					
					/* Replace the current node by the newly created ones */
					if(asize > 0){
						list_after->next = cur_list->next->next;
						list_opr->next = list_after;
					}
					else{
						list_opr->next = cur_list->next->next;
					}
					if(bsize > 0){
						list_before->next = list_opr;
						cur_list->next = list_before;
					}
					else{
						cur_list->next = list_opr;
					}
					
					cur_list = list_opr;
				}
				/* Otherwise, proceed to the next token */
				else
					cur_list = cur_list->next;
			}
			cur_list = virtual_list;
		}
		
		*plist = virtual_list->next;
    }
    
    return 0;
}

int str_to_num(char* str, int16_t* num, uint8_t base)
{
	/* TBD: Convert str to num */
	
	*num = 42;
	
	return 0;
}

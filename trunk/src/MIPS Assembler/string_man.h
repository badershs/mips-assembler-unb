/* ---------------------------------------------------------------------------
**  MIPS Assembler UnB - String Manipulator
**
**  Description: Implements some string manipulation functions useful for the
**  Lexical Analyzer
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** -------------------------------------------------------------------------*/
#ifndef STRING_MAN_H
#define STRING_MAN_H

#include <stdint.h>

/* ---------------------------------------------------------------------------
**								TYPEDEFS
** -------------------------------------------------------------------------*/

/* Type: string_list
** Description: Implement a linked list where each node holds a string
** -------------------------------------------------------------------------*/
typedef struct string_list_st {
    char* string;
    struct string_list_st* next;
} string_list;

/* ---------------------------------------------------------------------------
**						  FUNCTION PROTOTYPES
** -------------------------------------------------------------------------*/

/* Function: print_string_list
** Description: Method for printing the struct string_list
** -------------------------------------------------------------------------*/
void print_string_list(string_list*);

/* Function: string_tokenizer
** Description: Method for dividing a string in tokens. The delimiter 
** characters are the ones in 'delim' and 'opr'. The characters in 'delim'
** simply separate two tokens while the ones in 'opr' are also considered
** as tokens and appear isolated in the returned token list.
** -------------------------------------------------------------------------*/
string_list* string_tokenizer(char* str, char* delim, char* opr);

/* Function: string_tokenizer_opr
** Description: Subfunction of the method string_tokenizer. Search a
** previously generated string list for "operator" characters. When an
** "operator" character is found, the string holding it is split in three.
** -------------------------------------------------------------------------*/
int string_tokenizer_opr(string_list** plist, char* opr);

/* Function: str_to_num
** Description: Method to convert a literal number (string) into a nummerical
** variable (int). The number can be in any 'base'. The result is 0 if the
** operation succeeds or -1 if the string contains invalid characters.
** -------------------------------------------------------------------------*/
int str_to_num(char* str, int16_t* num, uint8_t base);
    

#endif	/* STRING_MAN_H */
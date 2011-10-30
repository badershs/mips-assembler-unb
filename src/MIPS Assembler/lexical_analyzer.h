/* ---------------------------------------------------------------------------
**  MIPS Assembler UnB - Lexical Analyzer
**
**  Description: 
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** -------------------------------------------------------------------------*/
#ifndef LEXICAL_ANALYZER_H
#define LEXICAL_ANALYZER_H

#include "mips_assembler.h"

/* ---------------------------------------------------------------------------
**								DEFINES
** -------------------------------------------------------------------------*/
#define MAX_LINE_LEN 128
#define MAX_REG_LEN 5

/* ---------------------------------------------------------------------------
**						  FUNCTION PROTOTYPES
** -------------------------------------------------------------------------*/

/* Function:
** Description:
** -------------------------------------------------------------------------*/
int lexical_analysis(FILE* file, token_list** list);

/* Function:
** Description:
** -------------------------------------------------------------------------*/
int classify_token(char*, token*);

/* Function:
** Description:
** -------------------------------------------------------------------------*/
void print_line_list(token_list*);

/* Function:
** Description:
** -------------------------------------------------------------------------*/
void print_token_list(token*);

#endif	/* LEXICAL_ANALYZER_H */
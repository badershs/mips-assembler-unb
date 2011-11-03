/* -----------------------------------------------------------------------------
**  MIPS Assembler UnB - Lexical Analyzer
**
**  Description: 
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** ---------------------------------------------------------------------------*/
#ifndef LEXICAL_ANALYZER_H
#define LEXICAL_ANALYZER_H

#include "mips_assembler.h"

/* -----------------------------------------------------------------------------
**									DEFINES
** ---------------------------------------------------------------------------*/
#define MAX_LINE_LEN 128

/* -----------------------------------------------------------------------------
**							  FUNCTION PROTOTYPES
** ---------------------------------------------------------------------------*/

/* Function: lexical_analysis
** Description: Read the input 'file' and perform the lexical analysis. The
** content of 'file' is split into tokens according to the MIPS assembly
** language especifications and each token is classified depending on its
** structure. All the tokens from the same line are organized in linked lists.
** The parameter 'list' will point to the list of content lines, where each
** line is the list of tokens mentioned above. In the case any lexical error
** is found, the function outputs a message error and terminates the process.
** In the case this behavior is not desire, this function should be called in
** an independent process.
** ---------------------------------------------------------------------------*/
int lexical_analysis(FILE* file, token_list** list, symbols_table** s_table);

/* Function: classify_token
** Description: Works as a subfunction of lexical_analysis. Verify if 'tok' is
** a valid token and classify it in one of the following classes: register,
** label, instruction, immediate. The selected class as well as the token
** value are stored in the given 'token_item' structure.
** ---------------------------------------------------------------------------*/
int classify_token(char* tok, token* token_item);

#endif	/* LEXICAL_ANALYZER_H */
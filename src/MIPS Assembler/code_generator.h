/* -----------------------------------------------------------------------------
**  MIPS Assembler UnB - Lexical Analyzer
**
**  Description: 
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** ---------------------------------------------------------------------------*/
#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include <stdio.h>
#include <stdint.h>

#include "mips_assembler.h"

/* -----------------------------------------------------------------------------
**							  FUNCTION PROTOTYPES
** ---------------------------------------------------------------------------*/

/* Function: classify_token
** Description: Works as a subfunction of lexical_analysis. Verify if 'tok' is
** a valid token and classify it in one of the following classes: register,
** label, instruction, immediate. The selected class as well as the token
** value are stored in the given 'token_item' structure.
** ---------------------------------------------------------------------------*/
void binario (int32_t dec, char** bin);


/* Function: classify_token
** Description: Works as a subfunction of lexical_analysis. Verify if 'tok' is
** a valid token and classify it in one of the following classes: register,
** label, instruction, immediate. The selected class as well as the token
** value are stored in the given 'token_item' structure.
** ---------------------------------------------------------------------------*/
int code_generator(inst_list* i_list, FILE* output_file);

#endif /* CODE_GENERATOR_H */
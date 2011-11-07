/* -----------------------------------------------------------------------------
**  MIPS Assembler UnB - Parser
**
**  Description: 
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** ---------------------------------------------------------------------------*/
#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdint.h>

#include "mips_assembler.h"



/* -----------------------------------------------------------------------------
**						  FUNCTION PROTOTYPES
** ---------------------------------------------------------------------------*/

/* Function:
** Description:
** ---------------------------------------------------------------------------*/
int parsing(token_list*,inst_list**);

/* Function:
** Description:
** ---------------------------------------------------------------------------*/
void initialize(inst_list*);

/* Function:
** Description:
** ---------------------------------------------------------------------------*/
void includeininst(uint8_t, int32_t,inst_list**);

#endif /* PARSER_H */
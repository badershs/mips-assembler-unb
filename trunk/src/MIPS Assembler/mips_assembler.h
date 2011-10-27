/* ---------------------------------------------------------------------------
**  MIPS Assembler UnB - MIPS Assembler Declarations Header
**
**  Description: This file contains several definitions and declarations for 
**  the MIPS Assembler such as structs and constants.
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** -------------------------------------------------------------------------*/
#ifndef MIPS_H
#define MIPS_H

#include <stdint.h>

#define TK_LABEL	(0x00)	
#define TK_SYMBOL	(0x01)
#define TK_INST		(0x02)
#define TK_REG		(0x03)
#define TK_REG_BRACKET	(0x04)
#define TK_IMM		(0x05)

typedef struct token_s {
    char* value;
    uint8_t type;
    struct token_s * next;
} token;

typedef struct token_list_s {
    token* first_token;
    struct token_list_s * next;
} token_list;

#endif
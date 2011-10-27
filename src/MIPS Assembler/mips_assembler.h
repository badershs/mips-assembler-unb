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

/* ------------------------------ Token types  ----------------------------- */
#define TK_LABEL	(0x01)	
#define TK_SYMBOL	(0x02)
#define TK_INST		(0x03)
#define TK_REG		(0x04)
#define TK_REG_ENC	(0x05)
#define TK_IMM		(0x06)

/* ------------------------------ Error codes  ----------------------------- */
#define ERR_TK_INV		(0x01)
#define ERR_TK_REG_INV		(0x02)
#define ERR_MISA_BRACKET	(0x10)		/* Missaligned Brackets	     */
#define ERR_MISU_BRACKET	(0x11)		/* Misused Brackets	     */

typedef struct token_st {
    char* value_s;
    int16_t value;
    uint8_t type;
    struct token_st * next;
} token;

typedef struct token_list_st {
    uint16_t index;
    token* first_token;
    struct token_list_st * next;
} token_list;

#endif
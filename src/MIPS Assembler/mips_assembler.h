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

/* ---------------------------------------------------------------------------
**								DEFINES
** -------------------------------------------------------------------------*/

/* ------------------------------ Token types  ----------------------------- */
#define TK_LABEL	(0x01)	
#define TK_SYMBOL	(0x02)
#define TK_INST		(0x03)
#define TK_REG		(0x04)
#define TK_REG_ENC	(0x05)
#define TK_IMM		(0x06)

/* --------------------------- Instruction types --------------------------- */
#define INSTR_R		(0x01)
#define INSTR_I		(0x02)
#define INSTR_J		(0x03)

/* ------------------------------ Error codes  ----------------------------- */
#define ERR_NO_ERROR		(0x00)
#define ERR_TK_INV			(0x01)
#define ERR_TK_REG_INV		(0x02)
#define ERR_TK_IMM_INV		(0x03)
#define ERR_MISA_BRACKET	(0x10)		/* Missaligned Brackets	     */
#define ERR_MISP_BRACKET	(0x11)		/* Misplaced Brackets	     */
#define ERR_MISP_COLON		(0x12)		/* Misplaced Colon	     */

/* ---------------------------------------------------------------------------
**								TYPEDEFS
** -------------------------------------------------------------------------*/

/* Type: token
** Description: Holds a token processed by the lexical analyzer from a mips 
** assembly program. The struct has a field for the token 'type' and two fields
** for the token value (int and string). The token type determines which value
** field is going to be used. It also has a pointer to a 'token' struct so that
** a linked list can be created.
** -------------------------------------------------------------------------*/
typedef struct token_st {
    char* value_s;
    int16_t value;
    uint8_t type;
    struct token_st * next;
} token;

/* Type: token_list
** Description: Implements a linked list for holding tokens. Each node contains
** an index, a pointer to a 'token' struct and a pointer to the next node.
** OBS: Remmembering that 'token' structs can produce linked lists, this struct
** is more commonly used for generating a "list of lists of tokens".
** -------------------------------------------------------------------------*/
typedef struct token_list_st {
    uint16_t index;
    token* first_token;
    struct token_list_st * next;
} token_list;

/* Type: 
** Description: 
** -------------------------------------------------------------------------*/
typedef struct inst_st {
    uint8_t op;
    uint8_t rs;
    uint8_t rt;
    uint8_t rd;
    uint8_t shamt;
    uint8_t funct;
    uint16_t immediate;
    unsigned int address;
    struct inst_st *next;
} inst;

/* Type: 
** Description: 
** -------------------------------------------------------------------------*/
typedef struct inst_list_st {
    uint16_t index;
    uint8_t type;
    inst* first_inst;
    struct inst_list_st *next;
} inst_list;

/* ---------------------------------------------------------------------------
**						  FUNCTION PROTOTYPES
** -------------------------------------------------------------------------*/

/* Function: print_error_msg
** Description: Method for printing an error mesage to the user
** -------------------------------------------------------------------------*/
void print_error_msg(uint16_t line, uint8_t error);

#endif
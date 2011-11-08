/* -----------------------------------------------------------------------------
**  MIPS Assembler UnB - MIPS Assembler Declarations Header
**
**  Description: This file contains several definitions and declarations for 
**  the MIPS Assembler such as structs and constants.
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** ---------------------------------------------------------------------------*/
#ifndef MIPS_H
#define MIPS_H

#include <stdint.h>

#include "instructions_table.h"
#include "register_table.h"

/* -----------------------------------------------------------------------------
**									DEFINES
** ---------------------------------------------------------------------------*/

/* ------------------------------ Parameters ---------------------------------*/
#define LANGUAGE_PT_BR		1

#define MAX_SYMBOL_SIZE		(31)
#define FIRST_INST_ADD		(0x00400000)

/* ----------------------------- Token types ---------------------------------*/
#define TK_NONE		(0x00)
#define TK_LABEL	(0x01)	
#define TK_SYMBOL	(0x02)
#define TK_INST		(0x03)
#define TK_REG		(0x04)	/* TK_REG = TK_REG_X & 0x0F (mask) */
#define TK_REG_S	(0x14)
#define TK_REG_T	(0x24)
#define TK_REG_D	(0x34)
#define TK_REG_ENC	(0x05)
#define TK_IMM		(0x06)	/* TK_IMM = TK_IMM_X & 0x0F */
#define TK_IMM_5	(0x16)
#define TK_IMM_16	(0x26)
#define TK_IMM_26	(0x36)
#define TK_IMM_OPT	(0x07)
#define TK_COMMA	(0x08)
#define TK_MASK		(0x0F)

/* ------------------------------ Error codes --------------------------------*/
#define ERR_NO_ERROR			(0x00)
#define ERR_TK_INV				(0x01)
#define ERR_TK_REG_INV			(0x02)
#define ERR_TK_IMM_INV			(0x03)
#define ERR_TK_SYMBOL_INV		(0x04)
#define ERR_MISA_BRACKET		(0x10)		/* Missaligned Brackets	  	      */
#define ERR_MISP_BRACKET		(0x11)		/* Misplaced Brackets	   		  */
#define ERR_MISP_COLON			(0x12)		/* Misplaced Colon	    		  */
#define ERR_MISS_BRACKET		(0x13)		/* Missing Brackets	   			  */
#define ERR_EXTRA_BRACKET		(0x14)		/* Extra Brackets	   			  */
#define ERR_MANY_ARG			(0x20)		/* Too many arguments	 	      */
#define ERR_FEW_ARG				(0x21)		/* Too few arguments	 	      */
#define ERR_TYPE_ARG			(0x22)		/* Incorrect argument type 		  */
#define ERR_MISS_INST			(0x23)		/* Missing instruction	    	  */
#define ERR_INV_INST			(0x24)		/* Invalid instruction	    	  */
#define ERR_MANY_LABELS			(0x25)		/* Too many labels	   			  */
#define ERR_REP_LABEL			(0x26)		/* Redeclared label 			  */
#define ERR_MISS_COMMA			(0x27)		/* Missing expected comma   	  */
#define ERR_MANY_COMMA			(0x28)		/* Comma used in wrong way  	  */
#define ERR_INV_IMM				(0x30)		/* Invalid size of immediate 	  */
#define ERR_NO_LABEL			(0x31)		/* Label called nonexistent 	  */
#define ERR_DUP_LABEL			(0x32)		/* Duplicated label			 	  */
#define ERR_ZERO_REG			(0x33)		/* Register ZERO set as target 	  */
#define ERR_INV_DIRECT			(0x40)		/* Invalid directive 			  */
#define ERR_HELP_MENU			(0x41)		/* Display Help menu 			  */
#define ERR_VERSION				(0x42)		/* Display assembler's version	  */
#define ERR_ABOUT				(0x43)		/* Display assembler's version 	  */
#define ERR_NO_OUT_NAME			(0x44)		/* Absent output file name 		  */
#define ERR_NO_DIR				(0x45)		/* Absent directory 			  */
#define ERR_NO_FILE				(0x46)		/* Absent input file name		  */
#define ERR_MANY_FILE			(0x47)		/* Too many input files			  */
#define ERR_INV_FILE			(0x48)		/* Couldn't find the input file	  */
#define ERR_INV_OUT_FILE		(0x49)		/* Couldn't open the output file  */
#define ERR_ANALYZE_DONE		(0x4A)		/* Analysis has finished		  */

/* -----------------------------------------------------------------------------
**								  TYPEDEFS
** ---------------------------------------------------------------------------*/

/* Type: symbols_table
** Description: Holds an element of the symbols table. This table matches the
** labels used in the program and the corresponding instruction index. It's
** filled during the lexical analysis and used again in the semantic analysis 
** to replace the symbols by their corresponding address.
** ---------------------------------------------------------------------------*/
typedef struct symbols_table_st {
	char* symbol;
	uint32_t index;
	uint32_t code_line;
	struct symbols_table_st * next;
} symbols_table;

/* Type: token
** Description: Holds a token processed by the lexical analyzer from a mips 
** assembly program. The struct has a field for the token 'type' and two fields
** for the token value (int and string). The token type determines which value
** field is going to be used. It also has a pointer to a 'token' struct so that
** a linked list can be created.
** ---------------------------------------------------------------------------*/
typedef struct token_st {
    char* value_s;
    int32_t value;
    uint8_t type;
    struct token_st * next;
} token;

/* Type: token_list
** Description: Implements a linked list for holding tokens. Each node contains
** an index, a pointer to a 'token' struct and a pointer to the next node.
** OBS: Remmembering that 'token' structs can produce linked lists, this struct
** is more commonly used for generating a "list of lists of tokens".
** ---------------------------------------------------------------------------*/
typedef struct token_list_st {
    uint32_t index;
	uint32_t code_line;
    token* first_token;
    struct token_list_st * next;
} token_list;

/* Type: 
** Description: 
** ---------------------------------------------------------------------------*/
typedef struct {
    uint8_t op;
    uint8_t rs;
    uint8_t rt;
    uint8_t rd;
    uint8_t funct;
    int32_t imm;
    int32_t imm_rel;
    char *symbol;
} inst;

/* Type: 
** Description: 
** ---------------------------------------------------------------------------*/
typedef struct inst_list_st {
    uint32_t index;
    uint32_t code_line;
    uint8_t type;
    uint8_t stype;
    inst values;
    struct inst_list_st *next;
} inst_list;

/* -----------------------------------------------------------------------------
**						 	  FUNCTION PROTOTYPES
** ---------------------------------------------------------------------------*/

/* Function: print_error_msg
** Description: Method for printing an error mesage to the user
** ---------------------------------------------------------------------------*/
void print_error_msg(uint32_t line, uint8_t error);

/* Function: print_line_list
** Description: For debug purposes. Print a token_list structure's content
** recursively in the terminal.
** ---------------------------------------------------------------------------*/
void print_line_list(token_list*);

/* Function: print_token_list
** Description: For debug purposes. Print a token structure's content 
** recursively in the terminal.
** ---------------------------------------------------------------------------*/
void print_token_list(token*);

/* Function: print_symbols_table
** Description: For debug purposes. Print a symbols_table structure's content 
** recursively in the terminal.
** ---------------------------------------------------------------------------*/
void print_symbols_table(symbols_table*);

/* Function:
** Description:
** ---------------------------------------------------------------------------*/
void print_inst(inst_list*);

#endif
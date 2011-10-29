/* ---------------------------------------------------------------------------
**  MIPS Assembler UnB - Instructions Table
**
**  Description: 
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** -------------------------------------------------------------------------*/
#ifndef INSTRUCTIONS_TABLE_H
#define INSTRUCTIONS_TABLE_H

#include <stdint.h>

/* ---------------------------------------------------------------------------
**								DEFINES
** -------------------------------------------------------------------------*/

/* -------------------------- Parameters  --------------------------------- */
#define INST_TABLE_SIZE		(12)

/* ----------------------- Instruction Types  ----------------------------- */
#define TYPE_R		(0x01)
#define TYPE_I		(0x02)
#define TYPE_J		(0x03)

/* --------------------- Instruction SubTypes  ---------------------------- */
#define STYPE_R1	(0x00)
#define STYPE_R2	(0x01)
#define STYPE_R3	(0x02)
#define STYPE_I1	(0x03)
#define STYPE_I2	(0x04)
#define STYPE_I3	(0x05)
#define STYPE_I4	(0x06)
#define STYPE_J1	(0x07)

/* ------------------------------ Opcodes   -------------------------------- */
#define OP_ADD		(0x00)
#define OP_SUB		(0x00)
#define OP_AND		(0x00)
#define OP_OR		(0x00)
#define OP_SLL		(0x00)
#define OP_JR		(0x00)
#define OP_ADDI		(0x08)
#define OP_LW		(0x23)
#define OP_SW		(0x2b)
#define OP_BEQ		(0x04)
#define OP_J		(0x02)
#define OP_JAL		(0x07)

/* ------------------------------- Functs   -------------------------------- */
#define FN_ADD		(0x20)
#define FN_SUB		(0x22)
#define FN_AND		(0x24)
#define FN_OR		(0x25)
#define FN_SLL		(0x00)
#define FN_JR		(0x08)
#define FN_ADDI		(0x00)
#define FN_LW		(0x00)
#define FN_SW		(0x00)
#define FN_BEQ		(0x00)
#define FN_J		(0x00)
#define FN_JAL		(0x00)

/* ---------------------------------------------------------------------------
**								TYPEDEFS
** -------------------------------------------------------------------------*/

/* Type: instruction
** Description: 
** -------------------------------------------------------------------------*/
typedef struct {
    char* name;
    uint8_t type;
    uint8_t subtype;
    uint8_t opcode;
    uint8_t funct;
} instruction;

/* Type: instruction
** Description: 
** -------------------------------------------------------------------------*/
typedef struct {
	uint8_t inst_subtype;
	uint8_t compl1;
	uint8_t compl2;
	uint8_t compl3;
} grammar_rule;



#endif

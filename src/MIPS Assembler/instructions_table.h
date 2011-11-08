/* -----------------------------------------------------------------------------
**  MIPS Assembler UnB - Instructions Table
**
**  Description: MIPS' Instructions Table (limited, does not contain all MIPS
**  instructions).
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** ---------------------------------------------------------------------------*/
#ifndef INSTRUCTIONS_TABLE_H
#define INSTRUCTIONS_TABLE_H

#include <stdint.h>

/* -----------------------------------------------------------------------------
**									DEFINES
** ---------------------------------------------------------------------------*/

/* ------------------------------ Parameters  --------------------------------*/
#define INST_TABLE_SIZE		(37)
#define NB_STYPE			(14)
#define VERSION				("1.0")

/* --------------------------- Instruction Types -----------------------------*/
/*#define TYPE		(0x01)*/
#define TYPE_R		(0x01)
#define TYPE_I		(0x02)
#define TYPE_J		(0x03)

/* -------------------------- Instruction SubTypes ---------------------------*/
/*#define STYPE		(0x02) */
#define STYPE_R1	(0x00) 		/* ArithLog: 	$d , $s , $t 	*/
#define STYPE_R2	(0x01) 		/* DivMult: 	$s , $t 		*/
#define STYPE_R3	(0x02) 		/* JumpR: 	$s 		*/
#define STYPE_R4	(0x03) 		/* MoveFrom:	$d		*/
#define STYPE_R5	(0x04) 		/* Shift:	$d , $t , h5bits	*/
#define STYPE_R6	(0x05) 		/* ShiftV:	$d , $t , $s	*/
#define STYPE_R7	(0x06) 		/* System:	nothing		*/
#define STYPE_I1	(0x07) 		/* ArithLogI:	$t , $s , imm16bits	*/
#define STYPE_I2	(0x08) 		/* Branch:	$s , $t , Label	*/
#define STYPE_I3	(0x09) 		/* LoadStore:	$t , imm16 ($s)	*/
#define STYPE_I4	(0x0A) 		/* BranchZ:	$s , Label	*/
#define STYPE_I5	(0x0B) 		/* Lui:		$t , imm16	*/
#define STYPE_J1	(0x0C) 		/* Jump:	Label		*/
#define STYPE_J2	(0x0D) 		/* Trap:	Imm26		*/

/* -------------------------------- Opcodes  ---------------------------------*/
/*#define OP				(0x03)*/
#define OP_NOOP			(0x00)
#define OP_R			(0x00)
#define OP_BEQ			(0x04)
#define OP_BNE			(0x05)
#define OP_JAL			(0x03)
#define OP_ADDI			(0x08)
#define OP_ADDIU		(0x09)	
#define OP_SLTI			(0x0A)
#define OP_SLTIU		(0x0B)
#define OP_ANDI			(0x0C)
#define OP_ORI			(0x0D)
#define OP_XORI			(0x0E)
#define OP_LUI			(0x0F)
#define OP_LB			(0x20)
#define OP_LH			(0x21)
#define OP_LW			(0x23)
#define OP_LBU			(0x24)
#define OP_LHU			(0x25)
#define OP_SB			(0x28)
#define OP_SH			(0x29)
#define OP_SW			(0x2b)
#define OP_J			(0x02)

/* -------------------------------- Functs  ----------------------------------*/
/*#define FN				(0x04)*/
#define FN_NOOP			(0x00)	
#define FN_I			(0x00)	
#define FN_J			(0x00)	
#define FN_SLL			(0x00)	
#define FN_SRL			(0x02)	
#define FN_JR			(0x08)	
#define FN_ADD			(0x20)	
#define FN_SUB			(0x22)	
#define FN_AND			(0x24)	
#define FN_OR			(0x25)	
#define FN_ADDU			(0x21)	
#define FN_SUBU			(0x23)	
#define FN_NOR			(0x27)	
#define FN_SLT			(0x2A)	
#define FN_SLTU			(0x2B)	
#define FN_MULT			(0x18)	
#define FN_DIV			(0x1A)	
#define FN_MFHI			(0x10)	
#define FN_MFLO			(0x12)	

/* -----------------------------------------------------------------------------
**									TYPEDEFS
** ---------------------------------------------------------------------------*/

/* Type: instruction
** Description: 
** ---------------------------------------------------------------------------*/
typedef struct {
    char* name;
    uint8_t type;
    uint8_t subtype;
    uint8_t opcode;
    uint8_t funct;
} inst_info;

#endif	/* INSTRUCTIONS_TABLE_H */

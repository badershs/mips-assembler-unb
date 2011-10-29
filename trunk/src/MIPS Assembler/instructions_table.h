#ifndef INSTRUCTIONS_TABLE_H
#define INSTRUCTIONS_TABLE_H

#include <stdint.h>

/* INSTRUCTION TYPES */
#define TYPE		(0x01)
#define TYPE_R		(0x01)
#define TYPE_I		(0x02)
#define TYPE_J		(0x03)

/* INSTRUCTION SUBTYPES */
#define STYPE		(0x02)
#define NB_STYPE	(0x08)
#define STYPE_R1	(0x00) 	/* ArithLog: 	$d $s $t 	*/
#define STYPE_R2	(0x01) 	/* DivMult: 	$s $t 		*/
#define STYPE_R3	(0x02) 	/* JumpR: 	$s 		*/
#define STYPE_R4	(0x03)	/* MoveFrom:	$d		*/
#define STYPE_R5	(0x04)	/* Shift:	$d $t h5bits	*/
#define STYPE_R6	(0x05)	/* ShiftV:	$d $t $s	*/
#define STYPE_R7	(0x06)	/* System:	nothing		*/
#define STYPE_I1	(0x07)	/* ArithLogI:	$t $s imm16bits	*/
#define STYPE_I2	(0x08)	/* Branch:	$s $t Label	*/
#define STYPE_I3	(0x09)	/* LoadStore:	$t imm16 ($s)	*/
#define STYPE_I4	(0x0A)	/* BranchZ:	$s Label	*/
#define STYPE_I5	(0x0B)	/* Lui:		$t imm16	*/
#define STYPE_J1	(0x0C)	/* Jump:	Label		*/
#define STYPE_J2	(0x0D)	/* Trap:	Imm26		*/

/* OPCODES */
#define OP		(0x03)
#define OP_ADD		(0x00)
#define OP_SUB		(0x00)
#define OP_AND		(0x00)
#define OP_OR		(0x00)
#define OP_ADDI		(0x08)
#define OP_LW		(0x23)
#define OP_SW		(0x1)
#define OP_BEQ		(0x04)
#define OP_J		(0x02)
#define OP_JR		(0x00)
#define OP_JAL		(0x7)

/* FUNCTS */
#define FN		(0x04)
#define FN_ADD		(0x20)
#define FN_SUB		(0x2)
#define FN_AND		(0x3)
#define FN_OR		(0x4)
#define FN_ADDI		(0x00)
#define FN_LW		(0x00)
#define FN_SW		(0x00)
#define FN_BEQ		(0x00)
#define FN_J		(0x00)
#define FN_JR		(0x5)
#define FN_JAL		(0x00)

typedef struct {
    char* name;
    uint8_t type;
    uint8_t subtype;
    uint8_t opcode;
    uint8_t funct;
} instruction;

typedef struct inst_order_st {
    uint8_t n;
    uint8_t *list;
} inst_order;

#endif

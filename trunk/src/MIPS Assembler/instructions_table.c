/* -----------------------------------------------------------------------------
**  MIPS Assembler UnB - Instructions Table
**
**  Description: 
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** ---------------------------------------------------------------------------*/

#include "instructions_table.h"
#include "mips_assembler.h"

const inst_info inst_table[] = { 
	{"add",			TYPE_R,		STYPE_R1,	OP_R,			FN_ADD},
	{"sub",			TYPE_R,		STYPE_R1,	OP_R,			FN_SUB},
	{"and",			TYPE_R,		STYPE_R1,	OP_R,			FN_AND},
	{"or",			TYPE_R,		STYPE_R1,	OP_R,			FN_OR},	
	{"addu",		TYPE_R,		STYPE_R1,	OP_R,			FN_ADDU},
	{"subu",		TYPE_R,		STYPE_R1,	OP_R,			FN_SUBU},
	{"nor",			TYPE_R,		STYPE_R1,	OP_R,			FN_NOR},
	{"slt",			TYPE_R,		STYPE_R1,	OP_R,			FN_SLT},
	{"sltu",		TYPE_R,		STYPE_R1,	OP_R,			FN_SLTU},
	{"mult",		TYPE_R,		STYPE_R2,	OP_R,			FN_MULT},
	{"div",			TYPE_R,		STYPE_R2,	OP_R,			FN_DIV},
	{"jr",			TYPE_R,		STYPE_R3,	OP_R,			FN_JR},
	{"mfhi",		TYPE_R,		STYPE_R4,	OP_R,			FN_MFHI},
	{"mflo",		TYPE_R,		STYPE_R4,	OP_R,			FN_MFLO},
	{"srl",			TYPE_R,		STYPE_R5,	OP_R,			FN_SRL},
	{"sll",			TYPE_R,		STYPE_R5,	OP_R,			FN_SLL},
	{"noop",		TYPE_R,		STYPE_R7,	OP_R,			FN_NOOP},
	
	{"addi",		TYPE_I,		STYPE_I1,	OP_ADDI,		FN_I},
	{"addiu",		TYPE_I,		STYPE_I1,	OP_ADDIU,		FN_I},
	{"andi",		TYPE_I,		STYPE_I1,	OP_ANDI,		FN_I},
	{"ori",			TYPE_I,		STYPE_I1,	OP_ORI,			FN_I},
	{"xori",		TYPE_I,		STYPE_I1,	OP_XORI,		FN_I},
	{"slti",		TYPE_I,		STYPE_I1,	OP_SLTI,		FN_I},
	{"sltiu",		TYPE_I,		STYPE_I1,	OP_SLTIU,		FN_I},
	{"beq",			TYPE_I,		STYPE_I2,	OP_BEQ,			FN_I},
	{"bne",			TYPE_I,		STYPE_I2,	OP_BNE,			FN_I},
	{"lw",			TYPE_I,		STYPE_I3,	OP_LW,			FN_I},
	{"sw",			TYPE_I,		STYPE_I3,	OP_SW,			FN_I},
	{"lb",			TYPE_I,		STYPE_I3,	OP_LB,			FN_I},
	{"sb",			TYPE_I,		STYPE_I3,	OP_SB,			FN_I},
	{"lh",			TYPE_I,		STYPE_I3,	OP_LH,			FN_I},
	{"sh",			TYPE_I,		STYPE_I3,	OP_SH,			FN_I},
	{"lbu",			TYPE_I,		STYPE_I3,	OP_LBU,			FN_I},
	{"lhu",			TYPE_I,		STYPE_I3,	OP_LHU,			FN_I},
	{"lui",			TYPE_I,		STYPE_I5,	OP_LUI,			FN_I},
	
	{"j",			TYPE_J,		STYPE_J1,	OP_J,			FN_J},
	{"jal",			TYPE_J,		STYPE_J1,	OP_JAL,			FN_J},
};

const uint8_t sintaxe[NB_STYPE][5]={
	{TK_REG_D,		TK_COMMA,	TK_REG_S,		TK_COMMA,	TK_REG_T},
	{TK_REG_S,		TK_COMMA,	TK_REG_T,		TK_NONE,	TK_NONE},
	{TK_REG_S,		TK_NONE,	TK_NONE,		TK_NONE,	TK_NONE},
	{TK_REG_D,		TK_NONE,	TK_NONE,		TK_NONE,	TK_NONE},
	{TK_REG_D,		TK_COMMA,	TK_REG_T,		TK_COMMA,	TK_IMM_5},
	{TK_REG_D,		TK_COMMA,	TK_REG_T,		TK_COMMA,	TK_REG_S},
	{TK_NONE,		TK_NONE,	TK_NONE,		TK_NONE,	TK_NONE},
	{TK_REG_T,		TK_COMMA,	TK_REG_S,		TK_COMMA,	TK_IMM_16},
	{TK_REG_S,		TK_COMMA,	TK_REG_T,		TK_COMMA,	TK_SYMBOL},
	{TK_REG_S,		TK_COMMA,	TK_IMM_16,		TK_REG_ENC,	TK_NONE},
	{TK_REG_S,		TK_COMMA,	TK_SYMBOL,		TK_NONE,	TK_NONE},
	{TK_REG_T,		TK_COMMA,	TK_IMM_16,		TK_NONE,	TK_NONE},
	{TK_SYMBOL,		TK_NONE,	TK_NONE,		TK_NONE,	TK_NONE},
	{TK_IMM_26,		TK_NONE,	TK_NONE,		TK_NONE,	TK_NONE}
};
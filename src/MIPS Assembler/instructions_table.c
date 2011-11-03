#include "instructions_table.h"
#include "mips_assembler.h"
#include <stdint.h>

const inst_info inst_table[] = { 
	{"noop",		TYPE_R,		STYPE_R7,	OP_R,			FN_NOOP},
	{"add",			TYPE_R,		STYPE_R1,	OP_R,			FN_ADD},
	{"sub",			TYPE_R,		STYPE_R1,	OP_R,			FN_SUB},
	{"and",			TYPE_R,		STYPE_R1,	OP_R,			FN_AND},
	{"or",			TYPE_R,		STYPE_R1,	OP_R,			FN_OR},
	{"sll",			TYPE_R,		STYPE_R2,	OP_R,			FN_SLL},
	{"jr",			TYPE_R,		STYPE_R3,	OP_R,			FN_JR},
	{"addi",		TYPE_I,		STYPE_I1,	OP_ADDI,		FN_ADDI},
	{"lw",			TYPE_I,		STYPE_I3,	OP_LW,			FN_LW},
	{"sw",			TYPE_I,		STYPE_I3,	OP_SW,			FN_SW},
	{"beq",			TYPE_I,		STYPE_I2,	OP_BEQ,			FN_BEQ},
	{"j",			TYPE_J,		STYPE_J1,	OP_J,			FN_J},
	{"jal",			TYPE_J,		STYPE_J1,	OP_JAL,			FN_JAL},
	{"addu",		TYPE_R,		STYPE_R1,	OP_R,			FN_ADDU},
	{"subu",		TYPE_R,		STYPE_R1,	OP_R,			FN_SUBU},
	{"nor",			TYPE_R,		STYPE_R1,	OP_R,			FN_NOR},
	{"srl",			TYPE_R,		STYPE_R2,	OP_R,			FN_SRL},
	{"slt",			TYPE_R,		STYPE_R1,	OP_R,			FN_SLT},
	{"sltu",		TYPE_R,		STYPE_R1,	OP_R,			FN_SLTU},
	{"addiu",		TYPE_I,		STYPE_I1,	OP_ADDIU,		FN_ADDIU},
	{"andi",		TYPE_I,		STYPE_I1,	OP_ANDI,		FN_ANDI},
	{"ori",			TYPE_I,		STYPE_I1,	OP_ORI,			FN_ORI},
	{"bne",			TYPE_I,		STYPE_I3,	OP_BNE,			FN_BNE},
	{"slti",		TYPE_I,		STYPE_I1,	OP_SLTI,		FN_SLTI},
	{"sltiu",		TYPE_I,		STYPE_I1,	OP_SLTIU,		FN_SLTIU},
	{"lui",			TYPE_I,		STYPE_I4,	OP_LUI,			FN_LUI},
	{"lb",			TYPE_I,		STYPE_I2,	OP_LB,			FN_LB},
	{"lh",			TYPE_I,		STYPE_I2,	OP_LH,			FN_LH},
	{"sb",			TYPE_I,		STYPE_I2,	OP_SB,			FN_SB},
	{"sh",			TYPE_I,		STYPE_I2,	OP_SH,			FN_SH},
};

const uint8_t sintaxe[NB_STYPE][3]={
	{TK_REG_D,		TK_REG_S,		TK_REG_T},
	{TK_REG_S,		TK_REG_T,		TK_NONE},
	{TK_REG_S,		TK_NONE,		TK_NONE},
	{TK_REG_D,		TK_NONE,		TK_NONE},
	{TK_REG_D,		TK_REG_T,		TK_IMM_5},
	{TK_REG_D,		TK_REG_T,		TK_REG_S},
	{TK_NONE,		TK_NONE,		TK_NONE},
	{TK_REG_T,		TK_REG_S,		TK_IMM_16},
	{TK_REG_S,		TK_REG_T,		TK_SYMBOL},
	{TK_REG_S,		TK_IMM_16,		TK_REG_ENC},
	{TK_REG_S,		TK_SYMBOL,		TK_NONE},
	{TK_REG_T,		TK_IMM_16,		TK_NONE},
	{TK_SYMBOL,		TK_NONE,		TK_NONE},
	{TK_IMM_26,		TK_NONE,		TK_NONE}
};
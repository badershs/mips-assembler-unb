#include "instructions_table.h"
#include "mips_assembler.h"


const instruction inst_table[] = { 
    {"add",		TYPE_R,		STYPE_R1,	OP_ADD,		FN_ADD},
    {"sub",		TYPE_R,		STYPE_R1,	OP_SUB,		FN_SUB},
    {"and",		TYPE_R,		STYPE_R1,	OP_AND,		FN_AND},
    {"or",		TYPE_R,		STYPE_R1,	OP_OR,		FN_OR},
	{"sll",		TYPE_R,		STYPE_R2,	OP_SLL,		FN_SLL},
	{"jr",		TYPE_R,		STYPE_R3,	OP_JR,		FN_JR},
	{"addi",	TYPE_I,		STYPE_I1,	OP_ADDI,	FN_ADDI},
    {"lw",		TYPE_I,		STYPE_I2,	OP_LW,		FN_LW},
    {"sw",		TYPE_I,		STYPE_I2,	OP_SW,		FN_SW},
    {"beq",		TYPE_I,		STYPE_I3,	OP_BEQ,		FN_BEQ},
    {"j",		TYPE_J,		STYPE_J1,	OP_J,		FN_J},
    {"jal",		TYPE_J,		STYPE_J1,	OP_JAL,		FN_JAL}
};

const grammar_rule grammar[] = {
	{STYPE_R1,		TK_REG,			TK_REG,			TK_REG},
	{STYPE_R2,		TK_REG,			TK_REG,			TK_IMM},
	{STYPE_R3,		TK_REG,			TK_NONE,		TK_NONE},
	{STYPE_I1,		TK_REG,			TK_REG,			TK_IMM},
	{STYPE_I2,		TK_REG,			TK_IMM_OPT,		TK_REG_ENC},
	{STYPE_I3,		TK_REG,			TK_REG,			TK_SYMBOL},
	{STYPE_I4,		TK_REG,			TK_IMM,			TK_NONE},
	{STYPE_J1,		TK_SYMBOL,		TK_NONE,		TK_NONE}
};
#include "instructions_table.h"

const instruction inst_table[] = { 
    {"add",		TYPE_R,		STYPE_R1,	OP_ADD,		FN_ADD},
    {"sub",		TYPE_R,		STYPE_R1,	OP_SUB,		FN_SUB},
    {"and",		TYPE_R,		STYPE_R1,	OP_AND,		FN_AND},
    {"or",		TYPE_R,		STYPE_R1,	OP_OR,		FN_OR},
    {"addi",	TYPE_I,		STYPE_I1,	OP_ADDI,	FN_ADDI},
    {"lw",		TYPE_I,		STYPE_I3,	OP_LW,		FN_LW},
    {"sw",		TYPE_I,		STYPE_I3,	OP_SW,		FN_SW},
    {"beq",		TYPE_I,		STYPE_I2,	OP_BEQ,		FN_BEQ},
    {"j",		TYPE_J,		STYPE_J1,	OP_J,		FN_J},
    {"jr",		TYPE_R,		STYPE_R3,	OP_JR,		FN_JR},
    {"jal",		TYPE_J,		STYPE_J2,	OP_JAL,		FN_JAL}
};

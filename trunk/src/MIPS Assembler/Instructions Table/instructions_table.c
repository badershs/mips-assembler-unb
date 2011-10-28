#include "instructions_table.h"

const instruction inst_table[] = { 
    {"add",	TYPE_R,		STYPE_R1,	OP_ADD,		FN_ADD},
    {"addi",	TYPE_I,		STYPE_I1,	OP_ADDI,	FN_ADDI},
    {"beq",	TYPE_I,		STYPE_I2,	OP_BEQ,		FN_BEQ},
    {"lw",	TYPE_I,		STYPE_I3,	OP_LW,		FN_LW},
    {"j",	TYPE_J,		STYPE_J1,	OP_J,		FN_J}
};
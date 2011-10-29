#include "instructions_table.h"
#include "mips_assembler.h"


const instruction inst_table[] = { 
    {"add",	TYPE_R,		STYPE_R1,	OP_ADD,		FN_ADD},
    {"sub",	TYPE_R,		STYPE_R1,	OP_SUB,		FN_SUB},
    {"and",	TYPE_R,		STYPE_R1,	OP_AND,		FN_AND},
    {"or",	TYPE_R,		STYPE_R1,	OP_OR,		FN_OR},
    {"addi",	TYPE_I,		STYPE_I1,	OP_ADDI,	FN_ADDI},
    {"lw",	TYPE_I,		STYPE_I3,	OP_LW,		FN_LW},
    {"sw",	TYPE_I,		STYPE_I3,	OP_SW,		FN_SW},
    {"beq",	TYPE_I,		STYPE_I2,	OP_BEQ,		FN_BEQ},
    {"j",	TYPE_J,		STYPE_J1,	OP_J,		FN_J},
    {"jr",	TYPE_R,		STYPE_R3,	OP_JR,		FN_JR},
    {"jal",	TYPE_J,		STYPE_J2,	OP_JAL,		FN_JAL}
};

/* This part concerns to create a table of all the rules (grammar) of each one of the NB_STYPE subtypes of instructions */
int i;
inst_order inst_order_table[NB_STYPE];

    /* STYPE_R1 */
    inst_order_table[STYPE_R1].n=3;
    inst_order_table[STYPE_R1].list=(uint8_t*)malloc(inst_order_table[STYPE_R1].n*sizeof(uint8_t));
    inst_order_table[STYPE_R1].list[0]=TK_REG;
    inst_order_table[STYPE_R1].list[1]=TK_REG;
    inst_order_table[STYPE_R1].list[2]=TK_REG;
    /* STYPE_R3 */
    inst_order_table[STYPE_R2].n=1;
    inst_order_table[STYPE_R2]={TK_REG};
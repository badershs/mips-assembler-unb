#include "instructions_table.h"
#include "mips_assembler.h"
#include <stdint.h>


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

/* This part concerns to create a table of all the rules (grammar) of each one of the NB_STYPE subtypes of instructions */
const uint8_t sintaxe[NB_STYPE][3]={
	{TK_REG_D,TK_REG_S,TK_REG_T},
	{TK_REG_S,TK_REG_T,TK_NONE},
	{TK_REG_S,TK_NONE,TK_NONE},
	{TK_REG_D,TK_NONE,TK_NONE},
	{TK_REG_D,TK_REG_T,TK_IMM_5},
	{TK_REG_D,TK_REG_T,TK_REG_S},
	{TK_NONE,TK_NONE,TK_NONE},
	{TK_REG_T,TK_REG_S,TK_IMM_16},
	{TK_REG_S,TK_REG_T,TK_SYMBOL},
	{TK_REG_S,TK_IMM_16,TK_REG_ENC},
	{TK_REG_S,TK_SYMBOL,TK_NONE},
	{TK_REG_T,TK_IMM,TK_NONE},
	{TK_SYMBOL,TK_NONE,TK_NONE},
	{TK_IMM_26,TK_NONE,TK_NONE}
};

    /* STYPE_R1 */
    /*inst_order[STYPE_R1]={TK_REG,TK_REG,TK_REG};*/
    /*inst_order[STYPE_R1][0]=TK_REG;*/

    /*inst_order_table[STYPE_R1].n=3;
    inst_order_table[STYPE_R1].list=(uint8_t*)malloc(inst_order_table[STYPE_R1].n*sizeof(uint8_t));
    inst_order_table[STYPE_R1].list[0]=TK_REG;
    inst_order_table[STYPE_R1].list[1]=TK_REG;
    inst_order_table[STYPE_R1].list[2]=TK_REG;*/
    /* STYPE_R3 */
   /* inst_order[STYPE_R3]={TK_REG,NULL,NULL};*/
    /*inst_order_table[STYPE_R2].n=1;
    inst_order_table[STYPE_R2]={TK_REG};*/
    /*inst_order[STYPE_I1]={TK_REG,TK_REG,TK_IMM};
    inst_order[STYPE_I2]={TK_REG,TK_REG,TK_SYMBOL};
    inst_order[STYPE_I3]={TK_REG,TK_IMM;TK_REG};
    inst_order{STYPE_J1]={TK_SYMBOL,NULL,NULL};*/
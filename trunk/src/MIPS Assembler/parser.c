/* -----------------------------------------------------------------------------
**  MIPS Assembler UnB - Parser
**
**  Description: 
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** ---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#include "instructions_table.h"
#include "mips_assembler.h"
#include "parser.h"
#include "lexical_analyzer.h"

extern const inst_info inst_table[];
extern const uint8_t sintaxe[NB_STYPE][5];
/*http://www.student.cs.uwaterloo.ca/~isg/res/mips/opcodes*/

int parsing(token_list* tk_list, inst_list** il_out) /* input, output ; returns error signal*/
{
	int i,instruction;	/* The flag Instruction tells whether the current line of tokens contains an instruction*/
	uint8_t code_inst, code_sint;
	uint32_t line;
	token *tok;
	token_list* cur_tk_list;
	inst_list* first_inst, *cur_inst, *next_inst;

	/* Initializing variables */
	first_inst = NULL;
	cur_tk_list = tk_list;
	next_inst = (inst_list*)malloc(sizeof(inst_list));
	initialize(next_inst);
	
	while(cur_tk_list != NULL)
	{
		/* Beginnng of the analysis: LABEL and missing instruction*/
		next_inst->index = cur_tk_list->index;
		next_inst->code_line = cur_tk_list->code_line;
		line = next_inst->code_line;

		instruction=1;
		tok = cur_tk_list->first_token;
		if(tok->type==TK_LABEL )
		{
			if(tok->next!=NULL )
			{
				tok = tok->next;
				if(tok->next->type==TK_LABEL ){
					print_error_msg(line, ERR_MANY_LABELS);
				}
			} 
			else 
				instruction=0;
		}
    
		if(instruction)
		{
			/* Now the token must be a valid instruction. Beginning of the constructions of instruction struct, with the use of the instruction table*/
			if( tok->type==TK_SYMBOL )
				print_error_msg(line, ERR_INV_INST);
			else if( tok->type!=TK_INST )
				print_error_msg(line, ERR_MISS_INST);
			else 
				code_inst=tok->value;
			
			code_sint=inst_table[code_inst].subtype;
			next_inst->type = inst_table[code_inst].type;
			next_inst->stype=code_sint;
			next_inst->values.op = inst_table[code_inst].opcode;
			next_inst->values.funct = inst_table[code_inst].funct;

			/* Treatment of the attributes: REG, REG_ENC, IMM, SYMBOL; using the sintaxe table */
			for( i=0; i<5 ; i++ )
			{
				if((sintaxe[code_sint][i]==TK_NONE) && (tok->next!=NULL))
					print_error_msg(line, ERR_MANY_ARG);
				if((sintaxe[code_sint][i]!=TK_NONE) && (tok->next==NULL))
					print_error_msg(line, ERR_FEW_ARG);
				if((sintaxe[code_sint][i]==TK_NONE) && (tok->next==NULL) )
					break;
				tok=tok->next;
				
				if( (sintaxe[code_sint][i] & TK_MASK) != tok->type ) 
				{ 
					if( ((sintaxe[code_sint][i] & TK_MASK)==TK_REG) && tok->type==TK_REG_ENC )
						print_error_msg(line, ERR_EXTRA_BRACKET);
					else if( ((sintaxe[code_sint][i] & TK_MASK)==TK_REG_ENC) && tok->type==TK_REG )
						print_error_msg(line, ERR_MISS_BRACKET);
					else if( (sintaxe[code_sint][i]==TK_COMMA) && (tok->type!=TK_COMMA) )
						print_error_msg(line, ERR_MISS_COMMA);
					else if( (sintaxe[code_sint][i]!=TK_COMMA) && (tok->type==TK_COMMA) )
						print_error_msg(line, ERR_MANY_COMMA);
					else 
						print_error_msg(line, ERR_TYPE_ARG);
				}
					
				if( (tok->type!=TK_SYMBOL)&&(tok->type!=TK_COMMA) ) { 
					includeininst(sintaxe[code_sint][i],tok->value,&next_inst); 
				}
				else if( tok->type==TK_SYMBOL ) { next_inst->values.symbol=tok->value_s;}
			}
		
			if(first_inst == NULL)
				first_inst = next_inst;
			else
				cur_inst->next = next_inst;
			cur_inst = next_inst;
			
			next_inst = (inst_list*)malloc(sizeof(inst_list));
			initialize(next_inst);
		}
		cur_tk_list=cur_tk_list->next;
	}
	*il_out = first_inst;

	return ERR_NO_ERROR;
}

void initialize(inst_list *il)
{
  il->next=NULL;
  il->values.op=il->values.rs=il->values.rt=il->values.rd=il->values.funct=0;
  il->values.imm=0;
  return;
}

void includeininst(uint8_t arg_type, int32_t value, inst_list** il)
{
  switch(arg_type){
      case(TK_REG_D):	(*il)->values.rd=(uint8_t)value; 		break;
      case(TK_REG_S):
      case(TK_REG_ENC): (*il)->values.rs=(uint8_t)value; 		break;
      case(TK_REG_T):	(*il)->values.rt=(uint8_t)value; 		break;
      case(TK_IMM_16):
      case(TK_IMM_26):	
      case(TK_IMM_5):	(*il)->values.imm=(int32_t)value;		break;
  }
  return;
}
		
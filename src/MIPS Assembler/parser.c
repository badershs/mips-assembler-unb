/* ---------------------------------------------------------------------------
**  MIPS Assembler UnB - Parser
**
**  Description: 
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** -------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

#include "instructions_table.h"
#include "mips_assembler.h"
#include "parser.h"
#include "lexical_analyzer.h"

extern const inst_info inst_table[];
extern const uint8_t sintaxe[NB_STYPE][3];
/*http://www.student.cs.uwaterloo.ca/~isg/res/mips/opcodes*/


int parsing(token_list* tk_list,inst_list** il_out) /* input, output ; returns error signal*/
{
  token_list* cur_tk_list;
  token *tok;
  inst_list* first_instr, *cur_instr;

  int i,f=1;
  uint8_t code_inst, code_sint;

  /* Inicialization of the lists of tokens and instructions */
  first_instr=(inst_list*)malloc(sizeof(inst_list));
  first_instr->next=NULL;
  cur_tk_list=tk_list;
  cur_instr=first_instr;

  while(f)
  {
      printf("\nLine %3d (index)",cur_tk_list->index);
      /* Beginnng of the analysis: LABEL and missing instruction*/
      cur_instr->index=cur_tk_list->index;
      tok=cur_tk_list->first_token;
      if( tok->type==TK_LABEL )
      {
	  if( tok->next!=NULL )
	  {
	      tok=tok->next;
	      if( tok->next->type==TK_LABEL )
		  return ERR_MANY_LABELS;
	  } 
	  else 
	  { 
	      tok->next=(token*)malloc(sizeof(token));
	      tok=tok->next;
	      tok->type=TK_INST;
	      tok->value=0;
	      tok->next=NULL;
	  }
      }
      printf("\nPASS the label test");

      /* Now the token must be a valid instruction. Beginning of the constructions of instruction struct, with the use of the instruction table*/
      if( tok->type==TK_SYMBOL ) { return ERR_INV_INST; }
      else if( tok->type!=TK_INST ) { return ERR_MISS_INST; }
      else { code_inst=tok->value; }
      printf("\nPASS the instruction test");
      cur_instr->type=inst_table[code_inst].type;
      cur_instr->values.op=inst_table[code_inst].opcode;
      if( cur_instr->type==TYPE_R )
	  cur_instr->values.funct=inst_table[code_inst].funct;
      code_sint=inst_table[code_inst].subtype;

      if( code_sint==STYPE_I4 )
      {
	  /* DEFINIR AS CONSTANTES EM RT PARA AS INSTRUÇÕES DE SUBTIPO I4 (BRANCHZ) */
      }

      /* Treatment of the attributes: REG, REG_ENC, IMM, SYMBOL; using the sintaxe table */
      for( i=0; i<3 ; i++ )
      {
	  if( (sintaxe[code_sint][i]==TK_NONE)&&(tok->next!=NULL) ) { return ERR_MANY_ARG; }
	  if( (sintaxe[code_sint][i]!=TK_NONE)&&(tok->next==NULL) ) { return ERR_FEW_ARG; }
	  if( (sintaxe[code_sint][i]==TK_NONE)&&(tok->next==NULL) ) { break; }
	  tok=tok->next;
	  if( (sintaxe[code_sint][i] & TK_MASK)!=tok->type ) 
	  { 
	      if( ((sintaxe[code_sint][i] & TK_MASK)==TK_REG) && tok->type==TK_REG_ENC ) { return ERR_EXTRA_BRACKET; }
	      else if( ((sintaxe[code_sint][i] & TK_MASK)==TK_REG_ENC) && tok->type==TK_REG ) { return ERR_MISS_BRACKET; }
	      else { return ERR_TYPE_ARG; }
	  }
	  if( tok->type!=TK_SYMBOL ) { includeininst(sintaxe[code_sint][i],tok->value,&cur_instr); }
	  else { cur_instr->values.symbol=tok->value_s;/*includesymbol(tok->value_s,) PARA INSERIR O VALOR DEVIDO AO SIMBOLO*/ }  
      }
 
      /* Preparation for the next line */
      printinst(cur_instr);
      if( cur_tk_list->next !=NULL )
      {
	  cur_tk_list=cur_tk_list->next;
	  cur_instr->next=(inst_list*)malloc(sizeof(inst_list));
	  cur_instr=cur_instr->next;
	  initialize(cur_instr);

	 
      }
      else{ f=0; }
  }

  il_out=&first_instr;

  return ERR_NO_ERROR;
}

void printinst(inst_list *il)
{
  printf("\nIndex: %3d",il->index);
  printf("\nType: %3d",il->type);
  printf("\nValues:\top = %3d\n\trs = %3d\n\trt = %3d\n\trd = %3d\n\tshamt = %3d\n\tfunct = %3d\n\timm = %d",
	 il->values.op,il->values.rs,il->values.rt,il->values.rd,il->values.shamt,il->values.funct,il->values.imm);
  return;
}

void initialize(inst_list *il)
{
  il->next=NULL;
  il->values.op=il->values.rs=il->values.rt=il->values.rd=il->values.shamt=il->values.funct=0;
  il->values.imm=0;
  return;
}

void includeininst(uint8_t arg_type, int32_t value,inst_list** il)
{
  switch(arg_type){
      case(TK_REG_D):	(*il)->values.rd=(uint8_t)value; 		break;
      case(TK_REG_S):
      case(TK_REG_ENC): (*il)->values.rs=(uint8_t)value; 		break;
      case(TK_REG_T):	(*il)->values.rt=(uint8_t)value; 		break;
      case(TK_IMM_16):
      case(TK_IMM_26):	(*il)->values.imm=value; 			break;
      case(TK_IMM_5):	(*il)->values.shamt=(uint8_t)value;		break;
  }
  return;
}
/* -----------------------------------------------------------------------------
**  MIPS Assembler UnB - MIPS Assembler General Purpose Functions
**
**  Description: 
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** ---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#include "mips_assembler.h"

#define SIZE_HELP_MENU	13

extern char* g_input_file_name;

#ifdef LANGUAGE_PT_BR
const char *help_menu[] = {
	"Sintaxe: gmag [opcoes] arquivo...",
	"Montador MIPS GMAG - GNU GPL v3",
	"",
	"Opcoes:",
	"  -o <arquivo>		Seleciona <arquivo> como o arquivo de saida",
	"  -B <diretorio>	Adiciona o <diretorio> ao caminho de busca do montador",
	"  -b			Gera o arquivo de saida em formato binario",
	"  -t			Gera o arquivo de saida em formato texto binario",
	"  -A			Executa apenas a analise; nao faz a montagem",	
	"  -Wall			Exibir mensagens de aviso",
	"  --help		Exibir este menu e encerrar execucao",
	"  --version		Exibir versao do montador",
	"  --about		Exibir informacoes autorais"
};

void print_error_msg(uint32_t line, uint8_t error) 
{
	int i;
	
	if(line > 0)
		printf("gmag: %s.%d: ",g_input_file_name, line);
	
	switch(error){
		case  ERR_TK_INV:
			printf("Erro lexico -> token invalido\n");
			break;
		case  ERR_TK_REG_INV:
			printf("Erro lexico -> registrador invalido\n");
			break;
		case  ERR_TK_IMM_INV:
			printf("Erro lexico -> imediato invalido\n");
			break;
		case  ERR_TK_SYMBOL_INV:
			printf("Erro lexico -> símbolo invalido\n");
			break;
		case  ERR_MISA_BRACKET:
			printf("Erro sintatico -> parenteses desalinhados\n");
			break;
		case  ERR_MISP_BRACKET:
			printf("Erro sintatico -> parenteses sobrando\n");
			break;
		case  ERR_MISP_COLON:
			printf("Erro lexico -> caractere ':' fora de rótulo\n");
			break;
		case  ERR_MISS_BRACKET:
			printf("Erro sintatico -> parenteses faltano\n");
			break;
		case  ERR_EXTRA_BRACKET:
			printf("Erro sintatico -> parenteses sobrando\n");
			break;
		case  ERR_MANY_ARG:
			printf("Erro sintatico -> argumentos sobrando\n");
			break;
		case  ERR_FEW_ARG:
			printf("Erro sintatico -> argumentos faltando\n");
			break;
		case  ERR_TYPE_ARG:
			printf("Erro sintatico -> argumento de tipo incorreto\n");
			break;
		case  ERR_MISS_INST:
			printf("Erro sintatico -> instrucao faltando\n");
			break;
		case  ERR_INV_INST:
			printf("Erro sintatico -> instrucao invalida\n");
			break;
		case  ERR_MANY_LABELS:
			printf("Erro sintatico -> rotulos demais\n");
			break;
		case  ERR_REP_LABEL:
			printf("Erro semantico -> rotulo re-declarado\n");
			break;
		case  ERR_INV_DIRECT:
			printf("gmag: opcao desconhecida\n");
			printf("      Para informacoes sobre diretivas, digite './gmag --help'\n");
			break;
		case  ERR_HELP_MENU: 
			for(i = 0; i < SIZE_HELP_MENU; i++)
				printf("%s\n",help_menu[i]);
			break;
		case ERR_VERSION:
			printf("%s\n",VERSION);
			break;
		case ERR_ABOUT:
			printf("desenvolvido por Geraldes, A.A.; Melo, N.C.; Gouveia, D.C.; Angelo, C.G.\n");
			printf("Novembro de 2011 - Universidade de Brasilia\n");
			break;
		case  ERR_NO_OUT_NAME:
			printf("gmag: diretiva '-o' deve ser seguida do nome do arquivo de saida\n");
			break;
		case  ERR_NO_DIR:			
			printf("gmag: diretiva '-B'deve ser seguida de um diretorio\n");
			break;
		case  ERR_NO_FILE: 
			printf("gmag: arquivo de entrada faltando\n");
			break;
		case  ERR_MANY_FILE:
			printf("gmag: arquivos de entrada demais\n");
			break;
		case  ERR_INV_FILE:
			printf("gmag: nao foi possivel abrir o arquivo de entrada\n");
			break;
		case  ERR_ANALYZE_DONE:
			printf("gmag: nenhum erro encontrado no codigo fonte\n");
			break;
		default: 
			printf("ERROR CODE = %d\n", error);
	}
	
	exit(1);
}

#else
const char *help_menu[] = {
	"Usage: gmag [options] file...",
	"GMAG MIPS Assembler - GNU GPL v3",
	"",
	"Options:",
	"  -o <file>		Place the output into <file>",
	"  -B <directory>	Add <directory> to the assembler's search path",
	"  -b			Generate output file in binary format",
	"  -t			Generate output file in binary text format",
	"  -A			Analyze only; do not assemble",	
	"  -Wall			Show warning messages",
	"  --help		Display this help and exit",
	"  --version		Display the version of the assembler",
	"  --about		Display authory information"
};

void print_error_msg(uint32_t line, uint8_t error) 
{
	if(line > 0)
		printf("gmag: %s.%d: ",g_input_file_name, line);
	
	switch(error){
		case  ERR_TK_INV:
			printf("Lexical error -> invalid token\n");
		case  ERR_TK_REG_INV:
			printf("Lexical error -> invalid register\n");
		case  ERR_TK_IMM_INV:
			printf("Lexical error -> invalid immediate\n");
		case  ERR_TK_SYMBOL_INV:
			printf("Lexical error -> invalid symbol\n");
		case  ERR_MISA_BRACKET:
			printf("Parsing error -> missaligned brackets\n");
		case  ERR_MISP_BRACKET:
			printf("Parsing error -> misplaced brackets\n");
		case  ERR_MISP_COLON:
			printf("Lexical error -> misplaced colon\n");
		case  ERR_MISS_BRACKET:
			printf("Parsing error -> missing brackets\n");
		case  ERR_EXTRA_BRACKET:
			printf("Parsing error -> extra brackets\n");
		case  ERR_MANY_ARG:
			printf("Parsing error -> too many arguments\n");
		case  ERR_FEW_ARG:
			printf("Parsing error -> too few arguments\n");
		case  ERR_TYPE_ARG:
			printf("Parsing error -> invalid argument type\n");
		case  ERR_MISS_INST:
			printf("Parsing error -> missing instruction\n");
		case  ERR_INV_INST:
			printf("Parsing error -> invalid instruction\n");
		case  ERR_MANY_LABELS:
			printf("Parsing error -> too many labels\n");
		case  ERR_REP_LABEL:
			printf("Semantic error -> repeated label\n");
			break;
		case  ERR_INV_DIRECT:
			printf("gmag: unrecognized option\n");
			printf("      For information about directives type './gmag --help'\n");
			break;
		case  ERR_HELP_MENU: 
			break;
		case ERR_VERSION:
			printf("%s\n",VERSION);
			break;
		case ERR_ABOUT:
			printf("developed by Geraldes, A.A.; Melo, N.C.; Gouveia, D.C.; Angelo, C.G.\n");
			printf("November 2011 - University of Brasilia\n");
			break;
		case  ERR_NO_OUT_NAME:
			printf("gmag: '-o' directive should be followed by the output file name\n");
			break;
		case  ERR_NO_DIR:			
			printf("gmag: '-B' directive should be followed by a directory\n");
			break;
		case  ERR_NO_FILE: 
			printf("gmag: no input file\n");
			break;
		case  ERR_MANY_FILE:
			printf("gmag: too many input files\n");
			break;
		default: 
			printf("ERROR CODE = %d\n", error);
	}
	
	exit(1);
}
#endif

void print_line_list(token_list* list){
	while(list != NULL){
		printf("LINE %d :\n",list->index);
		if(list->first_token != NULL)
			print_token_list(list->first_token);
		list = list->next;
	}
	return;
}

void print_token_list(token* tk){
	while(tk != NULL){
		printf("Token: type = %d, value = %d, value_s = %s\n",tk->type, tk->value, tk->value_s);
		tk = tk->next;
	}
	return;
}

void print_symbols_table(symbols_table* table){
	while(table != NULL){
		printf("SYMBOL = %s, INDEX = %d\n",table->symbol, table->index);
		table = table->next;
	}
	return;
}

void print_inst(inst_list *il)
{
	while(il != NULL){
		printf("\nIndex: %3d",il->index);
		printf("\nLine: %3d",il->code_line);
		printf("\nType: %3d",il->type);
		printf("\nValues:\top = %3d\n\trs = %3d\n\trt = %3d\n\trd = %3d\n\tshamt = %3d\n\tfunct = %3d\n\timm = %d",
			il->values.op,il->values.rs,il->values.rt,il->values.rd,il->values.imm,il->values.funct,il->values.imm);
		il = il->next;
	}
			return;
}
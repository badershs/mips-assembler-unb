/* -----------------------------------------------------------------------------
**  MIPS Assembler UnB - Directives Analyzer
**
**  Description: 
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** ---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "directives.h"
#include "string_man.h"
#include "mips_assembler.h"

#define SIZE_HELP_MENU	13

uint8_t gflag_analyze_only;
uint8_t gflag_warnings;
uint8_t gflag_binary;
char* g_input_file_name;
char* g_output_file_name;
string_list* g_path;

#ifdef LANGUAGE_PT_BR
const char *help_menu[] = {
	"Uso: gmag [opcoes] arquivo...",
	"Montador MIPS GMAG - GNU GPL v3",
	"",
	"Opcoes:",
	"  -o <arquivo>		Salva a saida em <arquivo>",
	"  -B <diretorio>	Adiciona o <diretorio> ao caminho de busca do montador",
	"  -b			Gera o arquivo de saida em formato binario",
	"  -t			Gera o arquivo de saida em formato texto binario",
	"  -A			Executa apenas a analise; nao faz a montagem",	
	"  -Wall			Exibir mensagens de aviso",
	"  --help		Exibir este menu e encerrar execucao",
	"  --version		Exibir versao do montador",
	"  --about		Exibir informacoes autorais"
};
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
#endif

int set_options(int argc, char *argv[])
{
	int i, j;
	char* output_prefix;
	string_list *cur_str, *next_str;
	
	gflag_analyze_only = 0;
	gflag_warnings = 0;
	gflag_binary = 0;
	g_input_file_name = NULL;
	g_output_file_name = NULL;
	g_path = NULL;
	
	for(i = 1; i < argc; i++){
		if(*(argv[i]) == '-'){
			if(strcmp(argv[i], "-o") == 0){
				if(i == argc-1)
					return ERR_NO_OUT_NAME;
				else{
					if(*(argv[i+1]) == '-')
						return ERR_NO_OUT_NAME;
					g_output_file_name = (char*)malloc(strlen(argv[i+1])+1);
					strcpy(g_output_file_name,argv[i+1]);
					i++;
				}
			}
			else if(strcmp(argv[i], "-b") == 0){
				gflag_binary = 1;
			}
			else if(strcmp(argv[i], "-t") == 0){
				gflag_binary = 0;
			}
			else if(strcmp(argv[i], "-A") == 0){
				gflag_analyze_only = 1;
			}
			else if(strcmp(argv[i], "-B") == 0){
				if(i == argc-1)
					return ERR_NO_DIR;
				else{
					if(*(argv[i+1]) == '-')
						return ERR_NO_DIR;
					
					next_str = (string_list*)malloc(sizeof(string_list));
					next_str->string = (char*)malloc(strlen(argv[i+1])+1);
					strcpy(next_str->string,argv[i+1]);
					i++;
					
					if(g_path == NULL)
						g_path = next_str;
					else
						cur_str->next = next_str;
					
					cur_str = next_str;
				}
			}
			else if(strcmp(argv[i], "-Wall") == 0){
				gflag_warnings = 1;
			}
			else if(strcmp(argv[i], "--version") == 0){
				return ERR_VERSION;
			}
			else if(strcmp(argv[i], "--about") == 0){
				return ERR_ABOUT;
			}
			else if(strcmp(argv[i], "--help") == 0){
				for(j = 0; j < SIZE_HELP_MENU; j++)
					printf("%s\n",help_menu[j]);
				printf("\n");
				return ERR_HELP_MENU;
			}
			else{
				return ERR_INV_DIRECT;
			}
		}
		else{
			if(g_input_file_name == NULL){
				g_input_file_name = (char*)malloc(strlen(argv[i])+1);
				strcpy(g_input_file_name, argv[i]);
			}
			else
				return ERR_MANY_FILE;
		}
	}
	
	if(g_input_file_name == NULL)
		return ERR_NO_FILE;
	
	if(g_output_file_name == NULL){
		output_prefix = (char*)malloc(strlen(g_input_file_name)+1);
		get_string_prefix(g_input_file_name, &output_prefix);
		
		if(gflag_binary){
			g_output_file_name = (char*)malloc(strlen(output_prefix)+5);
			strcpy(g_output_file_name, output_prefix);
			strcat(g_output_file_name, ".bin");
		}
		else{
			g_output_file_name = (char*)malloc(strlen(output_prefix)+9);
			strcpy(g_output_file_name, output_prefix);
			strcat(g_output_file_name, ".bin.txt");
		}
	}
	
	return ERR_NO_ERROR;
}
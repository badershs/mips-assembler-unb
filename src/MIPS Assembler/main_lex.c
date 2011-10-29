/* ---------------------------------------------------------------------------
**  MIPS Assembler UnB - Main (Debug file)
**
**  Description: This is just a debug main file, to test isolated functions
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** -------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "string_man.h"
#include "lexical_analyzer.h"

int main(){
	FILE* file = fopen("Testbench.s","r");
	if(file != NULL){
		lexical_analysis(file);
		fclose(file);
	}
	else
		printf("Error opening file\n");
    
    return 0;
}
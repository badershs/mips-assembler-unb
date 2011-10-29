/* ---------------------------------------------------------------------------
**  MIPS Assembler UnB - String Manipulator
**
**  Description: 
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** -------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#include "mips_assembler.h"

void print_error_msg(uint32_t line, uint8_t error) 
{
	switch(error){
		default: printf("Line %d: ERROR: error code = %d\n",line, error);
	}
	
	exit(1);
}
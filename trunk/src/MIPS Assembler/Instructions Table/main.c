#include "instructions_table.h"

extern const instruction inst_table[];

int main(){
    int i;
    instruction inst;
    
    printf("\nHi! I'm going to print 3 instructions from the instructions table\n\n");
    
    for(i = 0; i < 3; i++){
	inst = inst_table[i];
	printf("INSTRUCTION %d: Name = %s, Type = %d, Opcode = %d, Funct = %d\n",(i+1), inst.name, inst.type, inst.opcode, inst.funct);
	
    }
    
    printf("\nGoodbye\n\n");
    
    return 0;
}
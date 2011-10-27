/* Tabela com as instruções iniciais para a parte 1 do projeto.
	Tabelas monatadas em função de structs (eu acho).

*/
#include"instruction_table.h"
#include<stdio.h>
#include<string.h>

int instruction_table (int posição) {
	struct inst {
		int opcode;
		int funct;
		char tipo;
		char subtipo;
	};
	
	for () {
		inst add;
			add.opcode = 000000b;
			add.funct = 100000b;
			add.tipo = R;
			add.subtipo = R1;
			
		inst sub;
			sub.opcode = 000000b;
			sub.funct = 100010b;
			sub.tipo = R;
			sub.subtipo = R1;
			
		inst and;
			and.opcode = 000000b;
			and.funct = 100100b;
			and.tipo = R;
			and.subtipo = R1;
			
		inst or;
			or.opcode = 000000b;
			or.funct = 100101b;
			or.tipo = R;
			or.subtipo = R1;
			
		inst sll;
			sll.opcode = 000000b;
			sll.funct = 000000b;
			sll.tipo = R;
			sll.subtipo = R2;
			
		inst addi;
			addi.opcode = 001000b;
			addi.funct = Null;
			addi.tipo = I;
			addi.subtipo = I1;
			
		inst lw;
			lw.opcode = 100011b;
			lw.funct = Null;
			lw.tipo = I;
			lw.subtipo = I2;
			
		inst sw;
			sw.opcode = 101011b;
			sw.funct = Null;
			sw.tipo = I;
			sw.subtipo = I2;
			
		inst beq;
			beq.opcode = 000100b;
			beq.funct = Null;
			beq.tipo = I;
			beq.subtipo = I1;
			
		inst j;
			j.opcode = 000010b;
			j.funct = Null;
			j.tipo = J;
			j.subtipo = J1;
			
		inst jr;
			jr.opcode = 000000b;
			jr.funct = 001000b;
			jr.tipo = R;
			jr.subtipo = R1;
			
		inst jal;
			jal.opcode = 000011b;
			jal.funct = Null;
			jal.tipo = J;
			jal.subtipo = J2;
			
	}
}
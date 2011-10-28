#ifndef REGISTERS_STRING
#define REGISTERS_STRING

/*Registradores tipo 1*/

#define REG_0		(zero)
#define	REG_1		(at)
#define REG_2		(v0)
#define REG_3		(v1)
#define REG_4		(a0)
#define REG_5		(a1)
#define REG_6		(a2)
#define REG_7		(a3)
#define REG_8		(t0)
#define REG_9		(t1)
#define REG_10		(t2)
#define REG_11		(t3)
#define REG_12		(t4)
#define REG_13		(t5)
#define REG_14		(t6)
#define REG_15		(t7)
#define REG_16		(s0)
#define REG_17		(s1)
#define REG_18		(s2)
#define REG_19		(s3)
#define REG_20		(s4)
#define REG_21		(s5)
#define REG_22		(s6)
#define REG_23		(s7)
#define REG_24		(t8)
#define REG_25		(t9)
#define REG_26		(k0)
#define REG_27		(k1)
#define REG_28		(gp)
#define REG_29		(sp)
#define REG_30		(fp)
#define REG_31		(ra)

 typedef struct {
	char* name;
	char* reg;	
} registers;

#endif

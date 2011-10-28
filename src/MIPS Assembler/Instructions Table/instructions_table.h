#ifndef INSTRUCTIONS_TABLE_H
#define INSTRUCTIONS_TABLE_H

#include <stdint.h>

/* INSTRUCTION TYPES */
#define TYPE_R		(0x01)
#define TYPE_I		(0x02)
#define TYPE_J		(0x03)

/* INSTRUCTION SUBTYPES */
#define STYPE_R1	(0x01)
#define STYPE_I1	(0x11)
#define STYPE_I2	(0x12)
#define STYPE_I3	(0x13)
#define STYPE_J1	(0x21)

/* OPCODES */
#define OP_ADD		(0x00)
#define OP_ADDI		(0x08)
#define OP_BEQ		(0x04)
#define OP_LW		(0x23)
#define OP_J		(0x02)

/* FUNCTS */
#define FN_ADD		(0x20)
#define FN_ADDI		(0x00)
#define FN_BEQ		(0x00)
#define FN_LW		(0x00)
#define FN_J		(0x00)

typedef struct {
    char* name;
    uint8_t type;
    uint8_t subtype;
    uint8_t opcode;
    uint8_t funct;
} instruction;

#endif
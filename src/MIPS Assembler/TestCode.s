add $8, $9, $10
LABEL: jr $8
sll $8,$9,35
addi $8, $9, -9
beq $8, $9, LABEL
LABEL: j LABEL
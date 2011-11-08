Label1:		addi $t0, $zero, 50
Label2:		addi $t1, $zero, 40
Label3 :	beq $t0, $t1, Label24

Label4:		addi $t0, $zero, 60
Label5:		addi $t1, $zero, 70
Label6 :	beq $t0, $t1, Label6

Label7:		addi $t0, $zero, 80
Label8:		addi $t1, $zero, 90
Label9 :	beq $t0, $t1, Label10

Label10:	addi $t0, $zero, 100
Label11:	addi $t1, $zero, 110
Label12 :	beq $t0, $t1, Label16

Label13:	addi $t0, $zero, 120
Label14:	addi $t1, $zero, 130
Label15 :	bne $t0, $t1, Label14

Label16:	addi $t0, $zero, 140
Label17:	addi $t1, $zero, 150
Label18 :	bne $t0, $t1, Label13

Label19:	addi $t0, $zero, 160
Label20:	addi $t1, $zero, 170
Label21 :	bne $t0, $t1, Label3

Label22:	addi $t0, $zero, 180
Label23:	addi $t1, $zero, 190
Label24 :	bne $t0, $t1, Label1

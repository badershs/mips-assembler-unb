		addi	$t0, $zero, 0x34
		addi	$t1, $zero, 0x1200
		add 	$t2, $t0, $t1	
		beq 	$t2, $zero, Error
		sll 	$t4, $t2, 1
		sub	$t5, $t4, $t2
		bne	$t5, $t2, Error
End:	j End 

Error:	j Error

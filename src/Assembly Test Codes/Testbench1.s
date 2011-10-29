		li	$t0,0x12345678
		li	$t1,0x9ABCDEF0
		add 	$t2,$t0,$t1	
		beq 	$t0,$zero,Error
		sub 	$t3,$t2,$t1
		sll 	$t4,$t3,2
		
		
		addi	$t0, $t1, 000a00
		addi	$t0, $t1, -8		

End:	j End

Error:	j Error

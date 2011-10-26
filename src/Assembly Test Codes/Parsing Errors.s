###############################################################################
#                               PARSING ERRORS                                #
###############################################################################		

##### Errors involving brackets

#Error:		lw	$t1,$t2			-	Missing brackets
#Error:		lw	$t1,($t2		-	Missaligned brackets
#Error:		lw	($t1),($t2)		-	Extra brackets

##### Error with the arguments

#Error:		add	$t1,$t2			- 	Too few arguments
#Error:		add	$t1, $t2, $t3, $t4	-	Too many arguments
#Error:		add	$t1, $t2, var		-	Incorrect type
#Error:		add	$t1, $t2, 5		-	Incorrect type
#Error:		add	$t1, $t2, add		-	Incorrect type	

End:		j 	End

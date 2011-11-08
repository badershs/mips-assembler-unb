###############################################################################
#                               LEXICAL ERRORS                                #
###############################################################################		

##### Invalid language elements

# Invalid characters: ! @ % ¨& * - + = / ^ ~ ´ ` < > | \ [ ] { }

#Label!:	add	$t1,$t2,$t3 
#Label@:	add	$t1,$t2,$t3
#Label%:	add	$t1,$t2,$t3
#Label¨:	add	$t1,$t2,$t3
#Label&:	add	$t1,$t2,$t3
#Label*:	add	$t1,$t2,$t3
#Label-:	add	$t1,$t2,$t3
#Label+:	add	$t1,$t2,$t3
#Label=:	add	$t1,$t2,$t3
#Label/:	add	$t1,$t2,$t3 
#Label^:	add	$t1,$t2,$t3
#Label~:	add	$t1,$t2,$t3
#Label´:	add	$t1,$t2,$t3
#Label`:	add	$t1,$t2,$t3
#Label;:	add	$t1,$t2,$t3
#Label<:	add	$t1,$t2,$t3 
#Label>:	add	$t1,$t2,$t3 
#Label|:	add	$t1,$t2,$t3 
#Label\:	add	$t1,$t2,$t3 
#Label[:	add	$t1,$t2,$t3 
#Label]:	add	$t1,$t2,$t3 
#Label{:	add	$t1,$t2,$t3 
#Label}:	add	$t1,$t2,$t3 


##### Label starting with a number

#2Label:	add	$t1,$t2,$t3 


##### Duplicated lables

Label:		add	$t1, $t2, $t3
#Label:		add	$t1, $t2, $t3
		addi	$t1, $t2, 1+5

End:		j	End

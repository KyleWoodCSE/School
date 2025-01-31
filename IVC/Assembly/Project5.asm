# File:		Project5.asm
# Author:	Kyle Wood 1272942
# Purpose:	Recursive addition sum

.text
.globl main
main:
 	# register conventions
 	# $s0 - n
 	# $s1 - answer

 	la $a0, prompt 		# get the user number
 	jal PromptInt
 	move $s0, $v0

 	move $a0, $s0

 	jal Addition 		# do sum addition
 	move $s1, $v0

 	la $a0, result 		# print the answer
 	move $a1, $s1
 	jal PrintInt

 	jal Exit

Addition:
 	addi $sp, $sp, -8 	# push the stack
 	sw $a0, 4($sp) 		# save $a0
 	sw $ra, 0($sp) 		# save the $ra

 	seq $t0, $a0, $zero 	# if (n == 0) return
 	li $v0, 0 		# set return value
 	bnez $t0, Return

 	addi $a0, $a0, -1 	# set n = n-1
 	jal Addition 		# recurse
 	lw $a0, 4($sp) 		# retrieve n
 	add $v0, $a0, $v0 	# add n to result

 	Return:
 	lw $ra, 0($sp) 		# pop the stack
 	addi $sp, $sp, 8
 	jr $ra

.data
prompt: .asciiz "Enter an integer for recursive sum addition: "
result: .ascii "The answer is: "
.include "utils.asm"

# File:		Program8-2.asm
# Author:	Kyle Wood 1272942
# Purpose:	Recursive multiplication

.text
.globl main
main:
 	# register conventions
 	# $s0 - m
 	# $s1 - n
 	# $s2 - answer

 	la $a0, prompt1 # get the multiplicand
 	jal PromptInt
 	move $s0, $v0

 	la $a0, prompt2 # get the multiplier
 	jal PromptInt
 	move $s1, $v0

 	move $a0, $s0
 	move $a1, $s1

 	jal Multiply # do multiplication
 	move $s2, $v0

 	la $a0, result # print the answer
 	move $a1, $s2
 	jal PrintInt

 	jal Exit

Multiply:
 	addi $sp, $sp, -8 # push the stack
 	sw $a0, 4($sp) # save $a0
 	sw $ra, 0($sp) # save the $ra

 	seq $t0, $a1, $zero # if (n == 0) return
 	addi $v0, $zero, 0 # set return value
 	bnez $t0, Return

 	addi $a1, $a1, -1 # set n = n-1
 	jal Multiply # recurse
 	lw $a0, 4($sp) # retrieve m
 	add $v0, $a0, $v0 # return m+multiply(m, n-1)

 	Return:
 	lw $ra, 0($sp) # pop the stack
 	addi $sp, $sp, 8
 	jr $ra

.data
prompt1: .asciiz "Enter the multiplicand: "
prompt2: .asciiz "Enter the multiplier: "
result: .ascii "The answer is: "
.include "utils.asm"
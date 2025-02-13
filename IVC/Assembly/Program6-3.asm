# Program:	Program6-3.asm
# Author:	Kyle Wood #1272942
# Purpose:	Register direct access

.text
.globl main
main:
 	# Get input value and store it in $s0
 	la $a0, prompt
 	jal PromptInt
 	move $s0, $v0
 	
 	# Load constants a, b, and c into registers
 	li $t5, 5
 	li $t6, 2
 	li $t7, 3
 	
  	# Calculate the result of y=a*x*x + b * x + c and store it.
 	mul $t0, $s0, $s0
 	mul $t0, $t0, $t5
 	mul $t1, $s0, $t6
 	add $t0, $t0, $t1
 	add $s1, $t0, $t7
 	
 	# Print output from memory y
 	la $a0, result
 	move $a1, $s1
 	jal PrintInt
 	jal PrintNewLine
 	
 	#Exit program
 	jal Exit

.data
y: .word 0
prompt: .asciiz "Enter a value for x: "
result: .asciiz "The result is: "
.include "utils.asm"
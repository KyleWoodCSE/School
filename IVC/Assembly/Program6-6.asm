# Program:	Program6-6.asm
# Author:	Kyle Wood #1272942
# Purpose:	Memory (indirect) pointer variables)
# The following program shows the use of memory indirect (pointer) variables. The memory at
# the start of the .data segment (0x10010000) contains an address (or reference7)
# to the actual storage location for the constants a, b, and c.
# These variables are then accessed by loading the
# address in memory into a register and using that address to locate the constants.

.text
.globl main
main:
 	# Get input value and store it in $s0
 	la $a0, prompt
 	jal PromptInt
 	move $s0, $v0
 	
 	# Load constants a, b, and c into registers
 	lui $t0, 0x1001
 	lw $t0, 0($t0)
 	lw $t5, 0($t0)
 	lw $t6, 4($t0)
 	lw $t7, 8($t0)
 	
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
 .word constants
y: .word 0
prompt: .asciiz "Enter a value for x: "
result: .asciiz "The result is: "
constants:
 .word 5
 .word 2
 .word 3
.include "utils.asm"
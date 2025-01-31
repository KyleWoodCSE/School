# Program:	Program6-4.asm
# Author:	Kyle Wood #1272942
# Purpose:	Register indirect access
# Register indirect access differs from register direct access in that the register does not contain the
# value to use in the calculation but contains the address in memory of the value to be used. To
# see this, consider the following example. If the .data segment in this program is the first .data
# segment that the assembler has encountered, the numbering of variables in this segment begins at
# 0x10010000, so the variable a will be at that address. The next allocation that the assembler will
# find is for the variable b. Since the variable a took up 4 bytes of memory, the variable b will be
# at memory address 0x10010000 + 0x4 = 0x10010004. Likewise variable c will be at memory
# location 0x10010000 + 0x8 = 0x10010008, and variable y will be at 0x10010000 + 0xc =
# 0x1001000c. This next program illustrates how register indirect addressing works.

.text
.globl main
main:
 	# Get input value and store it in $s0
 	la $a0, prompt
 	jal PromptInt
 	move $s0, $v0
 	
 	# Load constants a, b, and c into registers
 	lui $t0, 0x1001
 	lw $t5, 0($t0)
 	addi $t0, $t0, 4
 	lw $t6, 0($t0)
 	addi $t0, $t0, 4
 	
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
 .word 5
 .word 2
 .word 3
y: .word 0
prompt: .asciiz "Enter a value for x: "
result: .asciiz "The result is: "
.include "utils.asm"
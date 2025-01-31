# Propgram:	Program7-5.asm
# Author:	Kyle Wood 1272942
# Purpose:	Counter control loop program

.text
 	la $a0, prompt
 	jal PromptInt
 	move $s1, $v0
 	li $s0, 0
 	li $s2, 0 # Initialize the total

 	start_loop:
 		slt $t1, $s0, $s1
 		beqz $t1, end_loop

 		# code block
 		add $s2, $s2, $s0
 		
 		addi $s0, $s0, 1
 		b start_loop
 	end_loop:

 	la $a0, output
 	move $a1, $s2
 	jal PrintInt

 	jal Exit
 	
.data
 	prompt: .asciiz "enter the value to calculate the sum up to: "
 	output: .asciiz "The final result is: "
 	
.include "utils.asm"
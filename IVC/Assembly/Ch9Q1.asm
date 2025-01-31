# Program: 	Ch9Q1.asm
# Author: 	Kyle Wood
# Purpose: 	Printing an array of integers in reverse order - changes made me me indicated by ***
#		Extra credit was implemented to prompt user for 5 integers

.text
.globl main
main:
 	la $a0, intro
 	jal PrintString
 	
 	# Initialize register values
    	li $t0, 0       # Counter for array index
    	la $t1, array_base   # Load address of array

	input_loop:
    		# prompt user for integer
    		la $a0, prompt
    		jal PromptInt

    		# Store integer in array
    		sw $v0, ($t1)   # Store the integer in the array
    		addi $t1, $t1, 4  # Move to the next element in the array

    		# Increment counter
    		addi $t0, $t0, 1

    		# Check if 5 integers have been entered
    		bne $t0, 5, input_loop
 	
 	la $a0, array_base
 	lw $a1, array_size
 	jal PrintIntArray
 	jal Exit

.data
 	array_size: .word 5
 	array_base: .space 20 # space for array to hold five 4 byte integers
 	intro: .asciiz "You will now be prompted to enter five integers.\n"
 	prompt: .asciiz "Enter an integer: "

# Subprogram: 	PrintIntArray
# Purpose: 	print an array of ints
# inputs: 	$a0 - the base address of the array
# 		$a1 - the size of the array

.text
PrintIntArray:
 	addi $sp, $sp, -16 	# Stack record
 	sw $ra, 0($sp)
 	sw $s0, 4($sp)
 	sw $s1, 8($sp)
 	sw $s2, 12($sp)
 	move $s0, $a0 		# save the base of the array to $s0

 	# Initialization for counter loop
 	# $s1 is the ending index of the loop
 	# $s2 is the loop counter
 	move $s1, $a1
 	li $s2, 4 # set to last element ***
 	li $s3, 5 # increment counter ***
 	la $a0 open_bracket 	# print open bracket
 	jal PrintString
 	

loop:
 	# check ending condition
 	beqz $s3, end_loop # once loop counter decrements to zero, break loop ***

 		sll $t0, $s2, 2 	# Multiply the loop counter by 4 to get offset (each element is 4 big)
 		add $t0, $t0, $s0 	# address of next array element
 		lw $a1, 0($t0) 		# Next array element
 		la $a0, comma
 		jal PrintInt 		# print the integer from array

 		addi $s2, $s2, -1 	# increment $s0
 		addi $s3, $s3, -1	# decrement loop counter ***
 		b loop
end_loop:
 	li $v0, 4 	# print close bracket
 	la $a0, close_bracket
 	syscall
 	
 	lw $ra, 0($sp)
 	lw $s0, 4($sp)
 	lw $s1, 8($sp)
 	lw $s2, 12($sp) 	# restore stack and return
 	addi $sp, $sp, 16
 	jr $ra 

.data
 	open_bracket: .asciiz "["
 	close_bracket: .asciiz "]"
 	comma: .asciiz ","
.include "utils.asm"
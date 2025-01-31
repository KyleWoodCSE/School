# Program: 	Ch9Q2.asm
# Author: 	Kyle Wood
# Purpose: 	Converts an input value of a single decimal number from 1 ? n ? 15 into a single hexadecimal digit


.text
.globl main

main:
    	# Prompt user to enter number between 0-15
    	la $a0, prompt      
    	jal PromptInt
    	move $t0, $v0           # store input value in $t0
    
    	# get hex value based on decimal input
    	sll $t0, $t0, 2 	# multiply $t0 by 4 (size) to get the offset
	la $t1, a 		# $t1 is the base of the array
	add $t0, $t0, $t1 	# basePtr + (index * size)

    	# Print output message
    	la $a0, output
    	jal PrintString

    	# Print hexadecimal digit
    	move $a0, $t0           # load address of array element into $a0
    	jal PrintString

    	# Exit program
    	jal Exit

.data
	prompt: .asciiz "Enter a number from 0 to 15: "
	output: .asciiz "Your number is "

	a:
    		.asciiz "0x0"
    		.asciiz "0x1"
    		.asciiz "0x2"
    		.asciiz "0x3"
    		.asciiz "0x4"
    		.asciiz "0x5"
    		.asciiz "0x6"
    		.asciiz "0x7"
    		.asciiz "0x8"
    		.asciiz "0x9"
    		.asciiz "0xa"
    		.asciiz "0xb"
    		.asciiz "0xc"
    		.asciiz "0xd"
    		.asciiz "0xe"
    		.asciiz "0xf"

.include "utils.asm"

# Program File: Program2-3.asm
# Author: Kyle Wood
# Reads a string from a user and prints it back to the console
.text
main:
	# Prompt for the string to enter
	li $v0, 4
	la $a0, prompt
	syscall
	
	# Read the string
	li $v0, 8
	la $a0, input
	lw $a1, inputSize
	syscall
	
	# Output "You typed the string: "
	li $v0, 4
	la $a0, output
	syscall
	
	# Output the user's string
	li $v0, 4
	la $a0, input
	syscall
	
	# Exit the program
	li $v0, 10
	syscall
	
.data
input: .space 81
inputSize: .word 80
prompt: .asciiz "Please enter a string: "
output: .asciiz "\nYou typed the string: "
# File:		Ch3Q1.asm
# Author:	Kyle Wood # 1272942
# Purpose:	Calculate the 2's complement of an integer given by user using xori and addi operators

.text
.globl main
main:
	# prompt user to enter a number
	li $v0, 4
	la $a0, prompt
	syscall
	
	# store integer input from user
	li $v0, 5
	syscall
	move $t0, $v0
	
	# perform bitwise complement of integer using xori
	xori $t0, $t0, -1
	
	# add 1 to bitwise complement to get 2's complement
	addi $t0, $t0, 1
	
	# print output and result to user
	li $v0, 4
	la $a0, output
	syscall
	
	li $v0, 1
	move $a0, $t0
	syscall
	
	# exit the program
	li $v0, 10
	syscall
	
.data
prompt: .asciiz "Enter an integer: "
output: .asciiz "The 2's complement of your integer is: "
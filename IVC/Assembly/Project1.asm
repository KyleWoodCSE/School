# File: 	Project1.asm
# Author: 	Kyle Wood #1272942
# Purpose: 	Calculate a gas volume using the Ideal Gas Law | V = (nRT)/P
#		Take user input for pressure (P), amount of gas (n), and temperature (T), R is a constant

.text
.globl main
main:
 	# prompt user to enter amount of gas (n)
	li $v0, 4
	la $a0, amountPrompt
	syscall
	
	# store integer input from user
	li $v0, 5
	syscall
	move $t0, $v0
	
	# prompt user to enter temperature (T)
	li $v0, 4
	la $a0, tempPrompt
	syscall
	
	# store integer input from user
	li $v0, 5
	syscall
	move $t1, $v0
	
	# prompt user to enter pressure (P)
	li $v0, 4
	la $a0, pressurePrompt
	syscall
	
	# store integer input from user
	li $v0, 5
	syscall
	move $t2, $v0
	
	# store R constant values in temp registers
	addi $t3, $zero, 8314
	addi $t4, $zero, 1000
	
	# perform calculations to find volume
	mul $t0, $t0, $t3 	# multiply n with R x 1000
	mul $t0, $t0, $t1	# multiply nR with T
	div $t0, $t0, $t2	# divide nRT by P
	div $t0, $t0, $t4	# divide by 1000 to correct R value

 	# Print output
 	addi $v0, $zero, 4 # Print result string
 	la $a0, result
 	syscall
 	li $v0, 1 # Print result
 	move $a0, $t0
 	syscall

 	#Exit program
 	addi $v0, $zero, 10
 	syscall

.data
amountPrompt: .asciiz "Please enter an integer number for amount of gas (n): "
tempPrompt: .asciiz "Please enter an integer number for temperature (T): "
pressurePrompt: .asciiz "Please enter an integer number for pressure (P): "
result: .asciiz "The volume based on the values you entered is: "

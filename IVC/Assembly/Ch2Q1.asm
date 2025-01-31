# Homework HWCh2Q1.asm
# Kyle Wood #1272942
# Question 1 - prompt user for favorite type of pie, program will output "so you like ____ pie"
# Explain why syscall makes output on separate lines
.text
main:
	# Prompt for the type of pie from the user
	li $v0, 4
	la $a0, prompt
	syscall
	
	# Read the string
	li $v0, 8
	la $a0, input
	lw $a1, inputSize
	syscall		# syscall service 8 will append newline character, causing anything printed after input is printed to be written on a new line
	
	# Output "So you like "
	li $v0, 4
	la $a0, outputFirst
	syscall
	
	# Output the user's pie input
	li $v0, 4
	la $a0, input
	syscall
	
	# Output " pie"
	li $v0, 4
	la $a0, outputSecond
	syscall
	
	# Exit the program
	li $v0, 10
	syscall
	
.data
input: .space 51
inputSize: .word 50
prompt: .asciiz "Please enter your favorite type of pie: "
outputFirst: .asciiz "\nSo you like "
outputSecond: .asciiz " pie"
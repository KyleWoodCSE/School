# HW Ch2Q5.asm
# Kyle wood 1272942
# Open input dialogue box, read a string value, write the string back to the user using a message box
.text
main:
	# open dialogue box for user input string
	li $v0, 54
	la $a0, prompt
	la $a1, input
	la $a2, inputSize
	syscall
	
	# print user input string in dialogue box
	li $v0, 59
	la $a0, output
	la $a1, input
	syscall
	
	# terminate execution
	li $v0, 10
	syscall
	
.data
prompt: .asciiz "Please enter a string: "
input: .space 81
inputSize: .word 80
output: .asciiz "The string you entered was: "
# File: 	Program5-4.asm
# Author: 	Kyle Wood
# Purpose: 	Illustrates implementing a subprogram named PrintNewLine.
.text
main:
 	# Read an input value from the user
 	la $a0, prompt
 	jal PrintString
 	li $v0, 5
 	syscall
 	move $s0, $v0

 	# Print the value back to the user
 	jal PrintNewLine
 	la $a0, result
 	move $a1, $s0
 	jal PrintInt

 	# Call the Exit subprogram to exit
 	jal Exit
.data
 prompt: .asciiz "Please enter an integer: "
 result: .asciiz "You entered: "
 
# Subprogram: 	PrintNewLine
# Author: 	Kyle Wood
# Purpose: 	to output a new line to the user console
# Input/Output: None
# Side effects: A new line character is printed to the user's console
.text
PrintNewLine:
 	li $v0, 4
 	la $a0, __PNL_newline
 	syscall
 	jr $ra
.data
 __PNL_newline: .asciiz "\n"
 
# Subprogram: 	PrintInt
# Author: 	Kyle Wood
# Purpose: 	To print a string to the console
# Input: 	$a0 - The address of the string to print.
# 		$a1 - The value of the int to print
# Returns: 	None
# Side effects: The String is printed followed by the integer value.
.text
PrintInt:
 	# Print string. The string address is already in $a0
 	li $v0, 4
 	syscall

 	# Print integer. The integer value is in $a1, and must
 	# be first moved to $a0.
 	move $a0, $a1
 	li $v0, 1
 	syscall

 	#Return
 	jr $ra

# Subprogram: 	PrintString
# Author: 	Kyle Wood
# Purpose: 	To print a string to the console
# Input: 	$a0 - The address of the string to print.
# Returns: 	None
# Side effects: The String is printed to the console.
.text
PrintString:
 	addi $v0, $zero, 4
 	syscall
 	jr $ra

# Subprogram: 	Exit
# Author: 	Kyle Wood
# Purpose: 	to use syscall service 10 to exit a program
# Input/Output: None
# Side effects: The program is exited
.text
Exit:
 	li $v0, 10
 	syscall
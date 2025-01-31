# File:		Project2.asm
# Purpose:	To define utilities which will be used in MIPS programs with some additional requests
# Author:	Kyle Wood
# 
# Title to and ownership of all intellectual property rights 
# in this file are the exclusive property of Charles W. Kann and Kyle Wood
#
# Subprograms Index:
#   Exit 		Call syscall with a server 10 to exit the program
#   PrintNewLine	Print a new line character (\n) to the console
#   PrintInt		Print a string with an integer to the console
#   PrintString		Print a string to the console
#   PromptInt		Prompt for an int & return it to the calling program.
#   NOR			Take two input parameters and return the NOR operation on those parameters
#   NAND		Take two input parameters and return the NAND operation on those two parameters
#   Mult4		Take an input parameter and return that parameter multiplied by 4 using only the shift operation
#   Swap		Take two input parameters and swap them using only the XOR and MOVE operations
#
# Modification History
#     12/27/2014 - Initial release
#	03/16/2024 - Added functions for Project2


# Subprogram:		Exit
# Author:  		Charles Kann
# Purpose:		to use syscall service 10 to exit a program
# Input/Output:		None
# Side effects:		The program is exited

.text
Exit:
    li $v0, 10
    syscall

# Subprogram:		PrintNewLine
# Author:  		Charles Kann
# Purpose:		to output a new line to the user console
# Input/Output:		None
# Side effects:		A new line character is printed to the user's console

.text
PrintNewLine:
    li $v0, 4
    la $a0, __PNL_newline
    syscall 
    jr $ra

.data
   __PNL_newline:   .asciiz "\n"


# Subprogram: 		PrintInt
# Author:		Charles W. Kann
# Purpose:		To print a string to the console
# Input:		$a0 - The address of the string to print.
#			$a1 - The value of the int to print
# Output:		None
# Side effects:		The String is printed followed by the integer value.

.text
PrintInt: 
    # Print string.  The string address is already in $a0
    li $v0, 4
    syscall
    
    # Print integer.   The integer value is in $a1, and must
    # be first moved to $a0.
    move $a0, $a1
    li $v0, 1
    syscall
    
    #Return
    jr $ra

# Subprogram: 		PrintString
# Author:		Charles W. Kann
# Purpose:		To print a string to the console
# Input:		$a0 - The address of the string to print.
# Output:		None
# Side effects:		The String is printed to the console.

.text
PrintString: 
    addi $v0, $zero, 4
    syscall
    jr $ra

# Subprogram: 		PromptInt
# Author:		Charles W. Kann
# Purpose:		To print the user for an integer input, and
#               	to return that input value to the caller.
# Input:		$a0 - The address of the string to print.
# Output:		$v0 - The value the user entered
# Side effects:		The String is printed followed by the integer value.

.text
PromptInt: 
    # Print the prompt, which is already in $a0
    li $v0, 4
    syscall
    
    # Read the integer.  Note: at the end of the syscall the value is
    # already in $v0, so there is no need to move it anywhere.
    li $v0, 5
    syscall
    
    #Return
    jr $ra
    
# Subprogram:		NOR
# Author:		Kyle Wood
# Purpose:		Take two input parameters and return the NOR operation on those two parameters
# Input:		$a0, $a1- input parameters
# Output:		$v0 - result of NOR operation on inputs
# Side effects:		

.text
NOR
	# prompt user for inputs and read inputs
	li $v0, 4
    	la $a0, __NOR_prompt1
    	syscall
    	
    	li $a0, 5
    	syscall
    	
    	li $v0, 4
    	la $a3, __NOR_prompt2
    	syscall
    	
    	li $a1, 5
    	syscall
    	
	# perform NOR operation on the two inputs
	nor $v0, $a0, $a1
	
	# return
	jr $ra

.data
   __NOR_prompt1:   .asciiz "Enter an integer for first input: "
   __NOR_prompt2:   .asciiz "Enter an integer for second input: "	

# Subprogram:		NAND
# Author:		Kyle Wood
# Purpose:		Take two input parameters and return the NAND operation on those two parameters
# Input:		$a0, $a1 - input parameters
# Output:		$v0 - output after NAND logical operationon both inputs
# Side effects:		

.text
NAND
	# prompt user for inputs and read inputs
	li $v0, 4
    	la $a0, __NAND_prompt1
    	syscall
    	
    	li $a0, 5
    	syscall
    	
    	li $v0, 4
    	la $a3, __NAND_prompt2
    	syscall
    	
    	li $a1, 5
    	syscall
	
	# perform AND operation
	and $t0, $a0, $a1
	# followed by NOR operation to simulate NAND
	nor $v0, $zero, $t0
	
	#return
	jr $ra
	
.data
   __NAND_prompt1:   .asciiz "Enter an integer for first input: "
   __NAND_prompt2:   .asciiz "Enter an integer for second input: "

# Subprogram:		Mult4
# Author:		Kyle Wood
# Purpose:		Take an input parameter and return that parameter multiplied by 4 using only the shift operation.
# Input:		$a0 - input parameter
# Output:		$v0 - input multiplied by 4 by shifting left two bits
# Side effects:		

.text
Mult4:
	# prompt user for input and read input
	li $v0, 4
    	la $a0, __SWAP_prompt1
    	syscall
    	
    	li $a0, 5
    	syscall
	
	# multiply input by 4 by shifting left 2 bits
	sll $v0, $a0, 2
	
	# return
	jr $ra
	
.data
   __MULT4_prompt:   .asciiz "Enter an integer for multiplication input: "

# Subprogram:		Swap
# Author:		Kyle Wood
# Purpose:		Take two input parameters and swap them using only the XOR and MOVE operations.
# Input:		$a0, $a1 - input parameters
# Output:		$a0, $a1 - swapped input parameters
# Side effects:		

.text
Swap:
	# prompt user for inputs and read inputs
	li $v0, 4
    	la $a0, __SWAP_prompt1
    	syscall
    	
    	li $a0, 5
    	syscall
    	
    	li $v0, 4
    	la $a3, __SWAP_prompt2
    	syscall
    	
    	li $a1, 5
    	syscall
	
	# store $a0 parameter in temp register using xor
	xor $t0, $zero, $a0
	# move contents of $a1 to $a0
	move $a0, $a1
	# move contents of $t0 to $a1
	move $a1, $t0
	
	# return
	jr $ra
	
.data
   __SWAP_prompt1:   .asciiz "Enter an integer for first input: "
   __SWAP_prompt2:   .asciiz "Enter an integer for second input: "

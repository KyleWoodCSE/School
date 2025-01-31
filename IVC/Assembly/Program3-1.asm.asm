# File:		Program3-1.asm
# Author:	Kyle Wood
# Purpose: To illustrate some addition operators

.text
# illustrate R format add operator
li $t1, 100
li $t2, 50
add $t0, $t1, $t2

li $v0, 4
la $a0, output1
syscall

li $v0, 1
move $a0, $t0
syscall

# illustrate add with an immediate
addi $t0, $t0, 50

li $v0, 4
la $a0, output2
syscall

li $v0, 1
move $a0, $t0
syscall

# note that an add with a psuedo instruction translated into an addi instruction
add $t0, $t0, 50

li $v0, 4
la $a0, output3
syscall

li $v0, 1
move $a0, $t0
syscall

# using an unsign number, not that the result is not expected for negative numbers
addiu $t0, $t2, -100

li $v0, 4
la $a0, output4
syscall

li $v0, 1
move $a0, $t0
syscall

# addition using a 32 immediate
# note that 5647123 base 10 is 0x562b13
addi $t1, $t2, 5647123

li $v0, 4
la $a0, output5
syscall

li $v0, 1
move $a0, $t1
syscall

# exit the program
li $v0, 10
syscall
	
.data
output1: .asciiz "R format add 100 and 50: "
output2: .asciiz "\nImmediate add 150 and 50: "
output3: .asciiz "\nImmediate add 200 and 50: "
output4: .asciiz "\nImmediate add 50 and -100: "
output5: .asciiz "\nAdd 5647123 and 50 using 32 immediate: "
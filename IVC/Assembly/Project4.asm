# Propgram:	Project4.asm
# Author:	Kyle Wood 1272942
# Purpose:	Print every other capital letter

.data
alphabet: .asciiz "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
newline: .asciiz "\n"

.text
.globl main

main:
    # Load address of the alphabet string
    la $t0, alphabet

    # Initialize loop counter
    li $t1, 0

print_loop:
    # Check if we have reached the end of the string
    lb $t2, 0($t0)
    beqz $t2, end_print_loop
    
    # Check if the current character is a capital letter
    li $t3, 'A'
    li $t4, 'Z'
    blt $t2, $t3, next_iteration
    bgt $t2, $t4, next_iteration
    
    # Print the current capital letter
    li $v0, 11
    move $a0, $t2
    syscall

    # Print a space
    li $v0, 11
    li $a0, ' '
    syscall

next_iteration:
    # Move to the next character in the string
    addi $t0, $t0, 1
    
    # Increment loop counter
    addi $t1, $t1, 1
    
    # Check if we need to skip the next character
    li $t5, 2
    div $t1, $t5
    mfhi $t6
    bnez $t6, next_char
    
next_char:
    # Move to the next character in the string
    addi $t0, $t0, 1

    # Repeat the loop
    j print_loop

end_print_loop:
    # Print a newline character
    li $v0, 11
    la $a0, newline
    syscall

    # Exit the program
    li $v0, 10
    syscall

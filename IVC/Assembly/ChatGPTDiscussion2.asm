# Propgram:	ChatGPTDiscussion2.asm
# Author:	Kyle Wood 1272942
# Purpose:	ChatGPT program for sum revised

.data
array: .word 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
array_size: .word 11
result: .word 0
newline: .asciiz "\n"
sum_label: .asciiz "Sum: "

.text
.globl main

main:
    # Initialize variables
    la $t0, array      # Load array address into $t0
    lw $t1, array_size # Load array size into $t1
    li $t2, 0          # Initialize loop counter
    li $t3, 0          # Initialize sum
    
loop:
    # Check if loop counter exceeds array size
    bge $t2, $t1, print_sum
    
    # Load current element into $t4
    lw $t4, 0($t0)
    
    # Add current element to sum
    add $t3, $t3, $t4
    
    # Increment loop counter
    addi $t2, $t2, 1
    
    # Move to next element in array
    addi $t0, $t0, 4
    
    # Repeat loop
    j loop

print_sum:
    # Store the sum into result variable
    sw $t3, result
    
    # Print label
    li $v0, 4
    la $a0, sum_label
    syscall
    
    # Print sum
    li $v0, 1
    lw $a0, result
    syscall

    # Print newline
    li $v0, 4
    la $a0, newline
    syscall
    
    # Exit program
    li $v0, 10
    syscall

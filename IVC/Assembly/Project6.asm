# Program: 	Project6.asm
# Author: 	Kyle Wood
# Purpose: 	Selection Sort

.text
.globl main
main:
    # print array prior to sorting
    la $a0, begin
    jal PrintString
    la $a0, array_base
    lw $a1, array_size
    jal PrintIntArray

    # perform sorting
    la $a0, array_base
    lw $a1, array_size
    jal SelectionSort
    jal PrintNewLine
    
    # print array after sorting
    la $a0, end
    jal PrintString
    la $a0, array_base
    lw $a1, array_size
    jal PrintIntArray

    jal Exit

.data
    begin: .asciiz "This is the array before sorting: "
    end: .asciiz "This is the array after sorting: "
    array_size: .word 6
    array_base:
        .word 4
        .word 8
        .word 2
        .word 13
        .word 3
        .word 7

# Subprogram:     Selection Sort
# Purpose:        Sort data using a Selection Sort algorithm
# Input Params:   $a0 - array
#                 $a1 - array size
# Register conventions:
#                 $s0 - array base
#                 $s1 - array size
#                 $s2 - outer loop counter (i)
#                 $s3 - inner loop counter (j)
#                 $s4 - index of minimum element (minIndex)

.text
SelectionSort:
    addi $sp, $sp, -24    # save stack information
    sw $ra, 0($sp)
    sw $s0, 4($sp)        # need to keep and restore save registers
    sw $s1, 8($sp)
    sw $s2, 12($sp)
    sw $s3, 16($sp)
    sw $s4, 20($sp)

    move $s0, $a0
    move $s1, $a1

    addi $s2, $zero, 0    # outer loop counter (i)
    OuterLoop:
        slt $t0, $s2, $s1
        beqz $t0, EndOuterLoop

        move $s4, $s2     # minIndex = i

        addi $s3, $s2, 1  # inner loop counter (j)
        InnerLoop:
            slt $t0, $s3, $s1
            beqz $t0, EndInnerLoop

            sll $t1, $s3, 2
            add $t2, $s0, $t1
            lw $t3, 0($t2)   # load data[j]

            sll $t1, $s4, 2
            add $t2, $s0, $t1
            lw $t4, 0($t2)   # load data[minIndex]

            slt $t0, $t3, $t4
            beqz $t0, NotNewMin
                move $s4, $s3  # minIndex = j

            NotNewMin:
            addi $s3, $s3, 1
            b InnerLoop
        EndInnerLoop:

        # Swap data[i] and data[minIndex] if needed
        sll $t1, $s2, 2
        add $t2, $s0, $t1
        lw $t3, 0($t2)  # load data[i]

        sll $t1, $s4, 2
        add $t2, $s0, $t1
        lw $t4, 0($t2)  # load data[minIndex]

        bne $t3, $t4, SwapNeeded
        b ContinueOuterLoop

        SwapNeeded:
            move $a0, $s0
            move $a1, $s2
            move $a2, $s4
            jal Swap

        ContinueOuterLoop:
        addi $s2, $s2, 1
        b OuterLoop
    EndOuterLoop:
    lw $ra, 0($sp)  # restore stack information
    lw $s0, 4($sp)
    lw $s1, 8($sp)
    lw $s2, 12($sp)
    lw $s3, 16($sp)
    lw $s4, 20($sp)
    addi $sp, $sp, 24
    jr $ra

# Subprogram:      Swap
# Purpose:         to swap values in an array of integers
# Input parameters: $a0 - the array containing elements to swap
#                   $a1 - index of element 1
#                   $a2 - index of element 2
# Side Effects:    Array is changed to swap element 1 and 2
Swap:
    sll $t0, $a1, 2    # calculate address of element 1
    add $t0, $a0, $t0
    sll $t1, $a2, 2    # calculate address of element 2
    add $t1, $a0, $t1
    
    lw $t2, 0($t0)     # swap elements
    lw $t3, 0($t1)
    sw $t2, 0($t1)
    sw $t3, 0($t0)

    jr $ra
    
# Subprogram:  PrintIntArray
# Purpose:     print an array of ints
# inputs:      $a0 - the base address of the array
#              $a1 - the size of the array

PrintIntArray:
    addi $sp, $sp, -16  # Stack record
    sw $ra, 0($sp)
    sw $s0, 4($sp)
    sw $s1, 8($sp)
    sw $s2, 12($sp)

    move $s0, $a0       # save the base of the array to $s0

    # Initialization for counter loop
    # $s1 is the ending index of the loop
    # $s2 is the loop counter
    move $s1, $a1
    move $s2, $zero
    
    la $a0, open_bracket    # print open bracket
    jal PrintString
    
loop:
    # check ending condition
    sge $t0, $s2, $s1
    bnez $t0, end_loop

        sll $t0, $s2, 2    # Multiply the loop counter by by 4 to get offset (each element is 4 big).
        add $t0, $t0, $s0  # address of next array element
        lw $a1, 0($t0)     # Next array element
        la $a0, comma
        jal PrintInt       # print the integer from array

        addi $s2, $s2, 1   # increment $s0
        b loop
        
end_loop:

    li $v0, 4            # print close bracket
    la $a0, close_bracket
    syscall
    
    lw $ra, 0($sp)
    lw $s0, 4($sp)
    lw $s1, 8($sp)
    lw $s2, 12($sp)      # restore stack and return
    addi $sp, $sp, 16
    jr $ra
    
.data
    open_bracket: .asciiz "["
    close_bracket: .asciiz "]"
    comma: .asciiz ","
.include "utils.asm"

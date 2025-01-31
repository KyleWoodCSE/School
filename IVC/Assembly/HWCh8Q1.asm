# File:		HWCh8Q1.asm
# Author:	Kyle Wood 1272942
# Purpose:	Take in 4 numbers, return largest and average

.text
.globl main
main:
 	la $a0, prompt
 	jal PrintString
 	
 	li $v0, 5               # Load immediate 5 (read integer)
    	syscall
    	move $a0, $v0           # Move input to $a0

    	li $v0, 5               # Load immediate 5 (read integer)
    	syscall
    	move $a1, $v0           # Move input to $a1

    	li $v0, 5               # Load immediate 5 (read integer)
    	syscall
    	move $a2, $v0           # Move input to $a2

    	li $v0, 5               # Load immediate 5 (read integer)
    	syscall
    	move $a3, $v0           # Move input to $a3
    	
    	jal largestAndAverage

 	jal Exit
 	
largestAndAverage:
 	addi $sp, $sp, -20 	# save space on the stack (push) for the $ra
 	sw $ra, 0($sp) 		# save $ra
 	sw $a0, 4($sp)         # Store var0
    	sw $a1, 8($sp)         # Store var1
    	sw $a2, 12($sp)        # Store var2
    	sw $a3, 16($sp)        # Store var3
 	
 	lw $a0, 4($sp)          # Load var0
    	lw $a1, 8($sp)          # Load var1
 	jal getLarger		# getLarger var0, var1
 	move $s0, $v0
 	
 	move $a0, $s0
 	lw $a1, 12($sp)        # Load var2
 	jal getLarger		# getLarger previous large to var2
 	move $s0, $v0
 	
 	move $a0, $s0
 	lw $a1, 16($sp)        # Load var3
 	jal getLarger		# getLarger previous large to var3
 	
    	la $a0, largest
    	move $a1, $v0
    	jal PrintInt
    	
    	# load variables into temp registers for math operations
    	lw $t1, 4($sp)          # Load var0
    	lw $t2, 8($sp)          # Load var1
    	lw $t3, 12($sp)          # Load var2
    	lw $t4, 16($sp)         # Load var3
    	
    	# sum all four variables
    	add $t5, $t1, $t2
    	add $t5, $t5, $t3	
    	add $t5, $t5, $t4	
    	
    	# calculate average of four variables
    	div $v1, $t5, 4
    	
    	la $a0, average
    	move $a1, $v1
    	jal PrintInt

 	lw $ra, 0($sp) 		# restore $ra
 	addi $sp, $sp, 20 	# return the space on the stack (pop)
 	jr $ra
 	
getLarger:
 	move $v0, $a0     	# $v0 = $a0
    	sgt $t0, $a1, $a0     	# $t0 = 1 if $a1 < $a0, 0 otherwise
    	beqz $t0, larger  	# If $t0 is 0, $a0 is larger, jump to larger
    	move $v0, $a1     	# $v0 = $a1
	jr $ra
	
	larger:
    	jr $ra                  # Return

.data
prompt: .asciiz "Enter four integers: "
largest: .asciiz "\nThe largest integer entered was: "
average: .asciiz "\nThe average of the four integers is: "
.include "utils.asm"
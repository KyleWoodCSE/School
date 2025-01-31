# Program:	Ch6HW.asm
# Author:	Kyle Wood #1272942
# Purpose:	Question 3 troubleshooting

.text
    lui $t0, 0x1001
    lw $a0, 0($t0)
    li $v0, 1
    syscall
    
    li $v0, 10
    syscall

.data
    .word 8



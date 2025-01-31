# File:		Ch4Q1EC.asm
# Author: 	Kyle Wood # 1272942
# Purpose:	Correct the Ch. 4 question 1 output to be "15 * 3 is 45"

.text
.globl main
main:
	# R format opcode-6 rs-5 rt-5 rd-5 shamt(shift)-5 funct-6
	# I format opcode-6 rs-5 rt-5 IMM-16
	
	ori $t0, $zero, 15
	# ori opcode d(hex) - 13(dec), rs - $zero is register 0, rt - $t0 is register 8, IMM-15
	# 001101 00000 01000 0000000000001111 
	# 0011 0100 0000 1000 0000 0000 0000 1111 # binary
	# 0x3408000f  #hex
	
	ori $t1, $zero, 3
	# ori opcode d(hex) - 13(dec), rs - $zero is register 0, rt - $t1 is register 9, IMM-3
	# 001101 00000 01001 0000000000000011
	# 0011 0100 0000 1001 0000 0000 0000 0011 # binary
	# 0x34090003  #hex
	
 	add $t1, $zero $t1
 	# add opcode 0(hex), rs $zero is 0, rt $t1 is 9, rd $t1 is 9, shamt is 0, funct is 20(hex)
 	# 000000 00000 01001 01001 00000 100000
 	# 0000 0000 0000 1001 0100 1000 0010 0000 #binary
 	# 0x00094820 #hex
 	
 	sub $t2, $t0, $t1
 	# sub opcode 0, rs $t0 is 8, rt $t1 is 9, rd $t2 is 10, shamt is 0, funct is 22(hex)
 	# 000000 01000 01001 01010 00000 100010
 	# 0000 0001 0000 1001 0101 0000 0010 0010 #binary
 	# 0x01095022 #hex
 	
 	sra $t2, $t2, 2
 	# opcode 0, rs - 0, rt - $t2 is 10, rd - $t2 is 10, shamt 2, funct 3
 	# 000000 00000 01010 01010 00010 000011
 	# 0000 0000 0000 1010 0101 0000 1000 0011 #binary
 	# 0x000a5083 #hex
 	
 	ori $v0, $zero, 4
 	# ori opcode d(hex) - 13(dec), rs - $zero is register 0, rt - $v0 is register 2, IMM-4
 	# 001101 00000 00010 0000000000000100
 	# 0011 0100 0000 0010 0000 0000 0000 0100 binary
 	# 0x34020004 hex
 	
	la $a0, result
	# 001111 00000 00001 00010 00000 000001
	# 0011 1100 0000 0001 0001 0000 0000 0001
	# 0x3c011001
	
	syscall
	# R format opcode-0, rs-0, rt-0, rd-0, shamt(shift)-0, funct-12
 	# 000000 00000 00000 00000 00000 001100
 	# 0000 0000 0000 0000 0000 0000 0000 1100 #binary
 	# 0x0000000C #hex
 	
 	mult $t0, $t1
 	# R format opcode-0, rs-$t0 8, rt-$t1 9, rd-0, shamt(shift)-0, funct-18
 	# 000000 01000 01001 00000 00000 011000
 	# 0000 0001 0000 1001 0000 0000 0001 1000 #binary
 	# 0x01090018 #hex
 	
 	mflo $a0
 	# R format opcode-0, rs-0, rt-0, rd-$a0 4, shamt(shift)-0, funct-12
 	# 000000 00000 00000 00100 00000 010010
 	# 0000 0000 0000 0000 0010 0000 0001 0010 # binary
 	# 0x00002012 #hex
 	
 	ori $v0, $zero, 1
 	# ori opcode d(hex) - 13(dec), rs - $zero is register 0, rt - $v0 is register 2, IMM-1
 	# 001101 00000 00010 0000000000000001
 	# 0011 0100 0000 0010 0000 0000 0000 0001 #binary
 	# 0x34020001 #hex
 	
 	syscall
 	# R format opcode-0, rs-0, rt-0, rd-0, shamt(shift)-0, funct-12
 	# 000000 00000 00000 00000 00000 001100
 	# 0000 0000 0000 0000 0000 0000 0000 1100 #binary
 	# 0x0000000C #hex
 	
 	addi $v0, $zero, 10
 	# I format opcode-8, rs-$zero is 0, rt-$v0 is 2, IMM-10
 	# 001000 00000 00010 0000000000001010
 	# 0010 0000 0000 0010 0000 0000 0000 1010 #binary
 	# 0x2002000a #hex
 	
 	syscall
 	# R format opcode-0, rs-0, rt-0, rd-0, shamt(shift)-0, funct-12
 	# 000000 00000 00000 00000 00000 001100
 	# 0000 0000 0000 0000 0000 0000 0000 1100 #binary
 	# 0x0000000C #hex

.data
 result: .asciiz "15 * 3 is "
# HW Ch2Q2.asm
# Kyle Wood 1272942
# Play middle C for 1 second as a reed instrument using MIDI services
# Explain difference between two services that produce the output
# 31 - MIDI out generates tone and returns immediately
# 33 - MIDI out synchronous generates tone and returns upon completion
.text
main:
	# play MIDI sound
	li $v0, 31	# generate tone and return immediately
	li $a0, 60	# pitch, value range 0-127, middle C value 60
	li $a1, 1000	# duration, milliseconds
	li $a2, 69	# instrument, reed value range 64-71
	li $a3, 100	# volume, value range 0-127
	syscall
	
	# terminate execution
	li $v0, 10
	syscall
 

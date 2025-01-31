# Propgram:	ChatGPTDiscussion3.asm
# Author:	Kyle Wood 1272942
# Purpose:	ChatGPT program for tic tac toe

.data
board: .space 9     # The board, initially empty
player: .word 'X'   # Current player, 'X' or 'O'
newline: .asciiz "\n"
prompt: .asciiz "Enter a position (1-9): "
invalid_input: .asciiz "Invalid input. Please enter a number between 1 and 9.\n"
invalid_move: .asciiz "Invalid move. Position already taken.\n"
win_message: .asciiz "Congratulations! Player "
win_message2: .asciiz " wins!\n"
tie_message: .asciiz "It's a tie!\n"

.text
.globl main

main:
    # Print initial board
    jal print_board
    
    # Main game loop
game_loop:
    # Check for win or tie
    jal check_win
    bne $v0, $zero, end_game   # If there's a winner or a tie, end the game
    
    # Get player's move
    jal get_move
    
    # Update the board
    jal update_board
    
    # Print updated board
    jal print_board
    
    # Switch player
    lw $t0, player
    li $t1, 'X'
    li $t2, 'O'
    beq $t0, $t1, switch_player
    sw $t1, player
    j game_loop

switch_player:
    sw $t2, player
    j game_loop

get_move:
    # Prompt for input
    li $v0, 4
    la $a0, prompt
    syscall
    
    # Get input
    li $v0, 5
    syscall
    move $t0, $v0      # Move user input to $t0
    
    # Check if input is valid (between 1 and 9)
    li $t1, 1
    li $t2, 9
    blt $t0, $t1, invalid_input
    bgt $t0, $t2, invalid_input
    
    # Check if position is already taken
    sll $t3, $t0, 2    # Calculate offset for board array
    la $t4, board
    add $t4, $t4, $t3
    lw $t5, 0($t4)     # Load value at position
    bne $t5, ' ', invalid_move
    
    jr $ra

invalid_input:
    # Print error message for invalid input
    li $v0, 4
    la $a0, invalid_input
    syscall
    j get_move

invalid_move:
    # Print error message for invalid move
    li $v0, 4
    la $a0, invalid_move
    syscall
    j get_move

update_board:
    # Update the board with the player's move
    lw $t0, player
    sll $t1, $t0, 24      # Move player character to MSB of $t1
    sll $t2, $t0, 16      # Move player character to middle of $t2
    sll $t3, $t0, 8       # Move player character to middle of $t3
    lw $t4, 0($sp)        # Get user input
    add $t5, $t4, $t1     # Add player character to position
    add $t6, $t4, $t2     # Add player character to position
    add $t7, $t4, $t3     # Add player character to position
    sw $t5, 0($sp)        # Store updated position
    sw $t6, 0($sp)        # Store updated position
    sw $t7, 0($sp)        # Store updated position
    la $t8, board         # Load board address
    sw $t5, 0($t8)        # Store updated board
    sw $t6, 4($t8)        # Store updated board
    sw $t7, 8($t8)        # Store updated board

    jr $ra

print_board:
    # Print the current state of the board
    li $v0, 4
    la $a0, newline
    syscall
    la $t0, board
    lw $a0, 0($t0)
    syscall
    lw $a0, 4($t0)
    syscall
    lw $a0, 8($t0)
    syscall
    li $v0, 4
    la $a0, newline
    syscall
    li $v0, 4
    la $a0, newline
    syscall
    li $v0, 4
    la $a0, newline
    syscall
    jr $ra

check_win:
    # Check for a win or tie
    la $t0, board

    # Check rows
    lw $t1, 0($t0)
    lw $t2, 4($t0)
    lw $t3, 8($t0)
    beq $t1, $t2, check_row2
    beq $t1, $t3, check_row3
    j check_col1

check_row2:
    beq $t2, $t3, win
    j check_col1

check_row3:
    j check_col1

check_col1:
    lw $t1, 0($t0)
    lw $t2, 4($t0)
    lw $t3, 8($t0)
    beq $t1, $t2, check_col2
    beq $t1, $t3, check_col3
    j check_diag1

check_col2:
    beq $t2, $t3, win
    j check_diag1

check_col3:
    j check_diag1

check_diag1:
    lw $t1, 0($t0)
    lw $t2, 4($t0)
    lw $t3, 8($t0)
    beq $t1, $t2, check_diag2
    beq $t1, $t3, win
    j check_tie

check_diag2:
    beq $t2, $t3, win
    j check_tie

check_tie:
    # Check for a tie
    lw $t1, 0($t0)
    lw $t2, 4($t0)
    lw $t3, 8($t0)
    bne $t1, ' ', next_cell
    bne $t2, ' ', next_cell
    bne $t3, ' ', next_cell
    j tie

next_cell:
    addi $t0, $t0, 4
    lw $t1, 0($t0)
    lw $t2, 4($t0)
    lw $t3, 8($t0)
    bne $t1, ' ', next_cell
    bne $t2, ' ', next_cell
    bne $t3, ' ', next_cell
    j tie

win:
    # If we reach here, there's a winner
    li $v0, 4
    la $a0, win_message
    syscall
    lw $a0, player
    syscall
    la $a0, win_message2
    syscall
    li $v0, 10
    jr $ra

tie:
    # If we reach here, it's a tie
    li $v0, 4
    la $a0, tie_message
    syscall
    li $v0, 10
    jr $ra

end_game:
    # End the game
    li $v0, 10
    jr $ra

# This code will take a input double and store it into an array looping till zero is entered. 
# It then calls a sort function to sort the array from smallest to largest.
# It then calls a print function to print the array from smallest to largest, the number of inputs, the sum, and the average.
# This program was written by Yisak Worku Yxw190038 for CS2340.005, assignment 4, starting March 25, 2024.

		.include 		"SysCalls.asm"
		.data
inputDoubles:	.space 800 	# Allocate space for 100 double-precision numbers (8 bytes each)
count:		.word  0     	# Variable to store the count of entered numbers
input_prompt:	.asciiz 		"Enter a double-precision number (or 0 to exit): "

		.text
		.globl main
		.globl inputDoubles
		.globl count
main:
    			# Part 1: Main loop to input numbers
	li $t0, 100     	# Initialize loop counter to 100
	la $s0, inputDoubles
input_loop:
    			# Prompt user to input a double-precision number
	li $v0, SysPrintString# Print prompt
	la $a0, input_prompt
	syscall
	li $v0, SysReadDouble	# System call reading double
	syscall
    
    			# Check if the input number is zero
	c.eq.d $f0, $f30, 
	bc1t end_input_loop
    
    			# Store the input number in memory
	sdc1 $f0, 0($s0) 	# Store the double-precision number at the address pointed by $s0
	addi $s0, $s0, 8 	# Increment memory address by 8 bytes (size of double)
    
    			# Increment count of entered numbers
	lw $t1, count    	# Load count into $t1
	addi $t1, $t1, 1 	# Increment count by 1
	sw $t1, count    	# Store updated count
    
    			# Decrement loop counter
	subi $t0, $t0, 1
	bnez $t0, input_loop 	# Branch back to input_loop if counter is not zero

end_input_loop:

    			# Part 2: Call sorting function
	lw $a0, count   	# Load count of entered numbers into $a0
	jal sort_numbers 	# Jump and link to sorting function
    
	jal print_numbers
    
    			# End of program
	li $v0, SysExit      	# System call to exit program
	syscall


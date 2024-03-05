# This code will take a integer and convert it into an array of bits and by comparing the 1 to zeros it find all primes up to n. 
# It achives this by sieveing through the numbers first it removes all multiples of 2 then 3 then the all mutiples of the next remaining bit and so on till only primes remain
# It will also exclude any integers by excluding inputs < 3 and > 160,000 if such and input is entered it will error and prompt of a new input.
# This program was written by Yisak Worku Yxw190038 for CS2340.005, assignment 3, starting Feb 27, 2024.

		.include 	"SysCalls.asm"
		.data
userPrompt:	.asciiz	"\nEnter a number from 3 to 160,000: "
resultTxt:		.asciiz	"\nPrime numbers between 2 and "
resultTxtCont:	.asciiz	" are: "
badInputTxt:	.asciiz
newlineTxt:	.asciiz    "\n"
commaTxt:		.asciiz     ", "


	.text
main:
	li $v0, SysPrintString	# Load print string
	la $a0, userPrompt 		# Load prompt
	syscall 			# Print prompt

	li $v0, SysReadInt 		# Load read int opcode
	syscall 			# Read int input
	move $s0, $v0		# Store user input in $s0

	blt $s0, 3, inputError	# If input is less then 3 go to error
	bgt $s0, 160000, inputError	# If input is greater then 160000 go to error

				# Calculate number of bytes to nearest 8
	addi $t0, $s0, 7		# Add 7 t0 round up to nearest 8
	srl $t0, $t0, 3		# divide 8
	sll $t0, $t0, 3		# multiple 8

	 			# Get the number of bytes to allocate
	li $v0, SysAlloc 		# Load the heap-allocate opcode
	move $a0, $t0
	syscall 			# Allocate space on the heap
	move $s1, $v0		# Move the array of booleans

   	li $t1, 0xFF		# Initialize the boolean array to hex ff
	li $s2, 0 			# Initialize counter

bool_loop:
	sb $t1, ($s1)		# Set it to False
	beq $s0, $s2, endbool 	# If the max number has been reached
	addi $s1, $s1, 1		# Increase array pointer
	addi $s2, $s2, 1 		# Increase counter
	j bool_loop 		# Repeat the initialization loop

inputError:	
	li $v0, SysPrintString	# Load print string
	la $a0, badInputTxt 		# Load prompt
	syscall 			# Print prompt
	j main
endbool:

	li $s2, 1 			# Initialize counter

arrayLoop:
	addi $s2, $s2, 1 		# Increase the counter
	sll $s3, $s2, 1   		# Square the counter
	bgt $s3, $s0, exitLoops 		# If the counter is greater than the user input

	lb $s4, 0($s1)		# Load the current index of the boolean array
	beqz $s4, arrayLoop		# If the value is not 0 (untouched), do nothing
	sll $s5, $s2, 1		# Initialize inner counter to outer counter squared


primeFactorLoop:
	bgt $s5, $s0, arrayLoop	# If the inner counter passes the user input, done looping
	add $s6, $s5, $s1		# Calculate the current index of the bool array
	sb $s2, 0($s6)		# Set current index to anything not False
	add $s5, $s5, $s2		# inner counter += outer counter     
	j primeFactorLoop		# Redo inner loop

	j arrayLoop		# Repeat the loop

exitLoops:

	li $v0, SysPrintString	# Load the print string opcode
	la $a0, resultTxt		# Load the prime display
	syscall 			# Print the display

	li $v0, SysPrintInt		# Load the print int opcode
	move $a0, $s0		# Load the user input
	syscall			# Print the display

	li $v0, SysPrintString	# Load the print string opcode
	la $a0, resultTxtCont		# Load the prime display
	syscall			# Print the display


	li $s2, 2 			# Initialize counter
	li $v0, SysPrintInt		# Load the print int opcode
	move $a0, $s2		# starter prime 2
	syscall  			# Print the prime
printPrimes:
	addi $s2, $s2, 1 		# Increment boolean array
	bgt $s2, $s0, exit 		# If counter is greater than user input, exit
	add $s3, $s1, $s2		# Calculate boolean array offset
	lb $s4, 0($s3)		# Load current value in boolean array

	bnez $s4, printPrimes		# If current byte is not zero, reloop
				# Else print the prime

	li $v0, SysPrintString	# Load the print string opcode
	la $a0, commaTxt 		# Load the comma and space
	syscall			# Print `, `
	
	li $v0, SysPrintInt		# Load the print int opcode
	move $a0, $s2		# Load the current prime number
	syscall  			# Print the prime

	j printPrimes			# Repeat the print loop

exit:				# Done looping
	li $v0, SysPrintString	# Load the print string opcode
	la $a0, newlineTxt		# Load the newline
	syscall			# Print `\n`

	li $v0, SysExit		# Load exit opcode
	syscall			# Exit program
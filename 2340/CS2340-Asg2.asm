# This code will take a string and convert it into an integer by comparing it to zero and find the sum of all valid integers and keep count of vaild inputs. 
# It will also exclude any nonnumeric characters by excluding inputs < 0 and > 9 if such and input is entered it will count it as an error and prompt of a new input.
# Addtionally the code can accept negitve numbers by identifyimg a - at the begining of a string. Entering a blank input exits the code.
# This program was written by Yisak Worku Yxw190038 for CS2340.005, assignment 2, starting Feb 5, 2024.


		.include	"SysCalls.asm"
		.data	
integer_prompt:	.asciiz 	"Enter a number: "
errorText:		.asciiz 	"Error: Invalid input.\n"
errorCountText:	.asciiz 	"\nTotal number of errors: "
inputCountText:	.asciiz 	"\nCount of valid numbers = "
sumInputText:	.asciiz 	"Sum="
inputBuffer:	.space 12	# buffer to store user input

		.text
		
main:		li	$t0, 0			# Input sum initialized to zero
		li	$t1, 0			# Counter for valid numbers initialized to zero
		li	$t2, 0			# Counter for errors initialized to zero

input_loop:	li	$v0, SysPrintString		# System call to print string
		la	$a0, integer_prompt		# Adress of integer prompt
		syscall

		li	$v0, SysReadString		# System call to read string
		la	$a0, inputBuffer		# Adress of string input
		li	$a1, 12			# Adress storing string input ##
		syscall

		lb	$t3, inputBuffer		# Load first character of the input
		la	$t4, inputBuffer		# Load the address of first character of the input
		beq	$t3, '\n', display_results	# If newline, go to display results

						# Check for negative sign
		beq	$t3, '-', moveNextChar	# If negative sign, branch to check next digits
		blt	$t3, '0', inputErrorCounter	# If less than 0, branch to error not a digit
		bgt	$t3, '9', inputErrorCounter	# If greater than 9, branch to error not a digit
		j	readInputLoop		# Jump to input read loop

inputErrorCounter:	li	$v0, SysPrintString		# System call to print string
		la	$a0, errorText		# Adress of error text
		addi	$t2, $t2, 1		# Add 1 to the error counter
		syscall
		
		j	input_loop			# Jump to input loop to take new inputs

moveNextChar:	addi	$t4,$t4,1			# Move to the next charater in the input
	
readInputLoop:	lb	$t3, ($t4)			# Load current character to $t3
		beq	$t3, '\n', computeNegitveInput	# If its a new line character jump to computeNegitveInput to find its sign
		blt	$t3, '0', inputErrorCounter	# If less than 0, branch to error not a digit
		bgt	$t3, '9', inputErrorCounter	# If greater than 9, branch to error not a digit
		subi	$t3, $t3, '0'		# Subtract input number by 0 store in $t3 (ascii conversion)
		mul	$t5, $t5, 10		# Multiply by 10 to correctly place the digits
		add	$t5,$t3,$t5		# Add current digit to the right of the last one
		j	moveNextChar		# Jump to move to the next Character
	
computeNegitveInput:	lb	$t3, inputBuffer		# Load first character of the input
		bne	$t3, '-', computeSum		# If its a (-) minus sign
		mul 	$t5, $t5, -1		# Multiply the number by -1

computeSum:	add	$t0, $t0, $t5		# Add full number to sum
		add	$t5, $zero, $zero		# Reset address storing last input prepping for the next input

		addi	$t1, $t1, 1		# Add 1 to the vaild numbers counter
		j	input_loop			# Jump back to the input loop for next input

display_results:	li	$v0, SysPrintString		# System call to print string
		la	$a0, sumInputText		# Adress of input sum prompt
		syscall	
		
		li	$v0, SysPrintInt		# System call to print integer
		move	$a0, $t0			# Adress of  input sum
		syscall

		li	$v0, SysPrintString		# System call to print string
		la	$a0, inputCountText		# Adress of input counter prompt
		syscall

		li	$v0, SysPrintInt		# System call to print integer
		move	$a0, $t1			# Adress of input counter 
		syscall

		li	$v0, SysPrintString		# System call to print string
		la	$a0, errorCountText		# Adress of error counter prompt
		syscall

		li	$v0, SysPrintInt		# System call to print integer
		move	$a0, $t2			# Adress of error counter
		syscall

exit_program:	li	$v0, SysExit		# Exit program
		syscall

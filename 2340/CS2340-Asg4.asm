# This code will take a input sting and pass it to a palindrome checker function. 
# If the input was a palindrome it will recive a 1 and print confermation if not then it will recive a 0 print not a palindrome.
# It will loop asking for and input till reciving a null input.
# This program was written by Yisak Worku Yxw190038 for CS2340.005, assignment 4, starting March 16, 2024.

		.include 		"SysCalls.asm"
		.data
inputPrompt: 	.asciiz 		"Enter a string: "
msgPalindrome: 	.asciiz 		"Palindrome\n"
msgNoPalindrome: 	.asciiz 		"Not a palindrome\n"
string_buffer:	.space 200  	# Buffer to store input string

		.text
	

main:
				# Print prompt
	la $a0, inputPrompt  		# Load message address into $a0
	li $v0, SysPrintString
	syscall  			# Print string using syscall
				# Read string from user
	la $a0, string_buffer		# Load buffer address into $a0
	li $v0, SysReadString		# syscall for read string
	li $a1, 200
	syscall 			# Read string
				# Check for empty string
	lb $t0, ($a0)
	beq $t0, '\n',exit 		# Exit if string is empty
				# Call function to check palindrome
	jal  is_palindrome
				#  Print result
	beq $v0, 0, printNoPalindrome  	# Print "Not a palindrome"

printPalindrome:
	li $v0, SysPrintString
	la $a0, msgPalindrome		# Load message address into $a0
	syscall 			# Print string using syscall
	j loop1 			# Jump back to prompt

printNoPalindrome:
	li $v0, SysPrintString
	la $a0, msgNoPalindrome	# Load message address into $a0
	syscall 			# Print string using syscall

loop1:
	j main  			# Jump back to main

exit:
	li $v0, SysExit  		# syscall for exit
	syscall 			# Exit program

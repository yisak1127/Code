# This code will take a input string from the main function and filter out all non alphanumerics and convert text into lowercase. 
# Once it does that it compares the ends of the string with one another and if they match it moves to the next most outer set if they don't it returns a zero.
# Once the ends meet or cross all pairs have been checked and its a palindrome so the function returns 1.
# This program was written by Yisak Worku Yxw190038 for CS2340.005, assignment 4, starting March 16, 2024

		.text
		.globl is_palindrome
		.include		"SysCalls.asm"

is_palindrome:
				# Base case: empty or single-character string is palindrome
				# Find the ends of the string
	move $t1, $a0		# Store the starting address of the string
findStringEnd:
	lb $t2, ($a0)		# Load character from current address
	beqz $t2, findMiddle		# If null terminator, go to find middle
	addi $a0, $a0, 1		# Move to the next character
	j findStringEnd		# Repeat until null terminator is found

findMiddle:
	subi $t2, $a0, 2		# Adjust end address to point to the last character
 	sub $t0, $t2, $t1		# find the diffrence between front and back
 	srl $t0, $t0, 2		# divde by 2 to find middle
 	sub $t0, $t2, $t0		# address of middle
	lb $t3, ($t1)		# Load character from the start of the string
	lb $t4, ($t2)		# Load character from the end of the string
	j frontFilter

next_front:
	addi $t1, $t1, 1 		# move font pointer to next character
	lb $t3, ($t1)		# Load character from the start of the string 
	j frontFilter

next_last: 
	subi $t2, $t2, 1		# Move to the previous character from the end
	lb $t4, ($t2)		# Load character from the start of the string
	j backFilter      
    
frontFilter:			# filter start
	blt $t3, '0',  next_front	# filter out under zero
	bgt $t3, 'z',  next_front	# filter out over z
	ble $t3, '9',  backFilter	# accept 0 to 9
	blt $t3, 'A',  next_front	# filter out under A
	ble $t3, 'Z',  backFilter	# accept A to Z
	blt $t3, 'a',  next_front	# filter out under a
	
backFilter:			# filter start
	blt $t4, '0',  next_last 	# filter out under zero
	bgt $t4, 'z',  next_last 	# filter out over z
	ble $t4, '9',  palindrome_loop	# accept 0 to 9
	blt $t4, 'A',  next_last 	# filter out under A
	ble $t4, 'Z',  palindrome_loop	# accept A to Z
	blt $t4, 'a',  next_last 	# filter out under a
	
palindrome_loop: 
	beq $t1, $t2, is_palindrome_true	# Base case: reached middle of string, it's a palindrome
	bge $t1, $t0, is_palindrome_true	# Base case: reached cross over of string, it's a palindrome
	
	ble $t3, '9', lowerCaseCheck	# if start is a number continue 
	bge $t3, 'a', lowerCaseCheck	# if start is a lowercase continue
	addi $t3, $t3, lowercase	# convert to lowercase

lowerCaseCheck:   
	ble $t4, '9', matchCheck	# if end is a number continue
	bge $t4, 'a', matchCheck	# if end is a lowercase continue
	addi $t4, $t4, lowercase 	# convert to lowercase
	move $a0, $t3		# Load message address into $a0
	
matchCheck:  
li	$v0, SysPrintInt	# System call to print int
	move	$a0, $t3		# Adress of sum
	syscall
	li	$v0, SysPrintInt	# System call to print int
	move	$a0, $t4		# Adress of sum
	syscall
	beq $t3, $t4, nextCharSet	# Characters match, continue palindrome check
	
not_palindrome:
	li $v0, 0			# Not a palindrome, set result to 0
	jr $ra			# Return
	
nextCharSet:
	addi $t1, $t1, 1		# Move to the next character from the start
	subi $t2, $t2, 1		# Move to the previous character from the end
	j frontFilter		# Continue palindrome check

is_palindrome_true:
	li $v0, 1			# Palindrome, set result to 1
	jr $ra			# Return

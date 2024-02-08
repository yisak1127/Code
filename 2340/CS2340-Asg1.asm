# This code will compute and update a sum and counter of given integers untill a zero is entered
# This program was written by Yisak Worku Yxw190038 for CS2340.005, assignment 1, starting Feb 2, 2024.
#

	.include	"SysCalls.asm"
	.data	
prompt:	.asciiz "Enter an integer: "
sumText:	.asciiz "The sum is: "
countText:	.asciiz "\nThe number of integers entered was: "
	
	.text 

main:	la	$a0, prompt	# Adress of integer prompt
	li	$v0, SysPrintString	# System call to print string
	syscall
	
	li 	$v0, SysReadInt	# System call to read int
	syscall	
	beqz	$v0, printResults	# branch if int equals zero to print results
	
	add	$t0, $t0, $v0	# add new integer to sum
	addi	$t1, $t1, 1	# add 1 to counter
	
	j	main		# jump to start of main loop
	
printResults:
	li	$v0, SysPrintString	# System call to print string
	la	$a0, sumText	# Adress of sum text
	syscall
	
	li	$v0, SysPrintInt	# System call to print int
	move	$a0, $t0		# Adress of sum
	syscall
	
	li 	$v0, SysPrintString	# System call to print string
	la	$a0, countText	# Adress of counter text
	syscall
	
	li	$v0, SysPrintInt	# System call to print int
	move	$a0, $t1		# Adress of counter
	syscall
		
	li	$v0, SysExit	# System call to exit
	syscall

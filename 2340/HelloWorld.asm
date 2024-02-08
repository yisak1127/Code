#	Simple hello world program for CS2340.005
#
##	.include "SysCalls.asm"
	.data 
hello:	.asciiz "Hello world!"
	
	.text 
main:	la	$a0, hello	# Adress of string to print
	li	$v0, 4	# Magic number to print string
	syscall
	li	$v0, 10	# System call to exit
	syscall 
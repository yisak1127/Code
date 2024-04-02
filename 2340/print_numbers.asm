# This code is a print function it takes a double array and prints it, its sum, average, and count. 
# It will keep a sum of all input doubles to print and use that sum divided by the count to calcuate the average.
# This program was written by Yisak Worku Yxw190038 for CS2340.005, assignment 4, starting March 25, 2024.

		.include 		"SysCalls.asm"
		.data
countPrompt: 	.asciiz 	"Counting: "
sumPrompt: 		.asciiz 	"Sum: "
avgPrompt: 		.asciiz 	"Average: "
nlPrompt: 		.asciiz 	"\n"
		.text
		.globl print_numbers

print_numbers:
   	move $s0, $ra       	# Save return address

    	li $t0, 0           	# Initialize sum to 0
    	li $t1, 0           	# Initialize index to 0
    	la $a1, inputDoubles	# Load address of numbers array
    	ldc1 $f10, count 	# Load count of entered numbers into $f10
    	move $t2, $a0	# Load count of entered numbers into $T2
print_loop:
    			# Check if index is less than count
    	bge $t1, $t2, prtResults# If index >= count, exit loop
    
    	l.d $f12, 0($a1)    	# Load current number into $f12
    
   	li $v0, 3          	# Print current number
    	syscall

    	li $v0, SysPrintString# Print newline
   	la $a0, nlPrompt     	# Load address of newline string into $a0
    	syscall
    
    	add.d $f8, $f8, $f12 	# Add current number to sum
    
    	addi $t1, $t1, 1    	# Increment index by 1
    	addi $a1, $a1, 8  	# Move to next double in array
    
    	j print_loop        	# Jump back to print_loop

prtResults:
			# Print newline
    	li $v0, SysPrintString# System call for printing string
    	la $a0, countPrompt  	# Load address of count prompt string
    	syscall
    	
    	cvt.d.w $f12, $f10	# Convert sum to double for print count of entered numbers
    	li $v0, SysPrintDouble# System call for printing double
    	syscall
    
    			# Print newline
    	li $v0, SysPrintString# System call for printing string
    	la $a0, nlPrompt     	# Load address of newline string into $a0
    	syscall
			# Print newline
    	li $v0, SysPrintString# System call for printing string
    	la $a0, sumPrompt     	# Load address of sum prompt string
    	syscall
    	
    	mov.d $f12, $f8	# Move sum to print sum of entered numbers
    	li $v0, SysPrintDouble# System call for printing double
    	syscall
    
    			# Print newline
    	li $v0, SysPrintString# System call for printing string
    	la $a0, nlPrompt     	# Load address of newline string into $a0
    	syscall
    			# Print newline
    	li $v0, SysPrintString# System call for printing string
    	la $a0, avgPrompt     	# Load address of average prompt string
    	syscall
    			# Calculate and print average of entered numbers
    	cvt.d.w $f8, $f10    	# Convert count to double
    	div.d $f12, $f12, $f8	# Divide sum by count
    	li $v0, SysPrintDouble# System call for printing double
    	syscall

    			# End of printing function
    	move $ra, $s0       	# Restore return address
    	jr $ra              	# Return to caller

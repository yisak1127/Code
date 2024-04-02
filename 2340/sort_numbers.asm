# This code is the sort function it takes a double array and applies a bubble sort. 
# It compares a pair of doubles and if the second is smaller it swaps addresses.
# It will loop through the array till it is fully sorted.
# This program was written by Yisak Worku Yxw190038 for CS2340.005, assignment 4, starting March 25, 2024.

			.include 		"SysCalls.asm"
			.globl sort_numbers
			
			# Sorting function (Bubble Sort)
sort_numbers:
	move $s0, $ra   	# Save return address
    
	li $t0, 1      	# Flag to indicate whether a swap occurred
	li $t1, 0     	# Outer loop counter
    
arrayLoop:
	li $t0, 0       	# Reset swap flag
	move $t2, $zero   	# Reset inner loop counter
    
bubbleLoop:
    			# Calculate array indices for comparison
	sll $t3, $t2, 3     	# Multiply inner loop counter by 8 to get byte offset
	la $t6, inputDoubles	# Base address of numbers array
	add $t4, $t3, $t6 	# Add byte offset to base address of numbers array
	l.d $f2, 0($t4)    	# Load current element (number) into $f2
    
	addi $t5, $t4, 8   	# Calculate address of next element
	l.d $f4, 0($t5)    	# Load next element into $f4
    
    			# Compare elements
	c.lt.d $f4, $f2    	# Compare $f2 with $f4
	bc1t swap_doubles 	# Branch if $f4 < $f2 to swap_elements
    
	addi $t2, $t2, 1	# Increment inner loop counter
	subi $t3, $a0, 1
			# Branch back to inner_loop if counter is less than count
    	blt $t2, $t3, bubbleLoop
	addi $t1, $t1, 1	# Increment outer loop counter
			# Branch back to outer_loop if counter is less than count
    	blt $t1, $t3, arrayLoop
    			# If no swaps occurred, array is sorted
	beq $t0, $zero, exitSort
    			# If swaps occurred, repeat sorting process
	j arrayLoop
    
swap_doubles:
    			# Swap elements
	s.d $f4, 0($t4) 	# Store $f4 at the address of $t4
	s.d $f2, 0($t5)     	# Store $f2 at the address of $t5
    
	li $t0, 1       	# Set swap flag to 1
    
	j bubbleLoop
    
exitSort:
	move $ra, $s0   	# Restore return address
	jr $ra          	# Return to caller

# as output.s -o output.o
# ld -dynamic-linker /lib/ld-linux.so.2 -o output -lc output.o
# ./output


.section .data					# MEM
	filo:	.space 4			# allocates space for STACK based on TAC
	temp:	.space 16			# allocates space for HEAP based on TAC.

	intf:	.string "%d\n"			# integer format for printing.
	
		.equ LINUX_SYSCALL , 0x80	# alias for invoking a system call through INT.

#------------------------------------------------------------------------------

.section .text					# CODE
	.extern printf
	.global _start				# enables linker (ld) to see it.
	.align 4				# ensures word (4 bytes, 32 bits) align of instructions.
	
	_start:	MOVL  $filo , %ECX		# register %ECX gets SP reference.
		MOVL  $temp , %EDX		# register %EDX gets Rx reference.

	_000:	LEAL (%EDX) , %EAX
		PUSHL  %EAX
		MOVL $0 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_001:	MOVL  (%EDX) , %EAX
		IMULL $4 , %EAX
		MOVL  %EAX ,(%EDX)

	_002:	MOVL  (%EDX) , %EAX
		SUBL  $0 , %EAX
		MOVL  %EAX ,(%EDX)

	_003:	LEAL 4(%EDX) , %EAX
		PUSHL  %EAX
		MOVL (%EDX) , %EAX
		LEAL (%ECX) , %EBX
		ADDL %EBX , %EAX
		POPL  %EBX
		MOVL (%EAX) , %EAX
		MOVL %EAX , (%EBX)

	_004:	LEAL 4(%EDX) , %EAX
		PUSHL  %EAX
		MOVL $10 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_005:	LEAL 8(%EDX) , %EAX
		PUSHL  %EAX
		MOVL $0 , %EBX
		POPL %EAX
		MOVL %EBX , (%EAX)

	_006:	MOVL  8(%EDX) , %EAX
		IMULL $4 , %EAX
		MOVL  %EAX ,8(%EDX)

	_007:	MOVL  8(%EDX) , %EAX
		SUBL  $0 , %EAX
		MOVL  %EAX ,8(%EDX)

	_008:	LEAL 12(%EDX) , %EAX
		PUSHL  %EAX
		MOVL 8(%EDX) , %EAX
		LEAL (%ECX) , %EBX
		ADDL %EBX , %EAX
		POPL  %EBX
		MOVL (%EAX) , %EAX
		MOVL %EAX , (%EBX)

	_009:	PUSHL  %ECX
		PUSHL  %EDX
		PUSHL  12(%EDX)
		PUSHL  $intf
		CALL printf
		POPL  %EAX
		POPL  %EAX
		POPL  %EDX
		POPL  %ECX

	_exit:	MOVL $1 , %EAX 
		MOVL $0 , %EBX 
		INT $LINUX_SYSCALL
.end

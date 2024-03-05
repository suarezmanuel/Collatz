.text
.globl	main
	.type	main, @function

# iterative implementation of Collatz
main:

	pushq	%rbp
	movq	%rsp,	%rbp

    # rax will count iterations
    movq    $1, %rax
    # rdi is given val
    cmpq    $1, %rdi
    je .finished

.loop:

    test    %rdi, 1
    jnz     .odd
    
    # divide even number by two
    shrq     %rdi, 1
    jmp .loop_end

.odd:

    # multiply by 3 and add 1
    imulq   %rdi, 3
    incq    %rdi

.loop_end:

    # add to counter
    incq    %rax
    cmpq    $1, %rdi
    jne     .loop

.finished:

	movq	%rbp, %rsp
	popq	%rbp	
	ret
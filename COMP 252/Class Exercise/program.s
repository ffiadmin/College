	.file	"program.c"
	.text
	.globl	divide
	.type	divide, @function
divide:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	16(%ebp), %eax
	movl	$555, (%eax)
	movq	%rax, %rbx
	movl	8(%ebp), %eax
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	12(%ebp)
	movl	%edx,(%rbx)
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
.LFE0:
	.size	divide, .-divide
	.section	.rodata
	.align 4
.LC0:
	.string	"High word 0x%.8x, low word 0x%.8x\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	leal	24(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$47, 4(%esp)
	movl	$8975, (%esp)
	call	divide
	movl	%eax, 28(%esp)
	movl	24(%esp), %edx
	movl	$.LC0, %eax
	movl	28(%esp), %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

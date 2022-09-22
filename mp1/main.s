	.file	"main.c"
	.text
	.section	.rodata
.LC0:
	.string	"input.txt"
.LC1:
	.string	"a"
.LC2:
	.string	"output.txt"
.LC3:
	.string	"From process %d: %c%c%c%c%c\n"
	.text
	.globl	read_chars
	.type	read_chars, @function
read_chars:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	-20(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, -16(%rbp)
	movl	$2, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	open@PLT
	movl	%eax, -12(%rbp)
	movl	-16(%rbp), %eax
	movslq	%eax, %rcx
	movl	-12(%rbp), %eax
	movl	$0, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	lseek@PLT
	movq	-32(%rbp), %rcx
	movl	-12(%rbp), %eax
	movl	$5, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	leaq	.LC0(%rip), %rax
	movl	%eax, %edi
	call	close@PLT
	leaq	.LC1(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	fopen@PLT
	movq	%rax, -8(%rbp)
	movq	-32(%rbp), %rax
	addq	$4, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %edi
	movq	-32(%rbp), %rax
	addq	$3, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %esi
	movq	-32(%rbp), %rax
	addq	$2, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %r9d
	movq	-32(%rbp), %rax
	addq	$1, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %r8d
	movq	-32(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %ecx
	movl	-20(%rbp), %edx
	movq	-8(%rbp), %rax
	pushq	%rdi
	pushq	%rsi
	leaq	.LC3(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	addq	$16, %rsp
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	read_chars, .-read_chars
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$1, -20(%rbp)
	call	fork@PLT
	movl	$1, -24(%rbp)
	call	getppid@PLT
	cmpl	$1, %eax
	jne	.L3
	movl	$0, -24(%rbp)
	call	fork@PLT
.L3:
	call	getppid@PLT
	cmpl	$1, %eax
	je	.L4
	cmpl	$1, -24(%rbp)
	je	.L4
	movl	$2, -24(%rbp)
.L4:
	leaq	-13(%rbp), %rdx
	movl	-24(%rbp), %eax
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	read_chars
	movl	$0, %edx
	movl	$0, %esi
	movl	$-1, %edi
	movl	$0, %eax
	call	waitpid@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L6
	call	__stack_chk_fail@PLT
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.2.0-19ubuntu1) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:

	.file	"naming_decoration.cpp"
	.text
	.globl	_Z4gfunv
	.def	_Z4gfunv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4gfunv
_Z4gfunv:
.LFB45:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	$10, -4(%rbp)
	nop
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z4gfuni
	.def	_Z4gfuni;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4gfuni
_Z4gfuni:
.LFB46:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	16(%rbp), %eax
	movl	%eax, -4(%rbp)
	nop
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z4gfund
	.def	_Z4gfund;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4gfund
_Z4gfund:
.LFB47:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movsd	%xmm0, 16(%rbp)
	pxor	%xmm0, %xmm0
	cvtsd2ss	16(%rbp), %xmm0
	movss	%xmm0, -4(%rbp)
	nop
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB48:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	call	_Z4gfunv
	movl	$10, %ecx
	call	_Z4gfuni
	movq	.LC0(%rip), %rax
	movq	%rax, %xmm0
	call	_Z4gfund
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC0:
	.long	-1546188227
	.long	1076247920
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-Builds project) 13.2.0"

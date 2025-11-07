	.file	"constexpr.cpp"
	.text
	.p2align 4
	.globl	_Z9function1ii
	.type	_Z9function1ii, @function
_Z9function1ii:
.LFB2457:
	.cfi_startproc
	endbr64
	movl	%edi, %eax
	imull	%esi, %eax
	ret
	.cfi_endproc
.LFE2457:
	.size	_Z9function1ii, .-_Z9function1ii
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"This is the cpp code to understand the constexpr in cpp \n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB2458:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$57, %edx
	leaq	.LC0(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE2458:
	.size	main, .-main
	.p2align 4
	.type	_GLOBAL__sub_I__Z9function1ii, @function
_GLOBAL__sub_I__Z9function1ii:
.LFB3027:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	leaq	_ZStL8__ioinit(%rip), %rbp
	movq	%rbp, %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	movq	%rbp, %rsi
	popq	%rbp
	.cfi_def_cfa_offset 8
	leaq	__dso_handle(%rip), %rdx
	jmp	__cxa_atexit@PLT
	.cfi_endproc
.LFE3027:
	.size	_GLOBAL__sub_I__Z9function1ii, .-_GLOBAL__sub_I__Z9function1ii
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z9function1ii
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0"
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

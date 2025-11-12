	.file	"source_code.cpp"
	.text
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
	.align 4
	.type	_ZN9__gnu_cxxL21__default_lock_policyE, @object
	.size	_ZN9__gnu_cxxL21__default_lock_policyE, 4
_ZN9__gnu_cxxL21__default_lock_policyE:
	.long	2
	.align 8
	.type	_ZNSt8__detailL25__platform_wait_alignmentE, @object
	.size	_ZNSt8__detailL25__platform_wait_alignmentE, 8
_ZNSt8__detailL25__platform_wait_alignmentE:
	.quad	4
	.align 4
	.type	_ZNSt8__detailL25__atomic_spin_count_relaxE, @object
	.size	_ZNSt8__detailL25__atomic_spin_count_relaxE, 4
_ZNSt8__detailL25__atomic_spin_count_relaxE:
	.long	12
	.align 4
	.type	_ZNSt8__detailL19__atomic_spin_countE, @object
	.size	_ZNSt8__detailL19__atomic_spin_countE, 4
_ZNSt8__detailL19__atomic_spin_countE:
	.long	16
	.type	_ZN6__pstl9execution2v1L3seqE, @object
	.size	_ZN6__pstl9execution2v1L3seqE, 1
_ZN6__pstl9execution2v1L3seqE:
	.zero	1
	.type	_ZN6__pstl9execution2v1L3parE, @object
	.size	_ZN6__pstl9execution2v1L3parE, 1
_ZN6__pstl9execution2v1L3parE:
	.zero	1
	.type	_ZN6__pstl9execution2v1L9par_unseqE, @object
	.size	_ZN6__pstl9execution2v1L9par_unseqE, 1
_ZN6__pstl9execution2v1L9par_unseqE:
	.zero	1
	.type	_ZN6__pstl9execution2v1L5unseqE, @object
	.size	_ZN6__pstl9execution2v1L5unseqE, 1
_ZN6__pstl9execution2v1L5unseqE:
	.zero	1
	.globl	globalvariable
	.bss
	.align 4
	.type	globalvariable, @object
	.size	globalvariable, 4
globalvariable:
	.zero	4
	.globl	globalvariable1
	.data
	.align 4
	.type	globalvariable1, @object
	.size	globalvariable1, 4
globalvariable1:
	.long	223
	.section	.rodata
.LC0:
	.string	"@ A class constructor \n"
	.section	.text._ZN1AC2Ev,"axG",@progbits,_ZN1AC5Ev,comdat
	.align 2
	.weak	_ZN1AC2Ev
	.type	_ZN1AC2Ev, @function
_ZN1AC2Ev:
.LFB3449:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	$40, %edi
	call	_Znam@PLT
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	leaq	24(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-8(%rbp), %rax
	leaq	74(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 16(%rax)
	movq	-8(%rbp), %rax
	movabsq	$2333279541225810753, %rsi
	movabsq	$2335514848431006050, %rdi
	movq	%rsi, 24(%rax)
	movq	%rdi, 32(%rax)
	movq	$8275, 40(%rax)
	movq	$0, 48(%rax)
	movq	$0, 56(%rax)
	movq	$0, 64(%rax)
	movw	$0, 72(%rax)
	movq	-8(%rbp), %rax
	movabsq	$2335514848431006018, %rsi
	movabsq	$8245080915159442803, %rdi
	movq	%rsi, 74(%rax)
	movq	%rdi, 82(%rax)
	movq	$27233, 90(%rax)
	movq	$0, 98(%rax)
	movq	$0, 106(%rax)
	movq	$0, 114(%rax)
	movw	$0, 122(%rax)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	-8(%rbp), %rax
	leaq	24(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3449:
	.size	_ZN1AC2Ev, .-_ZN1AC2Ev
	.weak	_ZN1AC1Ev
	.set	_ZN1AC1Ev,_ZN1AC2Ev
	.section	.rodata
.LC1:
	.string	"@ A class destructor \n"
	.section	.text._ZN1AD2Ev,"axG",@progbits,_ZN1AD5Ev,comdat
	.align 2
	.weak	_ZN1AD2Ev
	.type	_ZN1AD2Ev, @function
_ZN1AD2Ev:
.LFB3452:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA3452
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	.LC1(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3452:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table._ZN1AD2Ev,"aG",@progbits,_ZN1AD5Ev,comdat
.LLSDA3452:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3452-.LLSDACSB3452
.LLSDACSB3452:
.LLSDACSE3452:
	.section	.text._ZN1AD2Ev,"axG",@progbits,_ZN1AD5Ev,comdat
	.size	_ZN1AD2Ev, .-_ZN1AD2Ev
	.weak	_ZN1AD1Ev
	.set	_ZN1AD1Ev,_ZN1AD2Ev
	.section	.rodata
	.align 8
.LC2:
	.string	"This is the program to undertsand the cpp code example code is unique_ptr in cpp \n"
.LC3:
	.string	"Akshaya baalaji"
.LC4:
	.string	"Value ptr1 = "
.LC5:
	.string	"ptr1 =  "
	.align 8
.LC6:
	.string	"Value ptr1 After changing value  = "
.LC7:
	.string	"\n\nValue ptr11 = "
.LC8:
	.string	"ptr11 =  "
	.align 8
.LC9:
	.string	"Value ptr11 After changing value  = "
	.text
	.globl	main
	.type	main, @function
main:
.LFB3454:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA3454
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	.LC2(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
.LEHB0:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	.LC3(%rip), %rax
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy@PLT
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt11make_uniqueI1AJEENSt9_MakeUniqIT_E15__single_objectEDpOT0_
.LEHE0:
	leaq	.LC4(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
.LEHB1:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	.LC5(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt10unique_ptrI1ASt14default_deleteIS0_EEptEv
	movq	8(%rax), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-80(%rbp), %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt10unique_ptrI1ASt14default_deleteIS0_EEptEv
	movq	%rbx, 8(%rax)
	leaq	.LC6(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	.LC5(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt10unique_ptrI1ASt14default_deleteIS0_EEptEv
	movq	8(%rax), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	.LC7(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	.LC8(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt10unique_ptrI1ASt14default_deleteIS0_EEptEv
	movq	16(%rax), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt10unique_ptrI1ASt14default_deleteIS0_EEptEv
	movq	16(%rax), %rax
	movb	$98, (%rax)
	leaq	.LC9(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	leaq	.LC8(%rip), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt10unique_ptrI1ASt14default_deleteIS0_EEptEv
	movq	16(%rax), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE1:
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt10unique_ptrI1ASt14default_deleteIS0_EED1Ev
	movl	$0, %eax
	movq	-24(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L6
	jmp	.L8
.L7:
	endbr64
	movq	%rax, %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt10unique_ptrI1ASt14default_deleteIS0_EED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB2:
	call	_Unwind_Resume@PLT
.LEHE2:
.L8:
	call	__stack_chk_fail@PLT
.L6:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3454:
	.section	.gcc_except_table,"a",@progbits
.LLSDA3454:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3454-.LLSDACSB3454
.LLSDACSB3454:
	.uleb128 .LEHB0-.LFB3454
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB3454
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L7-.LFB3454
	.uleb128 0
	.uleb128 .LEHB2-.LFB3454
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE3454:
	.text
	.size	main, .-main
	.section	.text._ZSt11make_uniqueI1AJEENSt9_MakeUniqIT_E15__single_objectEDpOT0_,"axG",@progbits,_ZSt11make_uniqueI1AJEENSt9_MakeUniqIT_E15__single_objectEDpOT0_,comdat
	.weak	_ZSt11make_uniqueI1AJEENSt9_MakeUniqIT_E15__single_objectEDpOT0_
	.type	_ZSt11make_uniqueI1AJEENSt9_MakeUniqIT_E15__single_objectEDpOT0_, @function
_ZSt11make_uniqueI1AJEENSt9_MakeUniqIT_E15__single_objectEDpOT0_:
.LFB3777:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA3777
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movl	$128, %edi
.LEHB3:
	call	_Znwm@PLT
.LEHE3:
	movq	%rax, %rsi
	movq	%rsi, -32(%rbp)
	movq	%rsi, %rdi
.LEHB4:
	call	_ZN1AC1Ev
.LEHE4:
	movq	-24(%rbp), %rax
	movq	-32(%rbp), %rsi
	movq	%rax, %rdi
	call	_ZNSt10unique_ptrI1ASt14default_deleteIS0_EEC1IS2_vEEPS0_
	jmp	.L13
.L12:
	endbr64
	movq	%rax, %rbx
	movl	$128, %esi
	movq	-32(%rbp), %rdi
	call	_ZdlPvm@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB5:
	call	_Unwind_Resume@PLT
.LEHE5:
.L13:
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3777:
	.section	.gcc_except_table
.LLSDA3777:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3777-.LLSDACSB3777
.LLSDACSB3777:
	.uleb128 .LEHB3-.LFB3777
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB4-.LFB3777
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L12-.LFB3777
	.uleb128 0
	.uleb128 .LEHB5-.LFB3777
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
.LLSDACSE3777:
	.section	.text._ZSt11make_uniqueI1AJEENSt9_MakeUniqIT_E15__single_objectEDpOT0_,"axG",@progbits,_ZSt11make_uniqueI1AJEENSt9_MakeUniqIT_E15__single_objectEDpOT0_,comdat
	.size	_ZSt11make_uniqueI1AJEENSt9_MakeUniqIT_E15__single_objectEDpOT0_, .-_ZSt11make_uniqueI1AJEENSt9_MakeUniqIT_E15__single_objectEDpOT0_
	.section	.text._ZNSt10unique_ptrI1ASt14default_deleteIS0_EED2Ev,"axG",@progbits,_ZNSt10unique_ptrI1ASt14default_deleteIS0_EED5Ev,comdat
	.align 2
	.weak	_ZNSt10unique_ptrI1ASt14default_deleteIS0_EED2Ev
	.type	_ZNSt10unique_ptrI1ASt14default_deleteIS0_EED2Ev, @function
_ZNSt10unique_ptrI1ASt14default_deleteIS0_EED2Ev:
.LFB3779:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE6_M_ptrEv
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L15
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt10unique_ptrI1ASt14default_deleteIS0_EE11get_deleterEv
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt4moveIRP1AEONSt16remove_referenceIT_E4typeEOS4_
	movq	(%rax), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
	call	_ZNKSt14default_deleteI1AEclEPS0_
.L15:
	movq	-24(%rbp), %rax
	movq	$0, (%rax)
	nop
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3779:
	.size	_ZNSt10unique_ptrI1ASt14default_deleteIS0_EED2Ev, .-_ZNSt10unique_ptrI1ASt14default_deleteIS0_EED2Ev
	.weak	_ZNSt10unique_ptrI1ASt14default_deleteIS0_EED1Ev
	.set	_ZNSt10unique_ptrI1ASt14default_deleteIS0_EED1Ev,_ZNSt10unique_ptrI1ASt14default_deleteIS0_EED2Ev
	.section	.text._ZNKSt10unique_ptrI1ASt14default_deleteIS0_EEptEv,"axG",@progbits,_ZNKSt10unique_ptrI1ASt14default_deleteIS0_EEptEv,comdat
	.align 2
	.weak	_ZNKSt10unique_ptrI1ASt14default_deleteIS0_EEptEv
	.type	_ZNKSt10unique_ptrI1ASt14default_deleteIS0_EEptEv, @function
_ZNKSt10unique_ptrI1ASt14default_deleteIS0_EEptEv:
.LFB3783:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt10unique_ptrI1ASt14default_deleteIS0_EE3getEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3783:
	.size	_ZNKSt10unique_ptrI1ASt14default_deleteIS0_EEptEv, .-_ZNKSt10unique_ptrI1ASt14default_deleteIS0_EEptEv
	.section	.text._ZNSt15__uniq_ptr_dataI1ASt14default_deleteIS0_ELb1ELb1EECI2St15__uniq_ptr_implIS0_S2_EEPS0_,"axG",@progbits,_ZNSt15__uniq_ptr_dataI1ASt14default_deleteIS0_ELb1ELb1EECI5St15__uniq_ptr_implIS0_S2_EEPS0_,comdat
	.align 2
	.weak	_ZNSt15__uniq_ptr_dataI1ASt14default_deleteIS0_ELb1ELb1EECI2St15__uniq_ptr_implIS0_S2_EEPS0_
	.type	_ZNSt15__uniq_ptr_dataI1ASt14default_deleteIS0_ELb1ELb1EECI2St15__uniq_ptr_implIS0_S2_EEPS0_, @function
_ZNSt15__uniq_ptr_dataI1ASt14default_deleteIS0_ELb1ELb1EECI2St15__uniq_ptr_implIS0_S2_EEPS0_:
.LFB3907:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EEC2EPS0_
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3907:
	.size	_ZNSt15__uniq_ptr_dataI1ASt14default_deleteIS0_ELb1ELb1EECI2St15__uniq_ptr_implIS0_S2_EEPS0_, .-_ZNSt15__uniq_ptr_dataI1ASt14default_deleteIS0_ELb1ELb1EECI2St15__uniq_ptr_implIS0_S2_EEPS0_
	.weak	_ZNSt15__uniq_ptr_dataI1ASt14default_deleteIS0_ELb1ELb1EECI1St15__uniq_ptr_implIS0_S2_EEPS0_
	.set	_ZNSt15__uniq_ptr_dataI1ASt14default_deleteIS0_ELb1ELb1EECI1St15__uniq_ptr_implIS0_S2_EEPS0_,_ZNSt15__uniq_ptr_dataI1ASt14default_deleteIS0_ELb1ELb1EECI2St15__uniq_ptr_implIS0_S2_EEPS0_
	.section	.text._ZNSt10unique_ptrI1ASt14default_deleteIS0_EEC2IS2_vEEPS0_,"axG",@progbits,_ZNSt10unique_ptrI1ASt14default_deleteIS0_EEC5IS2_vEEPS0_,comdat
	.align 2
	.weak	_ZNSt10unique_ptrI1ASt14default_deleteIS0_EEC2IS2_vEEPS0_
	.type	_ZNSt10unique_ptrI1ASt14default_deleteIS0_EEC2IS2_vEEPS0_, @function
_ZNSt10unique_ptrI1ASt14default_deleteIS0_EEC2IS2_vEEPS0_:
.LFB3909:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt15__uniq_ptr_dataI1ASt14default_deleteIS0_ELb1ELb1EECI1St15__uniq_ptr_implIS0_S2_EEPS0_
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3909:
	.size	_ZNSt10unique_ptrI1ASt14default_deleteIS0_EEC2IS2_vEEPS0_, .-_ZNSt10unique_ptrI1ASt14default_deleteIS0_EEC2IS2_vEEPS0_
	.weak	_ZNSt10unique_ptrI1ASt14default_deleteIS0_EEC1IS2_vEEPS0_
	.set	_ZNSt10unique_ptrI1ASt14default_deleteIS0_EEC1IS2_vEEPS0_,_ZNSt10unique_ptrI1ASt14default_deleteIS0_EEC2IS2_vEEPS0_
	.section	.text._ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE6_M_ptrEv,"axG",@progbits,_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE6_M_ptrEv,comdat
	.align 2
	.weak	_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE6_M_ptrEv
	.type	_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE6_M_ptrEv, @function
_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE6_M_ptrEv:
.LFB3911:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt3getILm0EJP1ASt14default_deleteIS0_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3911:
	.size	_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE6_M_ptrEv, .-_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE6_M_ptrEv
	.section	.text._ZNSt10unique_ptrI1ASt14default_deleteIS0_EE11get_deleterEv,"axG",@progbits,_ZNSt10unique_ptrI1ASt14default_deleteIS0_EE11get_deleterEv,comdat
	.align 2
	.weak	_ZNSt10unique_ptrI1ASt14default_deleteIS0_EE11get_deleterEv
	.type	_ZNSt10unique_ptrI1ASt14default_deleteIS0_EE11get_deleterEv, @function
_ZNSt10unique_ptrI1ASt14default_deleteIS0_EE11get_deleterEv:
.LFB3912:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE10_M_deleterEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3912:
	.size	_ZNSt10unique_ptrI1ASt14default_deleteIS0_EE11get_deleterEv, .-_ZNSt10unique_ptrI1ASt14default_deleteIS0_EE11get_deleterEv
	.section	.text._ZSt4moveIRP1AEONSt16remove_referenceIT_E4typeEOS4_,"axG",@progbits,_ZSt4moveIRP1AEONSt16remove_referenceIT_E4typeEOS4_,comdat
	.weak	_ZSt4moveIRP1AEONSt16remove_referenceIT_E4typeEOS4_
	.type	_ZSt4moveIRP1AEONSt16remove_referenceIT_E4typeEOS4_, @function
_ZSt4moveIRP1AEONSt16remove_referenceIT_E4typeEOS4_:
.LFB3913:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3913:
	.size	_ZSt4moveIRP1AEONSt16remove_referenceIT_E4typeEOS4_, .-_ZSt4moveIRP1AEONSt16remove_referenceIT_E4typeEOS4_
	.section	.text._ZNKSt14default_deleteI1AEclEPS0_,"axG",@progbits,_ZNKSt14default_deleteI1AEclEPS0_,comdat
	.align 2
	.weak	_ZNKSt14default_deleteI1AEclEPS0_
	.type	_ZNKSt14default_deleteI1AEclEPS0_, @function
_ZNKSt14default_deleteI1AEclEPS0_:
.LFB3914:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rbx
	testq	%rbx, %rbx
	je	.L28
	movq	%rbx, %rdi
	call	_ZN1AD1Ev
	movl	$128, %esi
	movq	%rbx, %rdi
	call	_ZdlPvm@PLT
.L28:
	nop
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3914:
	.size	_ZNKSt14default_deleteI1AEclEPS0_, .-_ZNKSt14default_deleteI1AEclEPS0_
	.section	.text._ZNKSt10unique_ptrI1ASt14default_deleteIS0_EE3getEv,"axG",@progbits,_ZNKSt10unique_ptrI1ASt14default_deleteIS0_EE3getEv,comdat
	.align 2
	.weak	_ZNKSt10unique_ptrI1ASt14default_deleteIS0_EE3getEv
	.type	_ZNKSt10unique_ptrI1ASt14default_deleteIS0_EE3getEv, @function
_ZNKSt10unique_ptrI1ASt14default_deleteIS0_EE3getEv:
.LFB3917:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE6_M_ptrEv
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3917:
	.size	_ZNKSt10unique_ptrI1ASt14default_deleteIS0_EE3getEv, .-_ZNKSt10unique_ptrI1ASt14default_deleteIS0_EE3getEv
	.section	.text._ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EEC2EPS0_,"axG",@progbits,_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EEC5EPS0_,comdat
	.align 2
	.weak	_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EEC2EPS0_
	.type	_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EEC2EPS0_, @function
_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EEC2EPS0_:
.LFB3993:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt5tupleIJP1ASt14default_deleteIS0_EEEC1ILb1ELb1EEEv
	movq	-32(%rbp), %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE6_M_ptrEv
	movq	%rbx, (%rax)
	nop
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3993:
	.size	_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EEC2EPS0_, .-_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EEC2EPS0_
	.weak	_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EEC1EPS0_
	.set	_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EEC1EPS0_,_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EEC2EPS0_
	.section	.text._ZSt3getILm0EJP1ASt14default_deleteIS0_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_,"axG",@progbits,_ZSt3getILm0EJP1ASt14default_deleteIS0_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_,comdat
	.weak	_ZSt3getILm0EJP1ASt14default_deleteIS0_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_
	.type	_ZSt3getILm0EJP1ASt14default_deleteIS0_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_, @function
_ZSt3getILm0EJP1ASt14default_deleteIS0_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_:
.LFB3995:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__get_helperILm0EP1AJSt14default_deleteIS0_EEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3995:
	.size	_ZSt3getILm0EJP1ASt14default_deleteIS0_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_, .-_ZSt3getILm0EJP1ASt14default_deleteIS0_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_
	.section	.text._ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE10_M_deleterEv,"axG",@progbits,_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE10_M_deleterEv,comdat
	.align 2
	.weak	_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE10_M_deleterEv
	.type	_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE10_M_deleterEv, @function
_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE10_M_deleterEv:
.LFB3996:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt3getILm1EJP1ASt14default_deleteIS0_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3996:
	.size	_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE10_M_deleterEv, .-_ZNSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE10_M_deleterEv
	.section	.text._ZNKSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE6_M_ptrEv,"axG",@progbits,_ZNKSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE6_M_ptrEv,comdat
	.align 2
	.weak	_ZNKSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE6_M_ptrEv
	.type	_ZNKSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE6_M_ptrEv, @function
_ZNKSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE6_M_ptrEv:
.LFB3998:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt3getILm0EJP1ASt14default_deleteIS0_EEERKNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERKS8_
	movq	(%rax), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3998:
	.size	_ZNKSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE6_M_ptrEv, .-_ZNKSt15__uniq_ptr_implI1ASt14default_deleteIS0_EE6_M_ptrEv
	.section	.text._ZNSt5tupleIJP1ASt14default_deleteIS0_EEEC2ILb1ELb1EEEv,"axG",@progbits,_ZNSt5tupleIJP1ASt14default_deleteIS0_EEEC5ILb1ELb1EEEv,comdat
	.align 2
	.weak	_ZNSt5tupleIJP1ASt14default_deleteIS0_EEEC2ILb1ELb1EEEv
	.type	_ZNSt5tupleIJP1ASt14default_deleteIS0_EEEC2ILb1ELb1EEEv, @function
_ZNSt5tupleIJP1ASt14default_deleteIS0_EEEC2ILb1ELb1EEEv:
.LFB4066:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA4066
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEEC2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4066:
	.section	.gcc_except_table
.LLSDA4066:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE4066-.LLSDACSB4066
.LLSDACSB4066:
.LLSDACSE4066:
	.section	.text._ZNSt5tupleIJP1ASt14default_deleteIS0_EEEC2ILb1ELb1EEEv,"axG",@progbits,_ZNSt5tupleIJP1ASt14default_deleteIS0_EEEC5ILb1ELb1EEEv,comdat
	.size	_ZNSt5tupleIJP1ASt14default_deleteIS0_EEEC2ILb1ELb1EEEv, .-_ZNSt5tupleIJP1ASt14default_deleteIS0_EEEC2ILb1ELb1EEEv
	.weak	_ZNSt5tupleIJP1ASt14default_deleteIS0_EEEC1ILb1ELb1EEEv
	.set	_ZNSt5tupleIJP1ASt14default_deleteIS0_EEEC1ILb1ELb1EEEv,_ZNSt5tupleIJP1ASt14default_deleteIS0_EEEC2ILb1ELb1EEEv
	.section	.text._ZSt12__get_helperILm0EP1AJSt14default_deleteIS0_EEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE,"axG",@progbits,_ZSt12__get_helperILm0EP1AJSt14default_deleteIS0_EEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE,comdat
	.weak	_ZSt12__get_helperILm0EP1AJSt14default_deleteIS0_EEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE
	.type	_ZSt12__get_helperILm0EP1AJSt14default_deleteIS0_EEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE, @function
_ZSt12__get_helperILm0EP1AJSt14default_deleteIS0_EEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE:
.LFB4068:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEE7_M_headERS4_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4068:
	.size	_ZSt12__get_helperILm0EP1AJSt14default_deleteIS0_EEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE, .-_ZSt12__get_helperILm0EP1AJSt14default_deleteIS0_EEERT0_RSt11_Tuple_implIXT_EJS4_DpT1_EE
	.section	.text._ZSt3getILm1EJP1ASt14default_deleteIS0_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_,"axG",@progbits,_ZSt3getILm1EJP1ASt14default_deleteIS0_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_,comdat
	.weak	_ZSt3getILm1EJP1ASt14default_deleteIS0_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_
	.type	_ZSt3getILm1EJP1ASt14default_deleteIS0_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_, @function
_ZSt3getILm1EJP1ASt14default_deleteIS0_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_:
.LFB4069:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__get_helperILm1ESt14default_deleteI1AEJEERT0_RSt11_Tuple_implIXT_EJS3_DpT1_EE
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4069:
	.size	_ZSt3getILm1EJP1ASt14default_deleteIS0_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_, .-_ZSt3getILm1EJP1ASt14default_deleteIS0_EEERNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERS8_
	.section	.text._ZSt3getILm0EJP1ASt14default_deleteIS0_EEERKNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERKS8_,"axG",@progbits,_ZSt3getILm0EJP1ASt14default_deleteIS0_EEERKNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERKS8_,comdat
	.weak	_ZSt3getILm0EJP1ASt14default_deleteIS0_EEERKNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERKS8_
	.type	_ZSt3getILm0EJP1ASt14default_deleteIS0_EEERKNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERKS8_, @function
_ZSt3getILm0EJP1ASt14default_deleteIS0_EEERKNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERKS8_:
.LFB4070:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt12__get_helperILm0EP1AJSt14default_deleteIS0_EEERKT0_RKSt11_Tuple_implIXT_EJS4_DpT1_EE
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4070:
	.size	_ZSt3getILm0EJP1ASt14default_deleteIS0_EEERKNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERKS8_, .-_ZSt3getILm0EJP1ASt14default_deleteIS0_EEERKNSt13tuple_elementIXT_ESt5tupleIJDpT0_EEE4typeERKS8_
	.section	.text._ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEEC2Ev,"axG",@progbits,_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEEC5Ev,comdat
	.align 2
	.weak	_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEEC2Ev
	.type	_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEEC2Ev, @function
_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEEC2Ev:
.LFB4142:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt11_Tuple_implILm1EJSt14default_deleteI1AEEEC2Ev
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt10_Head_baseILm0EP1ALb0EEC2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4142:
	.size	_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEEC2Ev, .-_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEEC2Ev
	.weak	_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEEC1Ev
	.set	_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEEC1Ev,_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEEC2Ev
	.section	.text._ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEE7_M_headERS4_,"axG",@progbits,_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEE7_M_headERS4_,comdat
	.weak	_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEE7_M_headERS4_
	.type	_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEE7_M_headERS4_, @function
_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEE7_M_headERS4_:
.LFB4144:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt10_Head_baseILm0EP1ALb0EE7_M_headERS2_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4144:
	.size	_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEE7_M_headERS4_, .-_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEE7_M_headERS4_
	.section	.text._ZSt12__get_helperILm1ESt14default_deleteI1AEJEERT0_RSt11_Tuple_implIXT_EJS3_DpT1_EE,"axG",@progbits,_ZSt12__get_helperILm1ESt14default_deleteI1AEJEERT0_RSt11_Tuple_implIXT_EJS3_DpT1_EE,comdat
	.weak	_ZSt12__get_helperILm1ESt14default_deleteI1AEJEERT0_RSt11_Tuple_implIXT_EJS3_DpT1_EE
	.type	_ZSt12__get_helperILm1ESt14default_deleteI1AEJEERT0_RSt11_Tuple_implIXT_EJS3_DpT1_EE, @function
_ZSt12__get_helperILm1ESt14default_deleteI1AEJEERT0_RSt11_Tuple_implIXT_EJS3_DpT1_EE:
.LFB4145:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt11_Tuple_implILm1EJSt14default_deleteI1AEEE7_M_headERS3_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4145:
	.size	_ZSt12__get_helperILm1ESt14default_deleteI1AEJEERT0_RSt11_Tuple_implIXT_EJS3_DpT1_EE, .-_ZSt12__get_helperILm1ESt14default_deleteI1AEJEERT0_RSt11_Tuple_implIXT_EJS3_DpT1_EE
	.section	.text._ZSt12__get_helperILm0EP1AJSt14default_deleteIS0_EEERKT0_RKSt11_Tuple_implIXT_EJS4_DpT1_EE,"axG",@progbits,_ZSt12__get_helperILm0EP1AJSt14default_deleteIS0_EEERKT0_RKSt11_Tuple_implIXT_EJS4_DpT1_EE,comdat
	.weak	_ZSt12__get_helperILm0EP1AJSt14default_deleteIS0_EEERKT0_RKSt11_Tuple_implIXT_EJS4_DpT1_EE
	.type	_ZSt12__get_helperILm0EP1AJSt14default_deleteIS0_EEERKT0_RKSt11_Tuple_implIXT_EJS4_DpT1_EE, @function
_ZSt12__get_helperILm0EP1AJSt14default_deleteIS0_EEERKT0_RKSt11_Tuple_implIXT_EJS4_DpT1_EE:
.LFB4146:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEE7_M_headERKS4_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4146:
	.size	_ZSt12__get_helperILm0EP1AJSt14default_deleteIS0_EEERKT0_RKSt11_Tuple_implIXT_EJS4_DpT1_EE, .-_ZSt12__get_helperILm0EP1AJSt14default_deleteIS0_EEERKT0_RKSt11_Tuple_implIXT_EJS4_DpT1_EE
	.section	.text._ZNSt11_Tuple_implILm1EJSt14default_deleteI1AEEEC2Ev,"axG",@progbits,_ZNSt11_Tuple_implILm1EJSt14default_deleteI1AEEEC5Ev,comdat
	.align 2
	.weak	_ZNSt11_Tuple_implILm1EJSt14default_deleteI1AEEEC2Ev
	.type	_ZNSt11_Tuple_implILm1EJSt14default_deleteI1AEEEC2Ev, @function
_ZNSt11_Tuple_implILm1EJSt14default_deleteI1AEEEC2Ev:
.LFB4183:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt10_Head_baseILm1ESt14default_deleteI1AELb1EEC2Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4183:
	.size	_ZNSt11_Tuple_implILm1EJSt14default_deleteI1AEEEC2Ev, .-_ZNSt11_Tuple_implILm1EJSt14default_deleteI1AEEEC2Ev
	.weak	_ZNSt11_Tuple_implILm1EJSt14default_deleteI1AEEEC1Ev
	.set	_ZNSt11_Tuple_implILm1EJSt14default_deleteI1AEEEC1Ev,_ZNSt11_Tuple_implILm1EJSt14default_deleteI1AEEEC2Ev
	.section	.text._ZNSt10_Head_baseILm0EP1ALb0EEC2Ev,"axG",@progbits,_ZNSt10_Head_baseILm0EP1ALb0EEC5Ev,comdat
	.align 2
	.weak	_ZNSt10_Head_baseILm0EP1ALb0EEC2Ev
	.type	_ZNSt10_Head_baseILm0EP1ALb0EEC2Ev, @function
_ZNSt10_Head_baseILm0EP1ALb0EEC2Ev:
.LFB4186:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4186:
	.size	_ZNSt10_Head_baseILm0EP1ALb0EEC2Ev, .-_ZNSt10_Head_baseILm0EP1ALb0EEC2Ev
	.weak	_ZNSt10_Head_baseILm0EP1ALb0EEC1Ev
	.set	_ZNSt10_Head_baseILm0EP1ALb0EEC1Ev,_ZNSt10_Head_baseILm0EP1ALb0EEC2Ev
	.section	.text._ZNSt10_Head_baseILm0EP1ALb0EE7_M_headERS2_,"axG",@progbits,_ZNSt10_Head_baseILm0EP1ALb0EE7_M_headERS2_,comdat
	.weak	_ZNSt10_Head_baseILm0EP1ALb0EE7_M_headERS2_
	.type	_ZNSt10_Head_baseILm0EP1ALb0EE7_M_headERS2_, @function
_ZNSt10_Head_baseILm0EP1ALb0EE7_M_headERS2_:
.LFB4188:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4188:
	.size	_ZNSt10_Head_baseILm0EP1ALb0EE7_M_headERS2_, .-_ZNSt10_Head_baseILm0EP1ALb0EE7_M_headERS2_
	.section	.text._ZNSt11_Tuple_implILm1EJSt14default_deleteI1AEEE7_M_headERS3_,"axG",@progbits,_ZNSt11_Tuple_implILm1EJSt14default_deleteI1AEEE7_M_headERS3_,comdat
	.weak	_ZNSt11_Tuple_implILm1EJSt14default_deleteI1AEEE7_M_headERS3_
	.type	_ZNSt11_Tuple_implILm1EJSt14default_deleteI1AEEE7_M_headERS3_, @function
_ZNSt11_Tuple_implILm1EJSt14default_deleteI1AEEE7_M_headERS3_:
.LFB4189:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt10_Head_baseILm1ESt14default_deleteI1AELb1EE7_M_headERS3_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4189:
	.size	_ZNSt11_Tuple_implILm1EJSt14default_deleteI1AEEE7_M_headERS3_, .-_ZNSt11_Tuple_implILm1EJSt14default_deleteI1AEEE7_M_headERS3_
	.section	.text._ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEE7_M_headERKS4_,"axG",@progbits,_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEE7_M_headERKS4_,comdat
	.weak	_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEE7_M_headERKS4_
	.type	_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEE7_M_headERKS4_, @function
_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEE7_M_headERKS4_:
.LFB4190:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt10_Head_baseILm0EP1ALb0EE7_M_headERKS2_
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4190:
	.size	_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEE7_M_headERKS4_, .-_ZNSt11_Tuple_implILm0EJP1ASt14default_deleteIS0_EEE7_M_headERKS4_
	.section	.text._ZNSt10_Head_baseILm1ESt14default_deleteI1AELb1EEC2Ev,"axG",@progbits,_ZNSt10_Head_baseILm1ESt14default_deleteI1AELb1EEC5Ev,comdat
	.align 2
	.weak	_ZNSt10_Head_baseILm1ESt14default_deleteI1AELb1EEC2Ev
	.type	_ZNSt10_Head_baseILm1ESt14default_deleteI1AELb1EEC2Ev, @function
_ZNSt10_Head_baseILm1ESt14default_deleteI1AELb1EEC2Ev:
.LFB4208:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4208:
	.size	_ZNSt10_Head_baseILm1ESt14default_deleteI1AELb1EEC2Ev, .-_ZNSt10_Head_baseILm1ESt14default_deleteI1AELb1EEC2Ev
	.weak	_ZNSt10_Head_baseILm1ESt14default_deleteI1AELb1EEC1Ev
	.set	_ZNSt10_Head_baseILm1ESt14default_deleteI1AELb1EEC1Ev,_ZNSt10_Head_baseILm1ESt14default_deleteI1AELb1EEC2Ev
	.section	.text._ZNSt10_Head_baseILm1ESt14default_deleteI1AELb1EE7_M_headERS3_,"axG",@progbits,_ZNSt10_Head_baseILm1ESt14default_deleteI1AELb1EE7_M_headERS3_,comdat
	.weak	_ZNSt10_Head_baseILm1ESt14default_deleteI1AELb1EE7_M_headERS3_
	.type	_ZNSt10_Head_baseILm1ESt14default_deleteI1AELb1EE7_M_headERS3_, @function
_ZNSt10_Head_baseILm1ESt14default_deleteI1AELb1EE7_M_headERS3_:
.LFB4210:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4210:
	.size	_ZNSt10_Head_baseILm1ESt14default_deleteI1AELb1EE7_M_headERS3_, .-_ZNSt10_Head_baseILm1ESt14default_deleteI1AELb1EE7_M_headERS3_
	.section	.text._ZNSt10_Head_baseILm0EP1ALb0EE7_M_headERKS2_,"axG",@progbits,_ZNSt10_Head_baseILm0EP1ALb0EE7_M_headERKS2_,comdat
	.weak	_ZNSt10_Head_baseILm0EP1ALb0EE7_M_headERKS2_
	.type	_ZNSt10_Head_baseILm0EP1ALb0EE7_M_headERKS2_, @function
_ZNSt10_Head_baseILm0EP1ALb0EE7_M_headERKS2_:
.LFB4211:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4211:
	.size	_ZNSt10_Head_baseILm0EP1ALb0EE7_M_headERKS2_, .-_ZNSt10_Head_baseILm0EP1ALb0EE7_M_headERKS2_
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB4236:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L67
	cmpl	$65535, -8(%rbp)
	jne	.L67
	leaq	_ZStL8__ioinit(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rax
	movq	%rax, %rdx
	leaq	_ZStL8__ioinit(%rip), %rax
	movq	%rax, %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L67:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4236:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_globalvariable, @function
_GLOBAL__sub_I_globalvariable:
.LFB4237:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4237:
	.size	_GLOBAL__sub_I_globalvariable, .-_GLOBAL__sub_I_globalvariable
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_globalvariable
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
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

	.file	"satori.cxx"
	.intel_syntax noprefix
	.globl	__umodti3
	.text
	.p2align 4,,15
	.type	_ZN12_GLOBAL__N_1L9fpow_implEmmm, @function
_ZN12_GLOBAL__N_1L9fpow_implEmmm:
.LFB3729:
	.cfi_startproc
	test	rsi, rsi
	mov	eax, 1
	je	.L8
	mov	QWORD PTR [rsp-16], rbx
	.cfi_offset 3, -24
	mov	rbx, rdx
	mov	QWORD PTR [rsp-8], rbp
	sub	rsp, 24
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -16
	test	sil, 1
	mov	rbp, rdi
	jne	.L11
	shr	rsi
	call	_ZN12_GLOBAL__N_1L9fpow_implEmmm
	mov	rdi, rax
	mul	rdi
.L9:
	mov	rsi, rdx
	mov	rdi, rax
	mov	rdx, rbx
	xor	ecx, ecx
	call	__umodti3
	mov	rbx, QWORD PTR [rsp+8]
	mov	rbp, QWORD PTR [rsp+16]
	add	rsp, 24
	.cfi_restore 6
	.cfi_restore 3
	.cfi_def_cfa_offset 8
.L8:
	rep
	ret
	.p2align 4,,10
	.p2align 3
.L11:
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -24
	.cfi_offset 6, -16
	sub	rsi, 1
	call	_ZN12_GLOBAL__N_1L9fpow_implEmmm
	mul	rbp
	jmp	.L9
	.cfi_endproc
.LFE3729:
	.size	_ZN12_GLOBAL__N_1L9fpow_implEmmm, .-_ZN12_GLOBAL__N_1L9fpow_implEmmm
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB3733:
	.cfi_startproc
	push	r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	xor	edi, edi
	push	r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	push	r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	push	r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	push	rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	push	rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	sub	rsp, 40
	.cfi_def_cfa_offset 96
	call	_ZNSt8ios_base15sync_with_stdioEb
	lea	rsi, [rsp+24]
	mov	edi, OFFSET FLAT:_ZSt3cin
	call	_ZNSirsERm
.L13:
	mov	rax, QWORD PTR [rsp+24]
	lea	rdx, [rax-1]
	test	rax, rax
	mov	QWORD PTR [rsp+24], rdx
	je	.L47
	xor	ebx, ebx
	xor	r13d, r13d
	xor	r14d, r14d
	cmp	rbx, 1
	jbe	.L30
	.p2align 4,,10
	.p2align 3
.L49:
	cmp	rbx, 2
	je	.L26
	lea	rax, [rbx-1]
	xor	r15d, r15d
	mov	rbp, rax
	mov	QWORD PTR [rsp], rax
	and	ebp, 1
.L20:
	xor	r12d, r12d
	test	rbp, rbp
	mov	rax, QWORD PTR _ZZN12_GLOBAL__N_1L7isPrimeEmE13randomNumbers[0+r15*8]
	mov	rsi, QWORD PTR [rsp]
	jne	.L15
	.p2align 4,,10
	.p2align 3
.L16:
	shr	rsi
	add	r12, 1
	test	sil, 1
	je	.L16
.L15:
	xor	edx, edx
	div	rbx
	mov	rdi, rdx
	mov	rdx, rbx
	call	_ZN12_GLOBAL__N_1L9fpow_implEmmm
	cmp	rax, 1
	mov	rdi, rax
	je	.L17
	cmp	rax, QWORD PTR [rsp]
	je	.L17
	cmp	r12, 1
	jbe	.L18
	mul	rdi
	mov	rcx, r14
	mov	rdi, rax
	mov	rsi, rdx
	mov	rdx, r13
	call	__umodti3
	cmp	rax, 1
	mov	rdi, rax
	je	.L30
	mov	r15d, 1
	.p2align 4,,10
	.p2align 3
.L19:
	add	r15, 1
	cmp	r15, r12
	jne	.L48
.L18:
	cmp	rdi, QWORD PTR [rsp]
	sete	BYTE PTR [rsp+15]
	cmp	BYTE PTR [rsp+15], 0
	jne	.L43
.L23:
	movabs	rdx, 100000000000
	add	rbx, 1
	add	r13, 1
	adc	r14, 0
	cmp	rbx, rdx
	je	.L13
	cmp	rbx, 1
	ja	.L49
.L30:
	mov	BYTE PTR [rsp+15], 0
	jmp	.L23
	.p2align 4,,10
	.p2align 3
.L48:
	cmp	rdi, QWORD PTR [rsp]
	je	.L18
	mov	rax, rdi
	mov	rcx, r14
	mul	rdi
	mov	rdi, rax
	mov	rsi, rdx
	mov	rdx, r13
	call	__umodti3
	cmp	rax, 1
	mov	rdi, rax
	jne	.L19
	mov	BYTE PTR [rsp+15], 0
	jmp	.L23
	.p2align 4,,10
	.p2align 3
.L17:
	add	r15, 1
	cmp	r15, 56
	jne	.L20
	cmp	BYTE PTR [rsp+15], 0
	je	.L23
	.p2align 4,,10
	.p2align 3
.L43:
	mov	rsi, rbx
	mov	edi, OFFSET FLAT:_ZSt4cout
	call	_ZNSo9_M_insertImEERSoT_
	mov	edx, 1
	mov	BYTE PTR [rsp+23], 10
	lea	rsi, [rsp+23]
	mov	rdi, rax
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	jmp	.L23
	.p2align 4,,10
	.p2align 3
.L26:
	mov	BYTE PTR [rsp+15], 1
	jmp	.L43
.L47:
	add	rsp, 40
	.cfi_def_cfa_offset 56
	xor	eax, eax
	pop	rbx
	.cfi_def_cfa_offset 48
	pop	rbp
	.cfi_def_cfa_offset 40
	pop	r12
	.cfi_def_cfa_offset 32
	pop	r13
	.cfi_def_cfa_offset 24
	pop	r14
	.cfi_def_cfa_offset 16
	pop	r15
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3733:
	.size	main, .-main
	.p2align 4,,15
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB3933:
	.cfi_startproc
	sub	rsp, 8
	.cfi_def_cfa_offset 16
	mov	edi, OFFSET FLAT:_ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	mov	edx, OFFSET FLAT:__dso_handle
	mov	esi, OFFSET FLAT:_ZStL8__ioinit
	mov	edi, OFFSET FLAT:_ZNSt8ios_base4InitD1Ev
	add	rsp, 8
	.cfi_def_cfa_offset 8
	jmp	__cxa_atexit
	.cfi_endproc
.LFE3933:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.section	.rodata
	.align 32
	.type	_ZZN12_GLOBAL__N_1L7isPrimeEmE13randomNumbers, @object
	.size	_ZZN12_GLOBAL__N_1L7isPrimeEmE13randomNumbers, 56
_ZZN12_GLOBAL__N_1L7isPrimeEmE13randomNumbers:
	.quad	2
	.quad	325
	.quad	9375
	.quad	28178
	.quad	450775
	.quad	9780504
	.quad	1795265022
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu/Linaro 4.7.3-1ubuntu1) 4.7.3"
	.section	.note.GNU-stack,"",@progbits

	.file	"satori.cxx"
	.intel_syntax noprefix
	.text
	.p2align 4,,15
	.type	(anonymous namespace)::atan2Compare((anonymous namespace)::Event const&, (anonymous namespace)::Event const&), @function
(anonymous namespace)::atan2Compare((anonymous namespace)::Event const&, (anonymous namespace)::Event const&):
.LFB3743:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	push	rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	mov	rbx, rsi
	sub	rsp, 24
	.cfi_def_cfa_offset 48
	movsd	xmm1, QWORD PTR [rdi]
	movsd	xmm0, QWORD PTR [rdi+8]
	ucomisd	xmm1, QWORD PTR [rsi]
	jp	.L6
	je	.L12
.L6:
	mov	rdx, QWORD PTR [rdi+24]
	mov	rbp, QWORD PTR (anonymous namespace)::points[rip]
	sal	rdx, 4
	add	rdx, rbp
	subsd	xmm1, QWORD PTR [rdx]
	subsd	xmm0, QWORD PTR [rdx+8]
	call	atan2
	mov	rax, QWORD PTR [rbx+24]
	movsd	QWORD PTR [rsp+8], xmm0
	movsd	xmm1, QWORD PTR [rbx]
	movsd	xmm0, QWORD PTR [rbx+8]
	sal	rax, 4
	add	rax, rbp
	subsd	xmm0, QWORD PTR [rax+8]
	subsd	xmm1, QWORD PTR [rax]
	call	atan2
	ucomisd	xmm0, QWORD PTR [rsp+8]
	seta	al
	add	rsp, 24
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	pop	rbx
	.cfi_def_cfa_offset 16
	pop	rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L12:
	.cfi_restore_state
	ucomisd	xmm0, QWORD PTR [rsi+8]
	jp	.L6
	jne	.L6
	movzx	eax, BYTE PTR [rdi+32]
	cmp	BYTE PTR [rsi+32], al
	seta	al
	add	rsp, 24
	.cfi_def_cfa_offset 24
	pop	rbx
	.cfi_def_cfa_offset 16
	pop	rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3743:
	.size	(anonymous namespace)::atan2Compare((anonymous namespace)::Event const&, (anonymous namespace)::Event const&), .-(anonymous namespace)::atan2Compare((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)
	.p2align 4,,15
	.type	(anonymous namespace)::atan2ComparePoints((anonymous namespace)::Point const&, (anonymous namespace)::Point const&), @function
(anonymous namespace)::atan2ComparePoints((anonymous namespace)::Point const&, (anonymous namespace)::Point const&):
.LFB3744:
	.cfi_startproc
	push	rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	mov	rbx, rsi
	sub	rsp, 16
	.cfi_def_cfa_offset 32
	movsd	xmm1, QWORD PTR [rdi]
	movsd	xmm0, QWORD PTR [rdi+8]
	call	atan2
	movsd	xmm1, QWORD PTR [rbx]
	movsd	QWORD PTR [rsp+8], xmm0
	movsd	xmm0, QWORD PTR [rbx+8]
	call	atan2
	ucomisd	xmm0, QWORD PTR [rsp+8]
	seta	al
	add	rsp, 16
	.cfi_def_cfa_offset 16
	pop	rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3744:
	.size	(anonymous namespace)::atan2ComparePoints((anonymous namespace)::Point const&, (anonymous namespace)::Point const&), .-(anonymous namespace)::atan2ComparePoints((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)
	.p2align 4,,15
	.type	void std::__adjust_heap<(anonymous namespace)::Point*, long, (anonymous namespace)::Point, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, long, long, (anonymous namespace)::Point, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.37], @function
void std::__adjust_heap<(anonymous namespace)::Point*, long, (anonymous namespace)::Point, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, long, long, (anonymous namespace)::Point, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.37]:
.LFB4146:
	.cfi_startproc
	push	r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	mov	rax, rdx
	mov	r15, rsi
	sub	rax, 1
	push	r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	push	r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	mov	r13, rax
	shr	r13, 63
	push	r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	add	r13, rax
	mov	r12, rdi
	push	rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	push	rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	sub	rsp, 72
	.cfi_def_cfa_offset 128
	mov	QWORD PTR [rsp+8], r13
	sar	QWORD PTR [rsp+8]
	movsd	QWORD PTR [rsp+32], xmm0
	mov	rax, QWORD PTR [rsp+8]
	mov	QWORD PTR [rsp+16], rsi
	movsd	QWORD PTR [rsp+40], xmm1
	mov	QWORD PTR [rsp+24], rdx
	cmp	rsi, rax
	jl	.L28
	jmp	.L34
	.p2align 4,,10
	.p2align 3
.L24:
	mov	r15, rbp
.L28:
	lea	rbx, [r15+1]
	lea	rbp, [rbx+rbx]
	sal	rbx, 5
	add	rbx, r12
	lea	r13, [rbp-1]
	mov	rdi, rbx
	mov	rcx, r13
	sal	rcx, 4
	lea	r14, [r12+rcx]
	mov	rsi, r14
	call	(anonymous namespace)::atan2ComparePoints((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)
	test	al, al
	mov	rdx, r15
	cmovne	rbx, r14
	cmovne	rbp, r13
	sal	rdx, 4
	mov	rax, QWORD PTR [rbx]
	add	rdx, r12
	cmp	rbp, QWORD PTR [rsp+8]
	mov	QWORD PTR [rdx], rax
	mov	rax, QWORD PTR [rbx+8]
	mov	QWORD PTR [rdx+8], rax
	jl	.L24
.L17:
	test	BYTE PTR [rsp+24], 1
	jne	.L20
	mov	r15, QWORD PTR [rsp+24]
	sub	r15, 2
	mov	rax, r15
	shr	rax, 63
	add	r15, rax
	sar	r15
	cmp	rbp, r15
	je	.L32
.L20:
	mov	rax, QWORD PTR [rsp+32]
	cmp	rbp, QWORD PTR [rsp+16]
	mov	QWORD PTR [rsp+48], rax
	mov	rax, QWORD PTR [rsp+40]
	mov	QWORD PTR [rsp+56], rax
	jg	.L33
.L21:
	mov	rax, QWORD PTR [rsp+48]
	mov	QWORD PTR [rbx], rax
	mov	rax, QWORD PTR [rsp+56]
	mov	QWORD PTR [rbx+8], rax
	add	rsp, 72
	.cfi_remember_state
	.cfi_def_cfa_offset 56
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
	.p2align 4,,10
	.p2align 3
.L32:
	.cfi_restore_state
	lea	rbp, [rbp+1+rbp]
	mov	rax, rbp
	sal	rax, 4
	add	rax, r12
	mov	rdx, QWORD PTR [rax]
	mov	QWORD PTR [rbx], rdx
	mov	rdx, QWORD PTR [rax+8]
	mov	QWORD PTR [rbx+8], rdx
	mov	rbx, rax
	jmp	.L20
	.p2align 4,,10
	.p2align 3
.L33:
	lea	rax, [rbp-1]
	mov	r13, rax
	shr	r13, 63
	add	r13, rax
	sar	r13
.L23:
	mov	rbx, r13
	lea	rsi, [rsp+48]
	sal	rbx, 4
	add	rbx, r12
	mov	rdi, rbx
	call	(anonymous namespace)::atan2ComparePoints((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)
	test	al, al
	jne	.L22
	mov	rbx, rbp
	sal	rbx, 4
	add	rbx, r12
	jmp	.L21
	.p2align 4,,10
	.p2align 3
.L22:
	mov	rax, QWORD PTR [rbx]
	sal	rbp, 4
	add	rbp, r12
	mov	QWORD PTR [rbp+0], rax
	mov	rax, QWORD PTR [rbx+8]
	mov	QWORD PTR [rbp+8], rax
	lea	rax, [r13-1]
	mov	rdx, rax
	shr	rdx, 63
	add	rax, rdx
	sar	rax
	cmp	QWORD PTR [rsp+16], r13
	jge	.L21
	mov	rbp, r13
	mov	r13, rax
	jmp	.L23
.L34:
	mov	rbx, rsi
	mov	rbp, rsi
	sal	rbx, 4
	add	rbx, rdi
	jmp	.L17
	.cfi_endproc
.LFE4146:
	.size	void std::__adjust_heap<(anonymous namespace)::Point*, long, (anonymous namespace)::Point, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, long, long, (anonymous namespace)::Point, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.37], .-void std::__adjust_heap<(anonymous namespace)::Point*, long, (anonymous namespace)::Point, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, long, long, (anonymous namespace)::Point, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.37]
	.p2align 4,,15
	.type	void std::__unguarded_linear_insert<(anonymous namespace)::Point*, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.45], @function
void std::__unguarded_linear_insert<(anonymous namespace)::Point*, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.45]:
.LFB4138:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rdi
	push	rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	lea	rbx, [rdi-16]
	sub	rsp, 24
	.cfi_def_cfa_offset 48
	mov	rax, QWORD PTR [rdi]
	mov	QWORD PTR [rsp], rax
	mov	rax, QWORD PTR [rdi+8]
	mov	QWORD PTR [rsp+8], rax
	jmp	.L36
	.p2align 4,,10
	.p2align 3
.L37:
	mov	rax, QWORD PTR [rbx]
	mov	QWORD PTR [rbp+0], rax
	mov	rax, QWORD PTR [rbx+8]
	mov	QWORD PTR [rbp+8], rax
	mov	rbp, rbx
	sub	rbx, 16
.L36:
	mov	rsi, rbx
	mov	rdi, rsp
	call	(anonymous namespace)::atan2ComparePoints((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)
	test	al, al
	jne	.L37
	mov	rax, QWORD PTR [rsp]
	mov	QWORD PTR [rbp+0], rax
	mov	rax, QWORD PTR [rsp+8]
	mov	QWORD PTR [rbp+8], rax
	add	rsp, 24
	.cfi_def_cfa_offset 24
	pop	rbx
	.cfi_def_cfa_offset 16
	pop	rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE4138:
	.size	void std::__unguarded_linear_insert<(anonymous namespace)::Point*, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.45], .-void std::__unguarded_linear_insert<(anonymous namespace)::Point*, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.45]
	.p2align 4,,15
	.type	void std::__insertion_sort<(anonymous namespace)::Point*, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, (anonymous namespace)::Point*, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.44], @function
void std::__insertion_sort<(anonymous namespace)::Point*, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, (anonymous namespace)::Point*, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.44]:
.LFB4139:
	.cfi_startproc
	push	r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	mov	r13, rdi
	push	r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	mov	r12, rsi
	push	rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	push	rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	sub	rsp, 8
	.cfi_def_cfa_offset 48
	cmp	rdi, rsi
	je	.L39
	lea	rbp, [rdi+16]
.L52:
	cmp	r12, rbp
	je	.L39
.L53:
	mov	rsi, r13
	mov	rdi, rbp
	mov	rbx, rbp
	call	(anonymous namespace)::atan2ComparePoints((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)
	test	al, al
	je	.L42
	mov	rax, rbx
	movsd	xmm0, QWORD PTR [rbp+0]
	sub	rax, r13
	movsd	xmm1, QWORD PTR [rbp+8]
	sar	rax, 4
	lea	rbp, [rbp+16]
	test	rax, rax
	jle	.L46
	.p2align 4,,10
	.p2align 3
.L48:
	sub	rbx, 16
	sub	rax, 1
	mov	rdx, QWORD PTR [rbx]
	mov	QWORD PTR [rbx+16], rdx
	mov	rdx, QWORD PTR [rbx+8]
	mov	QWORD PTR [rbx+24], rdx
	jne	.L48
.L46:
	cmp	r12, rbp
	movsd	QWORD PTR [r13+0], xmm0
	movsd	QWORD PTR [r13+8], xmm1
	jne	.L53
.L39:
	add	rsp, 8
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	pop	rbx
	.cfi_def_cfa_offset 32
	pop	rbp
	.cfi_def_cfa_offset 24
	pop	r12
	.cfi_def_cfa_offset 16
	pop	r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L42:
	.cfi_restore_state
	mov	rdi, rbp
	add	rbp, 16
	call	void std::__unguarded_linear_insert<(anonymous namespace)::Point*, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.45]
	jmp	.L52
	.cfi_endproc
.LFE4139:
	.size	void std::__insertion_sort<(anonymous namespace)::Point*, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, (anonymous namespace)::Point*, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.44], .-void std::__insertion_sort<(anonymous namespace)::Point*, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, (anonymous namespace)::Point*, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.44]
	.p2align 4,,15
	.type	void std::__adjust_heap<(anonymous namespace)::Event*, long, (anonymous namespace)::Event, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, long, long, (anonymous namespace)::Event, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.53], @function
void std::__adjust_heap<(anonymous namespace)::Event*, long, (anonymous namespace)::Event, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, long, long, (anonymous namespace)::Event, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.53]:
.LFB4130:
	.cfi_startproc
	push	r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	mov	rax, rdx
	mov	r15, rsi
	sub	rax, 1
	push	r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	push	r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	mov	r13, rdi
	push	r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	mov	r12, rax
	shr	r12, 63
	push	rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	add	r12, rax
	push	rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	sub	rsp, 88
	.cfi_def_cfa_offset 144
	mov	QWORD PTR [rsp+8], r12
	sar	QWORD PTR [rsp+8]
	mov	QWORD PTR [rsp+24], rdx
	mov	rdx, QWORD PTR [rsp+8]
	mov	QWORD PTR [rsp+16], rsi
	cmp	rsi, rdx
	jl	.L67
	jmp	.L73
	.p2align 4,,10
	.p2align 3
.L63:
	mov	r15, rbp
.L67:
	lea	rax, [r15+1]
	lea	rbp, [rax+rax]
	lea	rax, [rbp+0+rax*8]
	lea	r12, [rbp-1]
	lea	rbx, [r13+0+rax*8]
	lea	rax, [r12+r12*4]
	lea	r14, [r13+0+rax*8]
	mov	rdi, rbx
	mov	rsi, r14
	call	(anonymous namespace)::atan2Compare((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)
	test	al, al
	lea	rax, [r15+r15*4]
	cmovne	rbx, r14
	cmovne	rbp, r12
	cmp	rbp, QWORD PTR [rsp+8]
	mov	rdx, QWORD PTR [rbx]
	lea	rax, [r13+0+rax*8]
	mov	QWORD PTR [rax], rdx
	mov	rdx, QWORD PTR [rbx+8]
	mov	QWORD PTR [rax+8], rdx
	mov	rdx, QWORD PTR [rbx+16]
	mov	QWORD PTR [rax+16], rdx
	mov	rdx, QWORD PTR [rbx+24]
	mov	QWORD PTR [rax+24], rdx
	movzx	edx, BYTE PTR [rbx+32]
	mov	BYTE PTR [rax+32], dl
	jl	.L63
.L56:
	test	BYTE PTR [rsp+24], 1
	jne	.L59
	mov	r14, QWORD PTR [rsp+24]
	sub	r14, 2
	mov	rax, r14
	shr	rax, 63
	add	r14, rax
	sar	r14
	cmp	rbp, r14
	je	.L71
.L59:
	mov	rax, QWORD PTR [rsp+144]
	cmp	rbp, QWORD PTR [rsp+16]
	mov	QWORD PTR [rsp+32], rax
	mov	rax, QWORD PTR [rsp+152]
	mov	QWORD PTR [rsp+40], rax
	mov	rax, QWORD PTR [rsp+160]
	mov	QWORD PTR [rsp+48], rax
	mov	rax, QWORD PTR [rsp+168]
	mov	QWORD PTR [rsp+56], rax
	mov	rax, QWORD PTR [rsp+176]
	mov	QWORD PTR [rsp+64], rax
	jg	.L72
.L60:
	mov	rax, QWORD PTR [rsp+32]
	mov	QWORD PTR [rbx], rax
	mov	rax, QWORD PTR [rsp+40]
	mov	QWORD PTR [rbx+8], rax
	mov	rax, QWORD PTR [rsp+48]
	mov	QWORD PTR [rbx+16], rax
	mov	rax, QWORD PTR [rsp+56]
	mov	QWORD PTR [rbx+24], rax
	movzx	eax, BYTE PTR [rsp+64]
	mov	BYTE PTR [rbx+32], al
	add	rsp, 88
	.cfi_remember_state
	.cfi_def_cfa_offset 56
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
	.p2align 4,,10
	.p2align 3
.L71:
	.cfi_restore_state
	lea	rbp, [rbp+1+rbp]
	lea	rax, [rbp+0+rbp*4]
	lea	rax, [r13+0+rax*8]
	mov	rdx, QWORD PTR [rax]
	mov	QWORD PTR [rbx], rdx
	mov	rdx, QWORD PTR [rax+8]
	mov	QWORD PTR [rbx+8], rdx
	mov	rdx, QWORD PTR [rax+16]
	mov	QWORD PTR [rbx+16], rdx
	mov	rdx, QWORD PTR [rax+24]
	mov	QWORD PTR [rbx+24], rdx
	movzx	edx, BYTE PTR [rax+32]
	mov	BYTE PTR [rbx+32], dl
	mov	rbx, rax
	jmp	.L59
	.p2align 4,,10
	.p2align 3
.L72:
	lea	rax, [rbp-1]
	mov	r12, rax
	shr	r12, 63
	add	r12, rax
	sar	r12
.L62:
	lea	rax, [r12+r12*4]
	lea	rsi, [rsp+32]
	lea	rbx, [r13+0+rax*8]
	mov	rdi, rbx
	call	(anonymous namespace)::atan2Compare((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)
	test	al, al
	lea	rax, [rbp+0+rbp*4]
	jne	.L61
	lea	rbx, [r13+0+rax*8]
	jmp	.L60
	.p2align 4,,10
	.p2align 3
.L61:
	mov	rdx, QWORD PTR [rbx]
	lea	rax, [r13+0+rax*8]
	mov	QWORD PTR [rax], rdx
	mov	rdx, QWORD PTR [rbx+8]
	mov	QWORD PTR [rax+8], rdx
	mov	rdx, QWORD PTR [rbx+16]
	mov	QWORD PTR [rax+16], rdx
	mov	rdx, QWORD PTR [rbx+24]
	mov	QWORD PTR [rax+24], rdx
	movzx	edx, BYTE PTR [rbx+32]
	mov	BYTE PTR [rax+32], dl
	lea	rax, [r12-1]
	mov	rdx, rax
	shr	rdx, 63
	add	rax, rdx
	sar	rax
	cmp	QWORD PTR [rsp+16], r12
	jge	.L60
	mov	rbp, r12
	mov	r12, rax
	jmp	.L62
.L73:
	lea	rax, [rsi+rsi*4]
	mov	rbp, rsi
	lea	rbx, [rdi+rax*8]
	jmp	.L56
	.cfi_endproc
.LFE4130:
	.size	void std::__adjust_heap<(anonymous namespace)::Event*, long, (anonymous namespace)::Event, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, long, long, (anonymous namespace)::Event, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.53], .-void std::__adjust_heap<(anonymous namespace)::Event*, long, (anonymous namespace)::Event, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, long, long, (anonymous namespace)::Event, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.53]
	.p2align 4,,15
	.type	void std::__unguarded_linear_insert<(anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.61], @function
void std::__unguarded_linear_insert<(anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.61]:
.LFB4122:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rdi
	push	rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	lea	rbx, [rdi-40]
	sub	rsp, 56
	.cfi_def_cfa_offset 80
	mov	rax, QWORD PTR [rdi]
	mov	QWORD PTR [rsp], rax
	mov	rax, QWORD PTR [rdi+8]
	mov	QWORD PTR [rsp+8], rax
	mov	rax, QWORD PTR [rdi+16]
	mov	QWORD PTR [rsp+16], rax
	mov	rax, QWORD PTR [rdi+24]
	mov	QWORD PTR [rsp+24], rax
	mov	rax, QWORD PTR [rdi+32]
	mov	QWORD PTR [rsp+32], rax
	jmp	.L75
	.p2align 4,,10
	.p2align 3
.L76:
	mov	rax, QWORD PTR [rbx]
	mov	QWORD PTR [rbp+0], rax
	mov	rax, QWORD PTR [rbx+8]
	mov	QWORD PTR [rbp+8], rax
	mov	rax, QWORD PTR [rbx+16]
	mov	QWORD PTR [rbp+16], rax
	mov	rax, QWORD PTR [rbx+24]
	mov	QWORD PTR [rbp+24], rax
	movzx	eax, BYTE PTR [rbx+32]
	mov	BYTE PTR [rbp+32], al
	mov	rbp, rbx
	sub	rbx, 40
.L75:
	mov	rsi, rbx
	mov	rdi, rsp
	call	(anonymous namespace)::atan2Compare((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)
	test	al, al
	jne	.L76
	mov	rax, QWORD PTR [rsp]
	mov	QWORD PTR [rbp+0], rax
	mov	rax, QWORD PTR [rsp+8]
	mov	QWORD PTR [rbp+8], rax
	mov	rax, QWORD PTR [rsp+16]
	mov	QWORD PTR [rbp+16], rax
	mov	rax, QWORD PTR [rsp+24]
	mov	QWORD PTR [rbp+24], rax
	movzx	eax, BYTE PTR [rsp+32]
	mov	BYTE PTR [rbp+32], al
	add	rsp, 56
	.cfi_def_cfa_offset 24
	pop	rbx
	.cfi_def_cfa_offset 16
	pop	rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE4122:
	.size	void std::__unguarded_linear_insert<(anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.61], .-void std::__unguarded_linear_insert<(anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.61]
	.p2align 4,,15
	.type	void std::__insertion_sort<(anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, (anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.60], @function
void std::__insertion_sort<(anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, (anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.60]:
.LFB4123:
	.cfi_startproc
	push	r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	cmp	rdi, rsi
	mov	r14, rdi
	push	r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	push	r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	push	rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	mov	rbp, rsi
	push	rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	je	.L78
	lea	r13, [rdi+40]
	cmp	rsi, r13
	je	.L78
	movabs	r12, -3689348814741910323
	.p2align 4,,10
	.p2align 3
.L86:
	mov	rsi, r14
	mov	rdi, r13
	mov	rbx, r13
	call	(anonymous namespace)::atan2Compare((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)
	test	al, al
	je	.L81
	mov	rax, rbx
	movsd	xmm0, QWORD PTR [r13+0]
	sub	rax, r14
	movsd	xmm1, QWORD PTR [r13+8]
	sar	rax, 3
	mov	rcx, QWORD PTR [r13+16]
	mov	rsi, QWORD PTR [r13+24]
	imul	rax, r12
	movzx	edi, BYTE PTR [r13+32]
	lea	r13, [r13+40]
	test	rax, rax
	jle	.L85
	.p2align 4,,10
	.p2align 3
.L87:
	sub	rbx, 40
	sub	rax, 1
	mov	rdx, QWORD PTR [rbx]
	mov	QWORD PTR [rbx+40], rdx
	mov	rdx, QWORD PTR [rbx+8]
	mov	QWORD PTR [rbx+48], rdx
	mov	rdx, QWORD PTR [rbx+16]
	mov	QWORD PTR [rbx+56], rdx
	mov	rdx, QWORD PTR [rbx+24]
	mov	QWORD PTR [rbx+64], rdx
	movzx	edx, BYTE PTR [rbx+32]
	mov	BYTE PTR [rbx+72], dl
	jne	.L87
.L85:
	movsd	QWORD PTR [r14], xmm0
	mov	QWORD PTR [r14+16], rcx
	mov	QWORD PTR [r14+24], rsi
	movsd	QWORD PTR [r14+8], xmm1
	mov	BYTE PTR [r14+32], dil
.L83:
	cmp	rbp, r13
	jne	.L86
.L78:
	pop	rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	pop	rbp
	.cfi_def_cfa_offset 32
	pop	r12
	.cfi_def_cfa_offset 24
	pop	r13
	.cfi_def_cfa_offset 16
	pop	r14
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L81:
	.cfi_restore_state
	mov	rdi, r13
	add	r13, 40
	call	void std::__unguarded_linear_insert<(anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.61]
	jmp	.L83
	.cfi_endproc
.LFE4123:
	.size	void std::__insertion_sort<(anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, (anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.60], .-void std::__insertion_sort<(anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, (anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.60]
	.p2align 4,,15
	.type	void std::__introsort_loop<(anonymous namespace)::Point*, long, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, (anonymous namespace)::Point*, long, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.31], @function
void std::__introsort_loop<(anonymous namespace)::Point*, long, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, (anonymous namespace)::Point*, long, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.31]:
.LFB4152:
	.cfi_startproc
	push	r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	mov	rax, rsi
	sub	rax, rdi
	push	r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	push	r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	mov	r13, rsi
	push	r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	mov	r12, rdi
	push	rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	push	rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	sub	rsp, 24
	.cfi_def_cfa_offset 80
	cmp	rax, 271
	jle	.L91
	test	rdx, rdx
	mov	r14, rdx
	je	.L113
	lea	r15, [rdi+16]
.L94:
	mov	rbx, rax
	lea	rbp, [r13-16]
	mov	rdi, r12
	sar	rbx, 5
	sub	r14, 1
	sal	rbx, 4
	add	rbx, r12
	mov	rsi, rbx
	call	(anonymous namespace)::atan2ComparePoints((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)
	test	al, al
	mov	rsi, rbp
	je	.L98
	mov	rdi, rbx
	call	(anonymous namespace)::atan2ComparePoints((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)
	test	al, al
	je	.L99
	movsd	xmm1, QWORD PTR [r12]
	movsd	xmm0, QWORD PTR [r12+8]
.L103:
	mov	rax, QWORD PTR [rbx]
	mov	QWORD PTR [r12], rax
	mov	rax, QWORD PTR [rbx+8]
	mov	QWORD PTR [r12+8], rax
	movsd	QWORD PTR [rbx], xmm1
	movsd	QWORD PTR [rbx+8], xmm0
.L100:
	mov	rbp, r13
	mov	rbx, r15
	jmp	.L119
	.p2align 4,,10
	.p2align 3
.L105:
	add	rbx, 16
.L119:
	mov	rsi, r12
	mov	rdi, rbx
	call	(anonymous namespace)::atan2ComparePoints((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)
	test	al, al
	jne	.L105
	.p2align 4,,10
	.p2align 3
.L107:
	sub	rbp, 16
	mov	rdi, r12
	mov	rsi, rbp
	call	(anonymous namespace)::atan2ComparePoints((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)
	test	al, al
	jne	.L107
	cmp	rbx, rbp
	jae	.L122
	mov	rax, QWORD PTR [rbp+0]
	movsd	xmm1, QWORD PTR [rbx]
	movsd	xmm0, QWORD PTR [rbx+8]
	mov	QWORD PTR [rbx], rax
	mov	rax, QWORD PTR [rbp+8]
	mov	QWORD PTR [rbx+8], rax
	movsd	QWORD PTR [rbp+0], xmm1
	add	rbx, 16
	movsd	QWORD PTR [rbp+8], xmm0
	jmp	.L119
.L122:
	mov	rdx, r14
	mov	rsi, r13
	mov	rdi, rbx
	call	void std::__introsort_loop<(anonymous namespace)::Point*, long, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, (anonymous namespace)::Point*, long, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.31]
	mov	rax, rbx
	sub	rax, r12
	cmp	rax, 271
	jle	.L91
	test	r14, r14
	je	.L111
	mov	r13, rbx
	jmp	.L94
.L98:
	mov	rdi, r12
	call	(anonymous namespace)::atan2ComparePoints((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)
	test	al, al
	jne	.L100
	mov	rsi, rbp
	mov	rdi, rbx
	call	(anonymous namespace)::atan2ComparePoints((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)
	test	al, al
	movsd	xmm1, QWORD PTR [r12]
	movsd	xmm0, QWORD PTR [r12+8]
	je	.L103
.L121:
	mov	rax, QWORD PTR [r13-16]
	mov	QWORD PTR [r12], rax
	mov	rax, QWORD PTR [r13-8]
	mov	QWORD PTR [r12+8], rax
	movsd	QWORD PTR [r13-16], xmm1
	movsd	QWORD PTR [r13-8], xmm0
	jmp	.L100
.L99:
	mov	rsi, rbp
	mov	rdi, r12
	call	(anonymous namespace)::atan2ComparePoints((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)
	test	al, al
	je	.L100
	movsd	xmm1, QWORD PTR [r12]
	movsd	xmm0, QWORD PTR [r12+8]
	jmp	.L121
.L113:
	mov	rbx, r13
.L111:
	mov	r14, rax
	sar	r14, 4
	lea	rbp, [r14-2]
	sar	rbp
	mov	r13, rbp
	sal	r13, 4
	add	r13, r12
	jmp	.L96
.L123:
	sub	rbp, 1
.L96:
	mov	rax, QWORD PTR [r13+0]
	mov	rdx, r14
	mov	rsi, rbp
	mov	rdi, r12
	mov	QWORD PTR [rsp], rax
	mov	rax, QWORD PTR [r13+8]
	sub	r13, 16
	movsd	xmm0, QWORD PTR [rsp]
	mov	QWORD PTR [rsp+8], rax
	movsd	xmm1, QWORD PTR [rsp+8]
	call	void std::__adjust_heap<(anonymous namespace)::Point*, long, (anonymous namespace)::Point, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, long, long, (anonymous namespace)::Point, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.37]
	test	rbp, rbp
	jne	.L123
.L116:
	sub	rbx, 16
	xor	esi, esi
	mov	rdi, r12
	mov	rax, QWORD PTR [rbx]
	mov	rbp, rbx
	sub	rbp, r12
	mov	rdx, rbp
	mov	QWORD PTR [rsp], rax
	mov	rax, QWORD PTR [rbx+8]
	sar	rdx, 4
	movsd	xmm0, QWORD PTR [rsp]
	mov	QWORD PTR [rsp+8], rax
	mov	rax, QWORD PTR [r12]
	movsd	xmm1, QWORD PTR [rsp+8]
	mov	QWORD PTR [rbx], rax
	mov	rax, QWORD PTR [r12+8]
	mov	QWORD PTR [rbx+8], rax
	call	void std::__adjust_heap<(anonymous namespace)::Point*, long, (anonymous namespace)::Point, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, long, long, (anonymous namespace)::Point, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.37]
	cmp	rbp, 31
	jg	.L116
.L91:
	add	rsp, 24
	.cfi_def_cfa_offset 56
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
.LFE4152:
	.size	void std::__introsort_loop<(anonymous namespace)::Point*, long, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, (anonymous namespace)::Point*, long, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.31], .-void std::__introsort_loop<(anonymous namespace)::Point*, long, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, (anonymous namespace)::Point*, long, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.31]
	.p2align 4,,15
	.type	void std::__introsort_loop<(anonymous namespace)::Event*, long, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, (anonymous namespace)::Event*, long, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.47], @function
void std::__introsort_loop<(anonymous namespace)::Event*, long, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, (anonymous namespace)::Event*, long, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.47]:
.LFB4136:
	.cfi_startproc
	push	r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	mov	rax, rsi
	sub	rax, rdi
	push	r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	push	r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	mov	r13, rsi
	push	r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	mov	r12, rdi
	push	rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	push	rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	sub	rsp, 104
	.cfi_def_cfa_offset 160
	cmp	rax, 679
	jle	.L124
	test	rdx, rdx
	mov	r14, rdx
	je	.L146
	lea	r15, [rdi+40]
.L127:
	sar	rax, 3
	movabs	rdx, -3689348814741910323
	lea	rbx, [r13-40]
	imul	rax, rdx
	mov	rdi, r12
	sub	r14, 1
	sar	rax
	lea	rax, [rax+rax*4]
	lea	rbp, [r12+rax*8]
	mov	rsi, rbp
	call	(anonymous namespace)::atan2Compare((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)
	test	al, al
	mov	rsi, rbx
	je	.L131
	mov	rdi, rbp
	call	(anonymous namespace)::atan2Compare((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)
	test	al, al
	je	.L132
	movzx	eax, BYTE PTR [r12+32]
	mov	rcx, QWORD PTR [r12+16]
	mov	rdx, QWORD PTR [r12+24]
	movsd	xmm1, QWORD PTR [r12]
	movsd	xmm0, QWORD PTR [r12+8]
.L136:
	mov	rsi, QWORD PTR [rbp+0]
	mov	QWORD PTR [r12], rsi
	mov	rsi, QWORD PTR [rbp+8]
	mov	QWORD PTR [r12+8], rsi
	mov	rsi, QWORD PTR [rbp+16]
	mov	QWORD PTR [r12+16], rsi
	mov	rsi, QWORD PTR [rbp+24]
	mov	QWORD PTR [r12+24], rsi
	movzx	esi, BYTE PTR [rbp+32]
	mov	BYTE PTR [r12+32], sil
	movsd	QWORD PTR [rbp+0], xmm1
	mov	QWORD PTR [rbp+16], rcx
	movsd	QWORD PTR [rbp+8], xmm0
	mov	QWORD PTR [rbp+24], rdx
	mov	BYTE PTR [rbp+32], al
.L133:
	mov	rbp, r13
	mov	rbx, r15
	jmp	.L151
	.p2align 4,,10
	.p2align 3
.L138:
	add	rbx, 40
.L151:
	mov	rsi, r12
	mov	rdi, rbx
	call	(anonymous namespace)::atan2Compare((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)
	test	al, al
	jne	.L138
	.p2align 4,,10
	.p2align 3
.L140:
	sub	rbp, 40
	mov	rdi, r12
	mov	rsi, rbp
	call	(anonymous namespace)::atan2Compare((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)
	test	al, al
	jne	.L140
	cmp	rbx, rbp
	jae	.L154
	mov	rsi, QWORD PTR [rbp+0]
	movsd	xmm1, QWORD PTR [rbx]
	movsd	xmm0, QWORD PTR [rbx+8]
	mov	rcx, QWORD PTR [rbx+16]
	movzx	eax, BYTE PTR [rbx+32]
	mov	rdx, QWORD PTR [rbx+24]
	mov	QWORD PTR [rbx], rsi
	mov	rsi, QWORD PTR [rbp+8]
	mov	QWORD PTR [rbx+8], rsi
	mov	rsi, QWORD PTR [rbp+16]
	mov	QWORD PTR [rbx+16], rsi
	mov	rsi, QWORD PTR [rbp+24]
	mov	QWORD PTR [rbx+24], rsi
	movzx	esi, BYTE PTR [rbp+32]
	mov	BYTE PTR [rbx+32], sil
	movsd	QWORD PTR [rbp+0], xmm1
	mov	QWORD PTR [rbp+16], rcx
	movsd	QWORD PTR [rbp+8], xmm0
	mov	QWORD PTR [rbp+24], rdx
	mov	BYTE PTR [rbp+32], al
	add	rbx, 40
	jmp	.L151
.L154:
	mov	rdx, r14
	mov	rsi, r13
	mov	rdi, rbx
	call	void std::__introsort_loop<(anonymous namespace)::Event*, long, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, (anonymous namespace)::Event*, long, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.47]
	mov	rax, rbx
	sub	rax, r12
	cmp	rax, 679
	jle	.L124
	test	r14, r14
	je	.L144
	mov	r13, rbx
	jmp	.L127
.L131:
	mov	rdi, r12
	call	(anonymous namespace)::atan2Compare((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)
	test	al, al
	jne	.L133
	mov	rsi, rbx
	mov	rdi, rbp
	call	(anonymous namespace)::atan2Compare((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)
	test	al, al
	movsd	xmm1, QWORD PTR [r12]
	movsd	xmm0, QWORD PTR [r12+8]
	mov	rcx, QWORD PTR [r12+16]
	mov	rdx, QWORD PTR [r12+24]
	movzx	eax, BYTE PTR [r12+32]
	je	.L136
.L153:
	mov	rsi, QWORD PTR [r13-40]
	mov	QWORD PTR [r12], rsi
	mov	rsi, QWORD PTR [r13-32]
	mov	QWORD PTR [r12+8], rsi
	mov	rsi, QWORD PTR [r13-24]
	mov	QWORD PTR [r12+16], rsi
	mov	rsi, QWORD PTR [r13-16]
	mov	QWORD PTR [r12+24], rsi
	movzx	esi, BYTE PTR [r13-8]
	mov	BYTE PTR [r12+32], sil
	movsd	QWORD PTR [r13-40], xmm1
	mov	QWORD PTR [r13-24], rcx
	movsd	QWORD PTR [r13-32], xmm0
	mov	QWORD PTR [r13-16], rdx
	mov	BYTE PTR [r13-8], al
	jmp	.L133
.L132:
	mov	rsi, rbx
	mov	rdi, r12
	call	(anonymous namespace)::atan2Compare((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)
	test	al, al
	je	.L133
	movsd	xmm1, QWORD PTR [r12]
	mov	rcx, QWORD PTR [r12+16]
	movsd	xmm0, QWORD PTR [r12+8]
	mov	rdx, QWORD PTR [r12+24]
	movzx	eax, BYTE PTR [r12+32]
	jmp	.L153
.L146:
	mov	rbx, r13
.L144:
	mov	r14, rax
	movabs	rax, -3689348814741910323
	sar	r14, 3
	imul	r14, rax
	lea	r13, [r14-2]
	sar	r13
	lea	rax, [r13+0+r13*4]
	lea	rbp, [r12+rax*8]
	jmp	.L129
.L155:
	sub	r13, 1
.L129:
	mov	rdi, QWORD PTR [rbp+0]
	mov	rsi, QWORD PTR [rbp+8]
	mov	rdx, QWORD PTR [rbp+24]
	mov	rcx, QWORD PTR [rbp+16]
	mov	rax, QWORD PTR [rbp+32]
	sub	rbp, 40
	mov	QWORD PTR [rsp+48], rdi
	mov	QWORD PTR [rsp+56], rsi
	mov	QWORD PTR [rsp+72], rdx
	mov	QWORD PTR [rsp], rdi
	mov	rdi, r12
	mov	QWORD PTR [rsp+8], rsi
	mov	QWORD PTR [rsp+24], rdx
	mov	rsi, r13
	mov	QWORD PTR [rsp+64], rcx
	mov	QWORD PTR [rsp+80], rax
	mov	rdx, r14
	mov	QWORD PTR [rsp+16], rcx
	mov	QWORD PTR [rsp+32], rax
	call	void std::__adjust_heap<(anonymous namespace)::Event*, long, (anonymous namespace)::Event, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, long, long, (anonymous namespace)::Event, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.53]
	test	r13, r13
	jne	.L155
	movabs	r13, -3689348814741910323
.L149:
	mov	rdx, QWORD PTR [r12]
	sub	rbx, 40
	mov	r8, QWORD PTR [rbx]
	mov	rdi, QWORD PTR [rbx+8]
	mov	rbp, rbx
	mov	rsi, QWORD PTR [rbx+16]
	mov	rcx, QWORD PTR [rbx+24]
	sub	rbp, r12
	mov	QWORD PTR [rbx], rdx
	mov	rdx, QWORD PTR [r12+8]
	mov	rax, QWORD PTR [rbx+32]
	mov	QWORD PTR [rsp+56], rdi
	mov	QWORD PTR [rsp+64], rsi
	mov	QWORD PTR [rsp+48], r8
	mov	QWORD PTR [rbx+8], rdx
	mov	rdx, QWORD PTR [r12+16]
	mov	QWORD PTR [rsp+72], rcx
	mov	QWORD PTR [rsp+80], rax
	mov	QWORD PTR [rbx+16], rdx
	mov	rdx, QWORD PTR [r12+24]
	mov	QWORD PTR [rbx+24], rdx
	movzx	edx, BYTE PTR [r12+32]
	mov	BYTE PTR [rbx+32], dl
	mov	rdx, rbp
	mov	QWORD PTR [rsp+8], rdi
	sar	rdx, 3
	mov	QWORD PTR [rsp+16], rsi
	mov	QWORD PTR [rsp], r8
	imul	rdx, r13
	xor	esi, esi
	mov	QWORD PTR [rsp+24], rcx
	mov	QWORD PTR [rsp+32], rax
	mov	rdi, r12
	call	void std::__adjust_heap<(anonymous namespace)::Event*, long, (anonymous namespace)::Event, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, long, long, (anonymous namespace)::Event, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.53]
	cmp	rbp, 79
	jg	.L149
.L124:
	add	rsp, 104
	.cfi_def_cfa_offset 56
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
.LFE4136:
	.size	void std::__introsort_loop<(anonymous namespace)::Event*, long, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, (anonymous namespace)::Event*, long, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.47], .-void std::__introsort_loop<(anonymous namespace)::Event*, long, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, (anonymous namespace)::Event*, long, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.47]
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC4:
	.string	"vector::_M_range_insert"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB3749:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3749
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
	sub	rsp, 200
	.cfi_def_cfa_offset 256
.LEHB0:
	call	std::ios_base::sync_with_stdio(bool)
	lea	rsi, [rsp+136]
	mov	edi, OFFSET FLAT:std::cin
	call	std::basic_istream<char, std::char_traits<char> >::operator>>(unsigned long&)
.L303:
	mov	rax, QWORD PTR [rsp+136]
	lea	rdx, [rax-1]
	test	rax, rax
	mov	QWORD PTR [rsp+136], rdx
	je	.L300
	mov	esi, OFFSET FLAT:(anonymous namespace)::n
	mov	edi, OFFSET FLAT:std::cin
	xor	ebx, ebx
	call	std::basic_istream<char, std::char_traits<char> >& std::basic_istream<char, std::char_traits<char> >::_M_extract<unsigned long>(unsigned long&)
	mov	esi, OFFSET FLAT:(anonymous namespace)::R
	mov	rdi, rax
	call	std::basic_istream<char, std::char_traits<char> >& std::basic_istream<char, std::char_traits<char> >::_M_extract<unsigned long>(unsigned long&)
	mov	rdi, QWORD PTR (anonymous namespace)::n[rip]
	sal	rdi, 4
	call	operator new[](unsigned long)
	cmp	QWORD PTR (anonymous namespace)::n[rip], 0
	mov	QWORD PTR (anonymous namespace)::points[rip], rax
	jne	.L288
	jmp	.L161
	.p2align 4,,10
	.p2align 3
.L305:
	mov	rax, QWORD PTR (anonymous namespace)::points[rip]
.L288:
	mov	rbp, rbx
	mov	edi, OFFSET FLAT:std::cin
	add	rbx, 1
	sal	rbp, 4
	add	rbp, rax
	mov	rsi, rbp
	call	std::basic_istream<char, std::char_traits<char> >& std::basic_istream<char, std::char_traits<char> >::_M_extract<double>(double&)
	lea	rsi, [rbp+8]
	mov	rdi, rax
	call	std::basic_istream<char, std::char_traits<char> >& std::basic_istream<char, std::char_traits<char> >::_M_extract<double>(double&)
	mov	rax, QWORD PTR (anonymous namespace)::n[rip]
	cmp	rbx, rax
	jb	.L305
	test	rax, rax
	je	.L161
	mov	QWORD PTR [rsp+112], 0
	xor	ebp, ebp
	.p2align 4,,10
	.p2align 3
.L220:
	lea	rdi, [rax+rax*4]
	sal	rdi, 4
	call	operator new[](unsigned long)
	cmp	QWORD PTR (anonymous namespace)::n[rip], 0
	mov	r12, rax
	je	.L236
	mov	rcx, rbp
	xor	r15d, r15d
	xor	ebx, ebx
	sal	rcx, 4
	movsd	xmm10, QWORD PTR .LC2[rip]
	jmp	.L186
	.p2align 4,,10
	.p2align 3
.L307:
	lea	rax, [r15+r15*4]
	lea	rax, [r12+rax*8]
	movsd	QWORD PTR [rax], xmm2
	mov	QWORD PTR [rax+16], rbx
	mov	QWORD PTR [rax+24], rbp
	movsd	QWORD PTR [rax+8], xmm5
	mov	BYTE PTR [rax+32], 0
	lea	rax, [r15+5+r15*4]
	add	r15, 2
	lea	rax, [r12+rax*8]
	movsd	QWORD PTR [rax], xmm2
	mov	QWORD PTR [rax+16], rbx
	mov	QWORD PTR [rax+24], rbp
	movsd	QWORD PTR [rax+8], xmm5
	mov	BYTE PTR [rax+32], 1
	.p2align 4,,10
	.p2align 3
.L163:
	mov	rdi, QWORD PTR (anonymous namespace)::n[rip]
	add	rbx, 1
	cmp	rbx, rdi
	jae	.L306
.L186:
	cmp	rbp, rbx
	je	.L163
	mov	r13, QWORD PTR (anonymous namespace)::points[rip]
	mov	rax, QWORD PTR (anonymous namespace)::R[rip]
	mov	r14, rbx
	sal	r14, 4
	add	r14, r13
	test	rax, rax
	movsd	xmm8, QWORD PTR [r14]
	movsd	xmm5, QWORD PTR [r14+8]
	js	.L164
	cvtsi2sd	xmm1, rax
.L165:
	add	r13, rcx
	movapd	xmm3, xmm5
	movsd	xmm7, QWORD PTR [r13+0]
	movsd	xmm9, QWORD PTR [r13+8]
	movapd	xmm4, xmm8
	mulsd	xmm1, xmm1
	subsd	xmm3, xmm9
	subsd	xmm4, xmm7
	movapd	xmm0, xmm3
	movapd	xmm2, xmm4
	mulsd	xmm0, xmm3
	mulsd	xmm2, xmm4
	addsd	xmm2, xmm0
	divsd	xmm1, xmm2
	movapd	xmm0, xmm1
	movapd	xmm2, xmm1
	subsd	xmm0, xmm1
	addsd	xmm2, xmm10
	addsd	xmm0, QWORD PTR .LC0[rip]
	mulsd	xmm0, QWORD PTR .LC1[rip]
	movapd	xmm6, xmm0
	mulsd	xmm6, xmm0
	ucomisd	xmm6, xmm2
	jae	.L163
	movapd	xmm2, xmm0
	mulsd	xmm5, xmm0
	mulsd	xmm9, xmm0
	mulsd	xmm2, xmm8
	mulsd	xmm0, xmm7
	addsd	xmm5, xmm9
	addsd	xmm2, xmm0
	movapd	xmm0, xmm1
	subsd	xmm0, xmm10
	ucomisd	xmm6, xmm0
	ja	.L307
	movapd	xmm0, xmm1
	subsd	xmm0, xmm6
	sqrtsd	xmm6, xmm0
	ucomisd	xmm6, xmm6
	jp	.L308
.L169:
	movsd	xmm0, QWORD PTR .LC3[rip]
	lea	rsi, [rsp+192]
	mulsd	xmm4, xmm6
	movapd	xmm7, xmm2
	xorpd	xmm3, xmm0
	lea	rdi, [rsp+144]
	mov	edx, 2
	mulsd	xmm3, xmm6
	movapd	xmm6, xmm5
	subsd	xmm5, xmm4
	addsd	xmm6, xmm4
	addsd	xmm7, xmm3
	subsd	xmm2, xmm3
	movapd	xmm0, xmm6
	movapd	xmm1, xmm7
	subsd	xmm0, QWORD PTR [r13+8]
	subsd	xmm1, QWORD PTR [r13+0]
	movsd	QWORD PTR [rsp+152], xmm0
	movapd	xmm0, xmm5
	movsd	QWORD PTR [rsp+144], xmm1
	movapd	xmm1, xmm2
	subsd	xmm0, QWORD PTR [r13+8]
	subsd	xmm1, QWORD PTR [r13+0]
	movsd	QWORD PTR [rsp+168], xmm0
	movsd	QWORD PTR [rsp+160], xmm1
	movsd	xmm0, QWORD PTR [r14+8]
	movsd	xmm1, QWORD PTR [r14]
	subsd	xmm0, QWORD PTR [r13+8]
	subsd	xmm1, QWORD PTR [r13+0]
	mov	QWORD PTR [rsp+56], rcx
	movsd	QWORD PTR [rsp+16], xmm2
	movsd	QWORD PTR [rsp+32], xmm5
	movsd	QWORD PTR [rsp+80], xmm6
	movsd	QWORD PTR [rsp+64], xmm7
	movsd	QWORD PTR [rsp], xmm10
	movsd	QWORD PTR [rsp+184], xmm0
	movsd	QWORD PTR [rsp+176], xmm1
	call	void std::__introsort_loop<(anonymous namespace)::Point*, long, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, (anonymous namespace)::Point*, long, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.31]
	lea	rsi, [rsp+192]
	lea	rdi, [rsp+144]
	call	void std::__insertion_sort<(anonymous namespace)::Point*, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)>((anonymous namespace)::Point*, (anonymous namespace)::Point*, bool (*)((anonymous namespace)::Point const&, (anonymous namespace)::Point const&)) [clone .constprop.44]
	movsd	xmm7, QWORD PTR [rsp+64]
	mov	rcx, QWORD PTR [rsp+56]
	movsd	xmm0, QWORD PTR [r13+0]
	movapd	xmm9, xmm7
	movsd	xmm3, QWORD PTR [rsp+144]
	movsd	xmm6, QWORD PTR [rsp+80]
	subsd	xmm9, xmm0
	movsd	xmm1, QWORD PTR [r13+8]
	movapd	xmm11, xmm6
	movsd	xmm2, QWORD PTR [rsp+16]
	subsd	xmm11, xmm1
	movsd	xmm5, QWORD PTR [rsp+32]
	ucomisd	xmm9, xmm3
	movsd	xmm10, QWORD PTR [rsp]
	jp	.L246
	jne	.L246
	ucomisd	xmm11, QWORD PTR [rsp+152]
	movsd	xmm8, QWORD PTR [r14+8]
	movsd	xmm4, QWORD PTR [r14]
	subsd	xmm8, xmm1
	subsd	xmm4, xmm0
	jp	.L173
	jne	.L173
	ucomisd	xmm4, QWORD PTR [rsp+160]
	jp	.L173
	.p2align 4,,2
	jne	.L173
	ucomisd	xmm8, QWORD PTR [rsp+168]
	jp	.L173
	jne	.L173
.L238:
	xor	esi, esi
	mov	edx, 1
.L176:
	lea	rax, [r15+r15*4]
	mov	rdi, QWORD PTR (anonymous namespace)::n[rip]
	lea	rax, [r12+rax*8]
	mov	QWORD PTR [rax+16], rbx
	movsd	QWORD PTR [rax], xmm7
	mov	QWORD PTR [rax+24], rbp
	movsd	QWORD PTR [rax+8], xmm6
	mov	BYTE PTR [rax+32], sil
	lea	rax, [r15+5+r15*4]
	add	r15, 2
	lea	rax, [r12+rax*8]
	mov	QWORD PTR [rax+16], rbx
	add	rbx, 1
	movsd	QWORD PTR [rax], xmm2
	cmp	rbx, rdi
	movsd	QWORD PTR [rax+8], xmm5
	mov	QWORD PTR [rax+24], rbp
	mov	BYTE PTR [rax+32], dl
	jb	.L186
	.p2align 4,,10
	.p2align 3
.L306:
	lea	rax, [r15+r15*4]
	lea	rbx, [r12+rax*8]
	cmp	r12, rbx
	je	.L239
	mov	r13, rbx
	movabs	rax, -3689348814741910323
	mov	edx, 63
	sub	r13, r12
	mov	rsi, rbx
	mov	rdi, r12
	mov	r15, r13
	sar	r15, 3
	imul	r15, rax
	bsr	rax, r15
	xor	eax, 63
	cdqe
	sub	rdx, rax
	add	rdx, rdx
	call	void std::__introsort_loop<(anonymous namespace)::Event*, long, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, (anonymous namespace)::Event*, long, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.47]
	cmp	r13, 679
	jg	.L309
	mov	rsi, rbx
	mov	rdi, r12
	call	void std::__insertion_sort<(anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, (anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.60]
.L304:
	mov	rdi, QWORD PTR (anonymous namespace)::n[rip]
.L162:
	call	operator new[](unsigned long)
	mov	rcx, QWORD PTR (anonymous namespace)::n[rip]
	mov	r13, rax
	test	rcx, rcx
	lea	rdx, [rcx+r13]
	je	.L194
	.p2align 4,,10
	.p2align 3
.L276:
	mov	BYTE PTR [rax], 0
	add	rax, 1
	cmp	rax, rdx
	jne	.L276
.L194:
	xor	esi, esi
	xor	r14d, r14d
	test	r15, r15
	je	.L192
	movabs	rax, 461168601842738790
	cmp	r15, rax
	ja	.L310
	lea	rsi, [r15+r15*4]
	sal	rsi, 3
	mov	rdi, rsi
	mov	QWORD PTR [rsp+80], rsi
	call	operator new(unsigned long)
	mov	rsi, QWORD PTR [rsp+80]
	mov	r14, rax
.L192:
	cmp	r12, rbx
	lea	rdi, [r14+rsi]
	je	.L196
	mov	rdx, r14
	mov	rax, r12
	.p2align 4,,10
	.p2align 3
.L198:
	test	rdx, rdx
	je	.L197
	mov	rcx, QWORD PTR [rax]
	mov	QWORD PTR [rdx], rcx
	mov	rcx, QWORD PTR [rax+8]
	mov	QWORD PTR [rdx+8], rcx
	mov	rcx, QWORD PTR [rax+16]
	mov	QWORD PTR [rdx+16], rcx
	mov	rcx, QWORD PTR [rax+24]
	mov	QWORD PTR [rdx+24], rcx
	mov	rcx, QWORD PTR [rax+32]
	mov	QWORD PTR [rdx+32], rcx
.L197:
	add	rax, 40
	add	rdx, 40
	cmp	rbx, rax
	jne	.L198
	lea	rax, [r12+40]
	mov	rdx, rbx
	sub	rdx, rax
	mov	rax, rdx
	movabs	rdx, -3689348814741910323
	shr	rax, 3
	lea	rax, [40+rax*8]
	mov	QWORD PTR [rsp+120], rax
	add	rax, r14
	mov	QWORD PTR [rsp+104], rax
	mov	rax, rdi
	sub	rax, QWORD PTR [rsp+104]
	sar	rax, 3
	imul	rax, rdx
	cmp	rax, r15
	jb	.L199
	mov	rdx, QWORD PTR [rsp+104]
	mov	rax, r12
	.p2align 4,,10
	.p2align 3
.L201:
	test	rdx, rdx
	je	.L200
	mov	rcx, QWORD PTR [rax]
	mov	QWORD PTR [rdx], rcx
	mov	rcx, QWORD PTR [rax+8]
	mov	QWORD PTR [rdx+8], rcx
	mov	rcx, QWORD PTR [rax+16]
	mov	QWORD PTR [rdx+16], rcx
	mov	rcx, QWORD PTR [rax+24]
	mov	QWORD PTR [rdx+24], rcx
	mov	rcx, QWORD PTR [rax+32]
	mov	QWORD PTR [rdx+32], rcx
.L200:
	add	rax, 40
	add	rdx, 40
	cmp	rbx, rax
	jne	.L201
	add	rsi, QWORD PTR [rsp+104]
.L202:
	cmp	rsi, r14
	je	.L196
	mov	rax, r14
	xor	ecx, ecx
	jmp	.L216
	.p2align 4,,10
	.p2align 3
.L212:
	add	rdx, QWORD PTR [rax+16]
	cmp	BYTE PTR [rdx], 0
	jne	.L214
	add	rcx, 1
	cmp	QWORD PTR [rsp+112], rcx
	mov	rdi, QWORD PTR [rsp+112]
	mov	BYTE PTR [rdx], 1
	cmovb	rdi, rcx
	mov	QWORD PTR [rsp+112], rdi
.L214:
	add	rax, 40
	cmp	rax, rsi
	je	.L196
.L216:
	cmp	BYTE PTR [rax+32], 0
	mov	rdx, r13
	je	.L212
	add	rdx, QWORD PTR [rax+16]
	cmp	BYTE PTR [rdx], 0
	je	.L214
	add	rax, 40
	sub	rcx, 1
	mov	BYTE PTR [rdx], 0
	cmp	rax, rsi
	jne	.L216
.L196:
	test	r13, r13
	je	.L217
	mov	rdi, r13
	call	operator delete[](void*)
.L217:
	test	r12, r12
	je	.L218
	mov	rdi, r12
	call	operator delete[](void*)
.L218:
	test	r14, r14
	je	.L219
	mov	rdi, r14
	call	operator delete(void*)
.L219:
	mov	rax, QWORD PTR (anonymous namespace)::n[rip]
	add	rbp, 1
	cmp	rax, rbp
	ja	.L220
	mov	rsi, QWORD PTR [rsp+112]
	add	rsi, 1
.L159:
	mov	edi, OFFSET FLAT:std::cout
	call	std::basic_ostream<char, std::char_traits<char> >& std::basic_ostream<char, std::char_traits<char> >::_M_insert<unsigned long>(unsigned long)
	lea	rsi, [rsp+135]
	mov	rdi, rax
	mov	edx, 1
	mov	BYTE PTR [rsp+135], 10
	call	std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long)
.LEHE0:
	mov	rdi, QWORD PTR (anonymous namespace)::points[rip]
	test	rdi, rdi
	je	.L303
	call	operator delete[](void*)
	jmp	.L303
	.p2align 4,,10
	.p2align 3
.L164:
	mov	rdx, rax
	and	eax, 1
	shr	rdx
	or	rdx, rax
	cvtsi2sd	xmm1, rdx
	addsd	xmm1, xmm1
	jmp	.L165
	.p2align 4,,10
	.p2align 3
.L246:
	movsd	xmm8, QWORD PTR [r14+8]
	movsd	xmm4, QWORD PTR [r14]
	subsd	xmm8, xmm1
	subsd	xmm4, xmm0
.L173:
	ucomisd	xmm4, xmm3
	jp	.L250
	jne	.L250
	ucomisd	xmm8, QWORD PTR [rsp+152]
	jp	.L250
	jne	.L250
	movapd	xmm4, xmm5
	subsd	xmm4, xmm1
	movapd	xmm1, xmm4
	movapd	xmm4, xmm2
	subsd	xmm4, xmm0
	ucomisd	xmm4, QWORD PTR [rsp+160]
	movapd	xmm0, xmm4
	jp	.L180
	jne	.L180
	ucomisd	xmm1, QWORD PTR [rsp+168]
	jp	.L180
	.p2align 4,,2
	je	.L238
.L180:
	ucomisd	xmm3, xmm0
	jp	.L252
	.p2align 4,,10
	.p2align 3
.L311:
	jne	.L252
	ucomisd	xmm1, QWORD PTR [rsp+152]
	jp	.L252
	.p2align 4,,2
	jne	.L252
	ucomisd	xmm9, QWORD PTR [rsp+160]
	jp	.L252
	jne	.L252
	ucomisd	xmm11, QWORD PTR [rsp+168]
	mov	edx, 1
	jp	.L185
	jne	.L185
	mov	esi, 1
	xor	esi, edx
	jmp	.L176
.L185:
	xor	edx, edx
	mov	esi, 1
	xor	esi, edx
	jmp	.L176
	.p2align 4,,10
	.p2align 3
.L250:
	movapd	xmm4, xmm5
	subsd	xmm4, xmm1
	movapd	xmm1, xmm4
	movapd	xmm4, xmm2
	subsd	xmm4, xmm0
	movapd	xmm0, xmm4
	ucomisd	xmm3, xmm0
	jnp	.L311
.L252:
	mov	esi, 1
	xor	edx, edx
	jmp	.L176
	.p2align 4,,10
	.p2align 3
.L309:
	lea	r13, [r12+640]
	mov	rdi, r12
	mov	rsi, r13
	call	void std::__insertion_sort<(anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, (anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.60]
	cmp	rbx, r13
	je	.L304
	.p2align 4,,10
	.p2align 3
.L277:
	mov	rdi, r13
	add	r13, 40
	call	void std::__unguarded_linear_insert<(anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)>((anonymous namespace)::Event*, bool (*)((anonymous namespace)::Event const&, (anonymous namespace)::Event const&)) [clone .constprop.61]
	cmp	rbx, r13
	jne	.L277
	jmp	.L304
	.p2align 4,,10
	.p2align 3
.L199:
	mov	rax, QWORD PTR [rsp+104]
	sub	rax, r14
	sar	rax, 3
	imul	rax, rdx
	movabs	rdx, 461168601842738790
	mov	rcx, rdx
	sub	rcx, rax
	cmp	rcx, r15
	jb	.L312
	cmp	rax, r15
	mov	rdi, -16
	cmovae	r15, rax
	add	r15, rax
	jae	.L313
.L204:
.LEHB1:
	call	operator new(unsigned long)
.LEHE1:
	cmp	QWORD PTR [rsp+104], r14
	mov	r15, rax
	je	.L243
.L315:
	mov	rcx, r15
	mov	rdx, r14
	.p2align 4,,10
	.p2align 3
.L208:
	test	rcx, rcx
	je	.L207
	mov	rax, QWORD PTR [rdx]
	mov	QWORD PTR [rcx], rax
	mov	rax, QWORD PTR [rdx+8]
	mov	QWORD PTR [rcx+8], rax
	mov	rax, QWORD PTR [rdx+16]
	mov	QWORD PTR [rcx+16], rax
	mov	rax, QWORD PTR [rdx+24]
	mov	QWORD PTR [rcx+24], rax
	mov	rax, QWORD PTR [rdx+32]
	mov	QWORD PTR [rcx+32], rax
.L207:
	add	rdx, 40
	add	rcx, 40
	cmp	QWORD PTR [rsp+104], rdx
	jne	.L208
	mov	rdi, QWORD PTR [rsp+104]
	lea	rax, [r14+40]
	sub	rdi, rax
	mov	rax, rdi
	shr	rax, 3
	lea	rsi, [r15+40+rax*8]
.L206:
	mov	rcx, rsi
	mov	rdx, r12
	.p2align 4,,10
	.p2align 3
.L210:
	test	rcx, rcx
	je	.L209
	mov	rax, QWORD PTR [rdx]
	mov	QWORD PTR [rcx], rax
	mov	rax, QWORD PTR [rdx+8]
	mov	QWORD PTR [rcx+8], rax
	mov	rax, QWORD PTR [rdx+16]
	mov	QWORD PTR [rcx+16], rax
	mov	rdi, QWORD PTR [rdx+24]
	mov	QWORD PTR [rcx+24], rdi
	mov	rdi, QWORD PTR [rdx+32]
	mov	QWORD PTR [rcx+32], rdi
.L209:
	add	rdx, 40
	add	rcx, 40
	cmp	rbx, rdx
	jne	.L210
	mov	rbx, QWORD PTR [rsp+120]
	add	rbx, rsi
	test	r14, r14
	je	.L211
	mov	rdi, r14
	call	operator delete(void*)
.L211:
	mov	rsi, rbx
	mov	r14, r15
	jmp	.L202
	.p2align 4,,10
	.p2align 3
.L239:
	mov	rbx, r12
	xor	r15d, r15d
	jmp	.L162
.L236:
	mov	rbx, rax
	xor	r15d, r15d
	xor	edi, edi
	jmp	.L162
.L313:
	cmp	r15, rdx
	ja	.L204
	test	r15, r15
	jne	.L314
	xor	r15d, r15d
	cmp	QWORD PTR [rsp+104], r14
	jne	.L315
.L243:
	mov	rsi, r15
	jmp	.L206
.L161:
	mov	esi, 1
	jmp	.L159
.L300:
	add	rsp, 200
	.cfi_remember_state
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
.L308:
	.cfi_restore_state
	mov	QWORD PTR [rsp+56], rcx
	movsd	QWORD PTR [rsp+16], xmm2
	movsd	QWORD PTR [rsp+80], xmm3
	movsd	QWORD PTR [rsp+64], xmm4
	movsd	QWORD PTR [rsp+32], xmm5
	movsd	QWORD PTR [rsp], xmm10
	call	sqrt
	movsd	xmm10, QWORD PTR [rsp]
	movapd	xmm6, xmm0
	movsd	xmm5, QWORD PTR [rsp+32]
	movsd	xmm4, QWORD PTR [rsp+64]
	mov	rcx, QWORD PTR [rsp+56]
	movsd	xmm3, QWORD PTR [rsp+80]
	movsd	xmm2, QWORD PTR [rsp+16]
	jmp	.L169
.L310:
.LEHB2:
	call	std::__throw_bad_alloc()
.L314:
	imul	rdi, r15, 40
	jmp	.L204
.L244:
	test	r14, r14
	mov	rbx, rax
	je	.L224
	mov	rdi, r14
	call	operator delete(void*)
.L224:
	mov	rdi, rbx
	call	_Unwind_Resume
.LEHE2:
.L312:
	mov	edi, OFFSET FLAT:.LC4
.LEHB3:
	call	std::__throw_length_error(char const*)
.LEHE3:
	.cfi_endproc
.LFE3749:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA3749:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3749-.LLSDACSB3749
.LLSDACSB3749:
	.uleb128 .LEHB0-.LFB3749
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB3749
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L244-.LFB3749
	.uleb128 0
	.uleb128 .LEHB2-.LFB3749
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB3-.LFB3749
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L244-.LFB3749
	.uleb128 0
.LLSDACSE3749:
	.section	.text.startup
	.size	main, .-main
	.p2align 4,,15
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB4091:
	.cfi_startproc
	sub	rsp, 8
	.cfi_def_cfa_offset 16
	mov	edi, OFFSET FLAT:std::__ioinit
	call	std::ios_base::Init::Init()
	mov	edx, OFFSET FLAT:__dso_handle
	mov	esi, OFFSET FLAT:std::__ioinit
	mov	edi, OFFSET FLAT:std::ios_base::Init::~Init()
	add	rsp, 8
	.cfi_def_cfa_offset 8
	jmp	__cxa_atexit
	.cfi_endproc
.LFE4091:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.local	(anonymous namespace)::n
	.comm	(anonymous namespace)::n,8,8
	.local	(anonymous namespace)::R
	.comm	(anonymous namespace)::R,8,8
	.local	(anonymous namespace)::points
	.comm	(anonymous namespace)::points,8,8
	.local	std::__ioinit
	.comm	std::__ioinit,1,1
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1072693248
	.align 8
.LC1:
	.long	0
	.long	1071644672
	.align 8
.LC2:
	.long	3894859413
	.long	1041313291
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC3:
	.long	0
	.long	-2147483648
	.long	0
	.long	0
	.hidden	__dso_handle
	.ident	"GCC: (Gentoo 4.7.2-r1 p1.5, pie-0.5.5) 4.7.2"
	.section	.note.GNU-stack,"",@progbits

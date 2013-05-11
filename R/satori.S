	.file	"satori.cxx"
	.intel_syntax noprefix
# GNU C++ (Gentoo 4.7.2-r1 p1.5, pie-0.5.5) version 4.7.2 (x86_64-pc-linux-gnu)
#	compiled by GNU C version 4.7.2, GMP version 5.1.1, MPFR version 3.1.2, MPC version 1.0.1
# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -D_GNU_SOURCE satori.cxx -march=core2 -mcx16 -msahf
# -mno-movbe -mno-aes -mno-pclmul -mno-popcnt -mno-abm -mno-lwp -mno-fma
# -mno-fma4 -mno-xop -mno-bmi -mno-bmi2 -mno-tbm -mno-avx -mno-avx2
# -mno-sse4.2 -msse4.1 -mno-lzcnt -mno-rdrnd -mno-f16c -mno-fsgsbase
# --param l1-cache-size=32 --param l1-cache-line-size=64
# --param l2-cache-size=6144 -mtune=core2 -masm=intel
# -auxbase-strip satori.S -O2 -fverbose-asm
# options enabled:  -fasynchronous-unwind-tables -fauto-inc-dec
# -fbranch-count-reg -fcaller-saves -fcombine-stack-adjustments -fcommon
# -fcompare-elim -fcprop-registers -fcrossjumping -fcse-follow-jumps
# -fdebug-types-section -fdefer-pop -fdelete-null-pointer-checks
# -fdevirtualize -fdwarf2-cfi-asm -fearly-inlining
# -feliminate-unused-debug-types -fexceptions -fexpensive-optimizations
# -fforward-propagate -ffunction-cse -fgcse -fgcse-lm -fgnu-runtime
# -fguess-branch-probability -fident -fif-conversion -fif-conversion2
# -findirect-inlining -finline -finline-atomics
# -finline-functions-called-once -finline-small-functions -fipa-cp
# -fipa-profile -fipa-pure-const -fipa-reference -fipa-sra
# -fira-share-save-slots -fira-share-spill-slots -fivopts
# -fkeep-static-consts -fleading-underscore -fmath-errno -fmerge-constants
# -fmerge-debug-strings -fmove-loop-invariants -fomit-frame-pointer
# -foptimize-register-move -foptimize-sibling-calls -foptimize-strlen
# -fpartial-inlining -fpeephole -fpeephole2 -fprefetch-loop-arrays -free
# -freg-struct-return -fregmove -freorder-blocks -freorder-functions
# -frerun-cse-after-loop -fsched-critical-path-heuristic
# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-insns2
# -fshow-column -fshrink-wrap -fsigned-zeros -fsplit-ivs-in-unroller
# -fsplit-wide-types -fstrict-aliasing -fstrict-overflow
# -fstrict-volatile-bitfields -fthread-jumps -ftoplevel-reorder
# -ftrapping-math -ftree-bit-ccp -ftree-builtin-call-dce -ftree-ccp
# -ftree-ch -ftree-copy-prop -ftree-copyrename -ftree-cselim -ftree-dce
# -ftree-dominator-opts -ftree-dse -ftree-forwprop -ftree-fre
# -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop -ftree-pre
# -ftree-pta -ftree-reassoc -ftree-scev-cprop -ftree-sink
# -ftree-slp-vectorize -ftree-sra -ftree-switch-conversion
# -ftree-tail-merge -ftree-ter -ftree-vect-loop-version -ftree-vrp
# -funit-at-a-time -funwind-tables -fvect-cost-model -fverbose-asm
# -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
# -maccumulate-outgoing-args -malign-stringops -mcx16 -mfancy-math-387
# -mfp-ret-in-387 -mglibc -mieee-fp -mmmx -mpush-args -mred-zone -msahf
# -msse -msse2 -msse3 -msse4.1 -mssse3 -mtls-direct-seg-refs

	.text
	.p2align 4,,15
	.type	_ZN12_GLOBAL__N_1L9fpow_implEmmm, @function
_ZN12_GLOBAL__N_1L9fpow_implEmmm:
.LFB3729:
	.cfi_startproc
	mov	QWORD PTR [rsp-16], rbx	#,
	.cfi_offset 3, -24
	mov	rbx, rdx	# mod, mod
	mov	edx, 1	# D.63844,
	mov	QWORD PTR [rsp-8], rbp	#,
	sub	rsp, 24	#,
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -16
	test	rsi, rsi	# exponent
	je	.L2	#,
	test	sil, 1	# exponent,
	mov	rbp, rdi	# base, base
	jne	.L8	#,
	mov	rdx, rbx	#, mod
	shr	rsi	# tmp76
	call	_ZN12_GLOBAL__N_1L9fpow_implEmmm	#
	xor	edx, edx	# D.63844
	imul	rax, rax	# tmp77, tmp77
	div	rbx	# mod
.L2:
	mov	rax, rdx	#, D.63844
	mov	rbx, QWORD PTR [rsp+8]	#,
	mov	rbp, QWORD PTR [rsp+16]	#,
	add	rsp, 24	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L8:
	.cfi_restore_state
	mov	rdx, rbx	#, mod
	sub	rsi, 1	# tmp72,
	call	_ZN12_GLOBAL__N_1L9fpow_implEmmm	#
	xor	edx, edx	# D.63844
	imul	rax, rbp	# tmp73, base
	div	rbx	# mod
	jmp	.L2	#
	.cfi_endproc
.LFE3729:
	.size	_ZN12_GLOBAL__N_1L9fpow_implEmmm, .-_ZN12_GLOBAL__N_1L9fpow_implEmmm
	.align 2
	.p2align 4,,15
	.type	_ZNSt8_Rb_treeIN12_GLOBAL__N_14PackES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE8_M_eraseEPSt13_Rb_tree_nodeIS1_E, @function
_ZNSt8_Rb_treeIN12_GLOBAL__N_14PackES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE8_M_eraseEPSt13_Rb_tree_nodeIS1_E:
.LFB3915:
	.cfi_startproc
	push	r12	#
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	test	rsi, rsi	# __x
	mov	r12, rdi	# this, this
	push	rbp	#
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	push	rbx	#
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	mov	rbx, rsi	# __x, __x
	je	.L9	#,
	.p2align 4,,10
	.p2align 3
.L13:
	mov	rsi, QWORD PTR [rbx+24]	# MEM[(struct _Rb_tree_node_base *)__x_21 + 24B], MEM[(struct _Rb_tree_node_base *)__x_21 + 24B]
	mov	rdi, r12	#, this
	call	_ZNSt8_Rb_treeIN12_GLOBAL__N_14PackES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE8_M_eraseEPSt13_Rb_tree_nodeIS1_E	#
	mov	rbp, QWORD PTR [rbx+16]	# __y, MEM[(struct _Rb_tree_node_base *)__x_21 + 16B]
	mov	rdi, rbx	#, __x
	call	_ZdlPv	#
	test	rbp, rbp	# __x
	mov	rbx, rbp	# __x, __y
	jne	.L13	#,
.L9:
	pop	rbx	#
	.cfi_def_cfa_offset 24
	pop	rbp	#
	.cfi_def_cfa_offset 16
	pop	r12	#
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3915:
	.size	_ZNSt8_Rb_treeIN12_GLOBAL__N_14PackES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE8_M_eraseEPSt13_Rb_tree_nodeIS1_E, .-_ZNSt8_Rb_treeIN12_GLOBAL__N_14PackES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE8_M_eraseEPSt13_Rb_tree_nodeIS1_E
	.align 2
	.p2align 4,,15
	.type	_ZNSt8_Rb_treeIN12_GLOBAL__N_14PackES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE10_M_insert_EPKSt18_Rb_tree_node_baseSA_RKS1_, @function
_ZNSt8_Rb_treeIN12_GLOBAL__N_14PackES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE10_M_insert_EPKSt18_Rb_tree_node_baseSA_RKS1_:
.LFB4000:
	.cfi_startproc
	mov	QWORD PTR [rsp-40], rbp	#,
	.cfi_offset 6, -48
	mov	rbp, rcx	# __v, __v
	mov	QWORD PTR [rsp-32], r12	#,
	.cfi_offset 12, -40
	mov	r12, rdi	# this, this
	mov	QWORD PTR [rsp-24], r13	#,
	.cfi_offset 13, -32
	mov	r13, rdx	# __p, __p
	mov	QWORD PTR [rsp-16], r14	#,
	.cfi_offset 14, -24
	lea	r14, [rdi+8]	# tmp90,
	mov	QWORD PTR [rsp-8], r15	#,
	.cfi_offset 15, -16
	mov	r15d, 1	# prephitmp.244,
	mov	QWORD PTR [rsp-48], rbx	#,
	sub	rsp, 56	#,
	.cfi_def_cfa_offset 64
	.cfi_offset 3, -56
	test	rsi, rsi	# __x
	je	.L27	#,
.L17:
	mov	edi, 72	#,
	call	_Znwm	#
	cmp	rax, -32	# __z,
	mov	rbx, rax	# __z,
	je	.L19	#,
	mov	rax, QWORD PTR [rbp+0]	# *__v_12(D), *__v_12(D)
	mov	QWORD PTR [rbx+32], rax	# MEM[(struct Pack *)__z_52 + 32B], *__v_12(D)
	mov	rax, QWORD PTR [rbp+8]	# *__v_12(D), *__v_12(D)
	mov	QWORD PTR [rbx+40], rax	# MEM[(struct Pack *)__z_52 + 32B], *__v_12(D)
	mov	rax, QWORD PTR [rbp+16]	# *__v_12(D), *__v_12(D)
	mov	QWORD PTR [rbx+48], rax	# MEM[(struct Pack *)__z_52 + 32B], *__v_12(D)
	mov	rax, QWORD PTR [rbp+24]	# *__v_12(D), *__v_12(D)
	mov	QWORD PTR [rbx+56], rax	# MEM[(struct Pack *)__z_52 + 32B], *__v_12(D)
	mov	rax, QWORD PTR [rbp+32]	# *__v_12(D), *__v_12(D)
	mov	QWORD PTR [rbx+64], rax	# MEM[(struct Pack *)__z_52 + 32B], *__v_12(D)
.L19:
	mov	rcx, r14	#, tmp90
	mov	rdx, r13	#, __p
	mov	rsi, rbx	#, __z
	mov	edi, r15d	#, prephitmp.244
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_	#
	mov	rax, rbx	#, __z
	mov	rbp, QWORD PTR [rsp+16]	#,
	add	QWORD PTR [r12+40], 1	# this_6(D)->_M_impl._M_node_count,
	mov	rbx, QWORD PTR [rsp+8]	#,
	mov	r12, QWORD PTR [rsp+24]	#,
	mov	r13, QWORD PTR [rsp+32]	#,
	mov	r14, QWORD PTR [rsp+40]	#,
	mov	r15, QWORD PTR [rsp+48]	#,
	add	rsp, 56	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L27:
	.cfi_restore_state
	cmp	rdx, r14	# __p, tmp90
	je	.L17	#,
	mov	rdx, QWORD PTR [rcx]	# D.65031, MEM[(const struct Matrix &)__v_12(D)].data
	mov	rax, QWORD PTR [r13+32]	# D.65032, MEM[(const struct Matrix &)__p_8(D) + 32].data
	cmp	rdx, rax	# D.65031, D.65032
	jne	.L18	#,
	mov	rdx, QWORD PTR [rcx+8]	# D.65031, MEM[(const struct Matrix &)__v_12(D)].data
	mov	rax, QWORD PTR [r13+40]	# D.65032, MEM[(const struct Matrix &)__p_8(D) + 32].data
	cmp	rdx, rax	# D.65031, D.65032
	jne	.L18	#,
	mov	rdx, QWORD PTR [rcx+16]	# D.65031, MEM[(const struct Matrix &)__v_12(D)].data
	mov	rax, QWORD PTR [r13+48]	# D.65032, MEM[(const struct Matrix &)__p_8(D) + 32].data
	cmp	rdx, rax	# D.65031, D.65032
	jne	.L18	#,
	mov	rdx, QWORD PTR [rcx+24]	# D.65031, MEM[(const struct Matrix &)__v_12(D)].data
	xor	r15b, r15b	#
	mov	rax, QWORD PTR [r13+56]	# D.65032, MEM[(const struct Matrix &)__p_8(D) + 32].data
	cmp	rdx, rax	# D.65031, D.65032
	je	.L17	#,
.L18:
	xor	r15d, r15d	# prephitmp.244
	cmp	rdx, rax	# D.65031, D.65032
	setb	r15b	#, prephitmp.244
	jmp	.L17	#
	.cfi_endproc
.LFE4000:
	.size	_ZNSt8_Rb_treeIN12_GLOBAL__N_14PackES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE10_M_insert_EPKSt18_Rb_tree_node_baseSA_RKS1_, .-_ZNSt8_Rb_treeIN12_GLOBAL__N_14PackES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE10_M_insert_EPKSt18_Rb_tree_node_baseSA_RKS1_
	.p2align 4,,15
	.type	_ZN12_GLOBAL__N_1L8solutionEv, @function
_ZN12_GLOBAL__N_1L8solutionEv:
.LFB3743:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA3743
	push	r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	mov	edi, OFFSET FLAT:_ZSt3cin	#,
	push	r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	push	r13	#
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	push	r12	#
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	push	rbp	#
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	push	rbx	#
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	sub	rsp, 504	#,
	.cfi_def_cfa_offset 560
	lea	rsi, [rsp+112]	#,
.LEHB0:
	call	_ZNSirsERm	#
	mov	rax, QWORD PTR [rsp+112]	# z.2, z
	lea	rdx, [rax-1]	# tmp422,
	test	rax, rax	# z.2
	mov	QWORD PTR [rsp+112], rdx	# z, tmp422
	je	.L28	#,
	lea	rax, [rsp+456]	#,
	mov	QWORD PTR [rsp+24], rax	# %sfp,
.L77:
	mov	esi, OFFSET FLAT:_ZN12_GLOBAL__N_1L1pE	#,
	mov	edi, OFFSET FLAT:_ZSt3cin	#,
	call	_ZNSi10_M_extractImEERSiRT_	#
	lea	rsi, [rsp+120]	#,
	mov	rdi, rax	#, D.65295
	call	_ZNSi10_M_extractImEERSiRT_	#
	lea	rsi, [rsp+128]	#,
	mov	rdi, rax	#, D.65299
	call	_ZNSi10_M_extractImEERSiRT_	#
	lea	rsi, [rsp+136]	#,
	mov	rdi, rax	#, D.65303
	call	_ZNSi10_M_extractImEERSiRT_	#
.LEHE0:
	mov	rcx, QWORD PTR _ZN12_GLOBAL__N_1L1pE[rip]	# p.6, p
	xor	edx, edx	#
	mov	rsi, QWORD PTR [rsp+120]	# a.4, a
	mov	rax, rcx	# tmp428, p.6
	add	rax, QWORD PTR [rsp+128]	# tmp428, b
	mov	QWORD PTR [rsp+152], rsi	# Z.data, a.4
	mov	QWORD PTR [rsp+160], rsi	# Z.data, a.4
	sub	rax, rsi	# tmp428, a.4
	div	rcx	# p.6
	lea	rax, [rdx+rsi]	# tmp431,
	mov	rdi, rdx	# tmp429,
	xor	edx, edx	# tmp432
	mov	QWORD PTR [rsp+168], rdi	# Z.data, tmp429
	div	rcx	# p.6
	mov	rax, QWORD PTR [rsp+136]	# d, d
	mov	QWORD PTR [rsp+144], rdx	# Z.data, tmp432
	test	rax, rax	# d
	js	.L30	#,
	cvtsi2sd	xmm0, rax	# tmp435, d
	sqrtsd	xmm0, xmm0	# tmp434, tmp435
	ucomisd	xmm0, xmm0	# tmp434, tmp434
	jp	.L141	#,
.L32:
	call	ceil	#
	addsd	xmm0, QWORD PTR .LC0[rip]	# tmp445,
	ucomisd	xmm0, QWORD PTR .LC1[rip]	# tmp445,
	jae	.L36	#,
	cvttsd2si	rbp, xmm0	# s, tmp445
.L37:
	xor	edx, edx	# tmp453
	mov	eax, 1	# tmp452,
	mov	QWORD PTR [rsp+216], 1	# A.data,
	div	QWORD PTR _ZN12_GLOBAL__N_1L1pE[rip]	# p
	test	rbp, rbp	# s
	mov	QWORD PTR [rsp+208], rdx	# A.data, tmp453
	mov	QWORD PTR [rsp+224], 1	# A.data,
	mov	QWORD PTR [rsp+232], 0	# A.data,
	mov	QWORD PTR [rsp+200], 1	# m.data,
	mov	QWORD PTR [rsp+176], 1	# m.data,
	mov	QWORD PTR [rsp+192], 0	# m.data,
	mov	QWORD PTR [rsp+184], 0	# m.data,
	je	.L38	#,
	xor	r14d, r14d	# left$_M_end_of_storage
	xor	ebx, ebx	# left$_M_finish
	xor	r12d, r12d	# i
	mov	QWORD PTR [rsp+72], 0	# %sfp,
	jmp	.L49	#
	.p2align 4,,10
	.p2align 3
.L143:
	test	rbx, rbx	# left$_M_finish
	je	.L40	#,
	mov	rax, QWORD PTR [rsp+176]	# m, m
	mov	QWORD PTR [rbx], rax	# *left$_M_finish_444, m
	mov	rax, QWORD PTR [rsp+184]	# m, m
	mov	QWORD PTR [rbx+8], rax	# *left$_M_finish_444, m
	mov	rax, QWORD PTR [rsp+192]	# m, m
	mov	QWORD PTR [rbx+16], rax	# *left$_M_finish_444, m
	mov	rax, QWORD PTR [rsp+200]	# m, m
	mov	QWORD PTR [rbx+24], rax	# *left$_M_finish_444, m
.L40:
	add	rbx, 32	# left$_M_finish,
.L41:
	mov	r8, QWORD PTR [rsp+176]	# D.65336, m.data
	xor	edx, edx	#
	add	r12, 1	# i,
	mov	r13, QWORD PTR _ZN12_GLOBAL__N_1L1pE[rip]	# pretmp.320, p
	mov	rcx, QWORD PTR [rsp+184]	# D.65336, m.data
	mov	rax, r8	# tmp476, D.65336
	imul	rax, QWORD PTR [rsp+216]	# tmp476, A.data
	mov	rsi, rcx	# tmp481, D.65336
	imul	rsi, QWORD PTR [rsp+224]	# tmp481, A.data
	div	r13	# pretmp.320
	mov	rax, r8	# tmp482, D.65336
	mov	r9, rdx	# tmp479,
	imul	rax, QWORD PTR [rsp+208]	# tmp482, A.data
	xor	edx, edx	# tmp484
	mov	r8, QWORD PTR [rsp+192]	# D.65336, m.data
	div	r13	# pretmp.320
	lea	rax, [rsi+rdx]	# D.65333,
	mov	rsi, rcx	# tmp486, D.65336
	imul	rsi, QWORD PTR [rsp+232]	# tmp486, A.data
	xor	edx, edx	#
	div	r13	# pretmp.320
	mov	rdi, rdx	# tmp487,
	mov	QWORD PTR [rsp+336], rdx	# result.data, tmp487
	xor	edx, edx	#
	mov	QWORD PTR [rsp+176], rdi	# m, tmp487
	add	rsi, r9	# D.65333, tmp479
	mov	r9, QWORD PTR [rsp+200]	# D.65336, m.data
	mov	rax, rsi	# tmp490, D.65333
	div	r13	# pretmp.320
	mov	rax, r8	# tmp491, D.65336
	mov	rsi, rdx	# tmp489,
	imul	rax, QWORD PTR [rsp+208]	# tmp491, A.data
	mov	QWORD PTR [rsp+344], rdx	# result.data, tmp489
	xor	edx, edx	#
	mov	QWORD PTR [rsp+184], rsi	# m, tmp489
	div	r13	# pretmp.320
	mov	rax, r8	# tmp496, D.65336
	mov	rcx, rdx	# tmp494,
	imul	rax, QWORD PTR [rsp+216]	# tmp496, A.data
	xor	edx, edx	# tmp499
	mov	r8, r9	# tmp502, D.65336
	imul	r8, QWORD PTR [rsp+232]	# tmp502, A.data
	div	r13	# pretmp.320
	mov	rax, r9	# tmp501, D.65336
	imul	rax, QWORD PTR [rsp+224]	# tmp501, A.data
	add	r8, rdx	# D.65333, tmp499
	xor	edx, edx	#
	add	rax, rcx	# D.65333, tmp494
	div	r13	# pretmp.320
	mov	rax, r8	# tmp506, D.65333
	mov	rcx, rdx	# tmp503,
	mov	QWORD PTR [rsp+352], rdx	# result.data, tmp503
	xor	edx, edx	# tmp505
	div	r13	# pretmp.320
	cmp	r12, rbp	# i, s
	mov	QWORD PTR [rsp+360], rdx	# result.data, tmp505
	mov	QWORD PTR [rsp+192], rcx	# m, tmp503
	mov	QWORD PTR [rsp+200], rdx	# m, tmp505
	je	.L142	#,
.L49:
	cmp	rbx, r14	# left$_M_finish, left$_M_end_of_storage
	jne	.L143	#,
	mov	r13, rbx	# tmp460, left$_M_finish
	mov	r14d, 32	# prephitmp.357,
	sub	r13, QWORD PTR [rsp+72]	# tmp460, %sfp
	sar	r13, 5	# tmp460,
	test	r13, r13	# tmp460
	je	.L43	#,
	lea	rax, [r13+r13]	# __len,
	cmp	r13, rax	# tmp460, __len
	jbe	.L144	#,
	mov	r14, -32	# prephitmp.357,
.L43:
	mov	rdi, r14	#, prephitmp.357
.LEHB1:
	call	_Znwm	#
.LEHE1:
	lea	r15, [rax+32]	# left$_M_finish,
	mov	rdx, r13	# tmp462, tmp460
	sal	rdx, 5	# tmp462,
	add	rdx, rax	# D.65503, left$_M_start
	je	.L44	#,
	mov	rsi, QWORD PTR [rsp+176]	# m, m
	mov	QWORD PTR [rdx], rsi	# *D.65503_292, m
	mov	rsi, QWORD PTR [rsp+184]	# m, m
	mov	QWORD PTR [rdx+8], rsi	# *D.65503_292, m
	mov	rsi, QWORD PTR [rsp+192]	# m, m
	mov	QWORD PTR [rdx+16], rsi	# *D.65503_292, m
	mov	rsi, QWORD PTR [rsp+200]	# m, m
	mov	QWORD PTR [rdx+24], rsi	# *D.65503_292, m
.L44:
	cmp	rbx, QWORD PTR [rsp+72]	# left$_M_finish, %sfp
	je	.L45	#,
	mov	rdx, QWORD PTR [rsp+72]	# left$_M_start, %sfp
	mov	rcx, rax	# ivtmp.404, left$_M_start
.L47:
	test	rcx, rcx	# ivtmp.404
	je	.L46	#,
	mov	rsi, QWORD PTR [rdx]	# MEM[base: left$_M_start_314, offset: 0], MEM[base: left$_M_start_314, offset: 0]
	mov	QWORD PTR [rcx], rsi	# MEM[base: left$_M_start_646, offset: 0B], MEM[base: left$_M_start_314, offset: 0]
	mov	rsi, QWORD PTR [rdx+8]	# MEM[base: left$_M_start_314, offset: 0], MEM[base: left$_M_start_314, offset: 0]
	mov	QWORD PTR [rcx+8], rsi	# MEM[base: left$_M_start_646, offset: 0B], MEM[base: left$_M_start_314, offset: 0]
	mov	rsi, QWORD PTR [rdx+16]	# MEM[base: left$_M_start_314, offset: 0], MEM[base: left$_M_start_314, offset: 0]
	mov	QWORD PTR [rcx+16], rsi	# MEM[base: left$_M_start_646, offset: 0B], MEM[base: left$_M_start_314, offset: 0]
	mov	rsi, QWORD PTR [rdx+24]	# MEM[base: left$_M_start_314, offset: 0], MEM[base: left$_M_start_314, offset: 0]
	mov	QWORD PTR [rcx+24], rsi	# MEM[base: left$_M_start_646, offset: 0B], MEM[base: left$_M_start_314, offset: 0]
.L46:
	add	rdx, 32	# left$_M_start,
	add	rcx, 32	# ivtmp.404,
	cmp	rdx, rbx	# left$_M_start, left$_M_finish
	jne	.L47	#,
	mov	rcx, QWORD PTR [rsp+72]	# tmp471, %sfp
	add	rcx, 32	# tmp471,
	sub	rdx, rcx	# tmp474, tmp471
	and	rdx, -32	# tmp474,
	lea	r15, [rax+64+rdx]	# left$_M_finish,
.L45:
	cmp	QWORD PTR [rsp+72], 0	# %sfp,
	je	.L48	#,
	mov	rdi, QWORD PTR [rsp+72]	#, %sfp
	mov	QWORD PTR [rsp+16], rax	#,
	call	_ZdlPv	#
	mov	rax, QWORD PTR [rsp+16]	#,
.L48:
	add	r14, rax	# left$_M_end_of_storage, left$_M_start
	mov	rbx, r15	# left$_M_finish, left$_M_finish
	mov	QWORD PTR [rsp+72], rax	# %sfp, left$_M_start
	jmp	.L41	#
.L142:
	mov	QWORD PTR [rsp+256], rcx	# mm, tmp503
	mov	rcx, QWORD PTR [rsp+24]	#, %sfp
	cmp	rbp, 1	# s,
	mov	QWORD PTR [rsp+240], rdi	# mm, tmp487
	mov	QWORD PTR [rsp+248], rsi	# mm, tmp489
	mov	QWORD PTR [rsp+264], rdx	# mm, tmp505
	mov	DWORD PTR [rsp+456], 0	# MEM[(struct _Rb_tree_impl *)&right]._M_header._M_color,
	mov	QWORD PTR [rsp+464], 0	# MEM[(struct _Rb_tree_impl *)&right]._M_header._M_parent,
	mov	QWORD PTR [rsp+488], 0	# MEM[(struct _Rb_tree_impl *)&right]._M_node_count,
	mov	QWORD PTR [rsp+472], rcx	# MEM[(struct _Rb_tree_impl *)&right]._M_header._M_left,
	mov	QWORD PTR [rsp+480], rcx	# MEM[(struct _Rb_tree_impl *)&right]._M_header._M_right,
	je	.L50	#,
	mov	r12, rbp	# s, s
	xor	r14d, r14d	# __j$_M_node
	mov	ebx, 1	# i,
	.p2align 4,,10
	.p2align 3
.L61:
	mov	rcx, QWORD PTR [rsp+240]	# mm, mm
	test	r14, r14	# __j$_M_node
	mov	QWORD PTR [rsp+432], r12	# D.59681.id, s
	mov	rsi, QWORD PTR [rsp+248]	# mm, mm
	mov	rdi, QWORD PTR [rsp+256]	# mm, mm
	mov	r8, QWORD PTR [rsp+264]	# mm, mm
	mov	QWORD PTR [rsp+400], rcx	# D.59681.m, mm
	mov	QWORD PTR [rsp+408], rsi	# D.59681.m, mm
	mov	QWORD PTR [rsp+416], rdi	# D.59681.m, mm
	mov	QWORD PTR [rsp+424], r8	# D.59681.m, mm
	je	.L86	#,
	mov	r9, rcx	# D.65566, mm
	jmp	.L52	#
	.p2align 4,,10
	.p2align 3
.L146:
	mov	r14, rax	# __j$_M_node, __j$_M_node
.L52:
	mov	rdx, QWORD PTR [r14+32]	# D.65565, MEM[(const struct Matrix &)__j$_M_node_625 + 32].data
	cmp	rcx, rdx	# mm, D.65565
	jne	.L87	#,
	mov	rax, QWORD PTR [r14+40]	# D.65565, MEM[(const struct Matrix &)__j$_M_node_625 + 32].data
	cmp	rsi, rax	# mm, D.65565
	jne	.L88	#,
	mov	rax, QWORD PTR [r14+48]	# D.65565, MEM[(const struct Matrix &)__j$_M_node_625 + 32].data
	cmp	rdi, rax	# mm, D.65565
	jne	.L89	#,
	mov	rax, QWORD PTR [r14+56]	# D.65565, MEM[(const struct Matrix &)__j$_M_node_625 + 32].data
	cmp	r8, rax	# mm, D.65565
	jne	.L145	#,
.L53:
	mov	rax, QWORD PTR [r14+24]	# __j$_M_node, MEM[(struct _Rb_tree_node_base *)__j$_M_node_625 + 24B]
	xor	r10d, r10d	# __comp
.L54:
	test	rax, rax	# __j$_M_node
	jne	.L146	#,
	test	r10b, r10b	# __comp
	mov	rax, r14	# __j$_M_node, __j$_M_node
	jne	.L51	#,
	cmp	r9, rdx	# D.65566, D.65565
	jne	.L60	#,
.L147:
	mov	rdx, QWORD PTR [rax+40]	# D.65565, MEM[(const struct Matrix &)__j$_M_node_492 + 32].data
	mov	r9, QWORD PTR [rsp+408]	# D.65566, MEM[(const struct Matrix &)&D.59681].data
	cmp	rdx, r9	# D.65565, D.65566
	jne	.L60	#,
	mov	rdx, QWORD PTR [rax+48]	# D.65565, MEM[(const struct Matrix &)__j$_M_node_492 + 32].data
	mov	r9, QWORD PTR [rsp+416]	# D.65566, MEM[(const struct Matrix &)&D.59681].data
	cmp	rdx, r9	# D.65565, D.65566
	jne	.L60	#,
	mov	rdx, QWORD PTR [rax+56]	# D.65565, MEM[(const struct Matrix &)__j$_M_node_492 + 32].data
	mov	r9, QWORD PTR [rsp+424]	# D.65566, MEM[(const struct Matrix &)&D.59681].data
	cmp	rdx, r9	# D.65565, D.65566
	jne	.L60	#,
.L59:
	mov	rdi, QWORD PTR [rsp+240]	# D.65354, mm.data
	xor	edx, edx	#
	add	rbx, 1	# i,
	mov	rcx, QWORD PTR [rsp+248]	# D.65354, mm.data
	add	r12, rbp	# s, s
	mov	r9, QWORD PTR [rsp+264]	# D.65354, mm.data
	mov	rax, rdi	# tmp527, D.65354
	imul	rax, QWORD PTR [rsp+184]	# tmp527, m.data
	mov	rsi, rcx	# tmp537, D.65354
	imul	rsi, QWORD PTR [rsp+200]	# tmp537, m.data
	div	r13	# pretmp.320
	mov	rax, rdi	# tmp532, D.65354
	mov	r8, rdx	# tmp530,
	imul	rax, QWORD PTR [rsp+176]	# tmp532, m.data
	xor	edx, edx	# tmp534
	add	rsi, r8	# D.65351, tmp530
	mov	r8, QWORD PTR [rsp+256]	# D.65354, mm.data
	div	r13	# pretmp.320
	mov	rax, rcx	# tmp536, D.65354
	imul	rax, QWORD PTR [rsp+192]	# tmp536, m.data
	add	rax, rdx	# D.65351, tmp534
	xor	edx, edx	#
	div	r13	# pretmp.320
	mov	rax, rsi	# tmp541, D.65351
	mov	rdi, rdx	# tmp538,
	mov	QWORD PTR [rsp+368], rdx	# result.data, tmp538
	xor	edx, edx	#
	div	r13	# pretmp.320
	mov	rax, r8	# tmp542, D.65354
	mov	rsi, rdx	# tmp540,
	imul	rax, QWORD PTR [rsp+176]	# tmp542, m.data
	mov	QWORD PTR [rsp+376], rdx	# result.data, tmp540
	xor	edx, edx	#
	mov	QWORD PTR [rsp+240], rdi	# mm, tmp538
	mov	QWORD PTR [rsp+248], rsi	# mm, tmp540
	div	r13	# pretmp.320
	mov	rax, r8	# tmp547, D.65354
	mov	rcx, rdx	# tmp545,
	imul	rax, QWORD PTR [rsp+184]	# tmp547, m.data
	xor	edx, edx	# tmp550
	mov	r8, r9	# tmp553, D.65354
	imul	r8, QWORD PTR [rsp+200]	# tmp553, m.data
	div	r13	# pretmp.320
	mov	rax, r9	# tmp552, D.65354
	imul	rax, QWORD PTR [rsp+192]	# tmp552, m.data
	add	r8, rdx	# D.65351, tmp550
	xor	edx, edx	#
	add	rax, rcx	# D.65351, tmp545
	div	r13	# pretmp.320
	mov	rax, r8	# tmp557, D.65351
	mov	rcx, rdx	# tmp554,
	mov	QWORD PTR [rsp+384], rdx	# result.data, tmp554
	xor	edx, edx	# tmp556
	div	r13	# pretmp.320
	cmp	rbx, rbp	# i, s
	mov	QWORD PTR [rsp+392], rdx	# result.data, tmp556
	mov	QWORD PTR [rsp+256], rcx	# mm, tmp554
	mov	QWORD PTR [rsp+264], rdx	# mm, tmp556
	je	.L50	#,
	mov	r14, QWORD PTR [rsp+464]	# __j$_M_node, MEM[(struct _Rb_tree *)&right + 16B]
	jmp	.L61	#
.L86:
	mov	r14, QWORD PTR [rsp+24]	# __j$_M_node, %sfp
	.p2align 4,,10
	.p2align 3
.L51:
	cmp	r14, QWORD PTR [rsp+472]	# __j$_M_node, MEM[(struct _Rb_tree *)&right + 24B]
	je	.L140	#,
	mov	rdi, r14	#, __j$_M_node
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base	#
	mov	r9, QWORD PTR [rsp+400]	# D.65566, MEM[(const struct Matrix &)&D.59681].data
	mov	rdx, QWORD PTR [rax+32]	# D.65565, MEM[(const struct Matrix &)__j$_M_node_359 + 32].data
	cmp	r9, rdx	# D.65566, D.65565
	je	.L147	#,
	.p2align 4,,10
	.p2align 3
.L60:
	cmp	rdx, r9	# D.65565, D.65566
	jae	.L59	#,
.L140:
	lea	rcx, [rsp+400]	#,
	mov	rdx, r14	#, __j$_M_node
	xor	esi, esi	#
	lea	rdi, [rsp+448]	#,
.LEHB2:
	call	_ZNSt8_Rb_treeIN12_GLOBAL__N_14PackES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE10_M_insert_EPKSt18_Rb_tree_node_baseSA_RKS1_	#
	mov	r13, QWORD PTR _ZN12_GLOBAL__N_1L1pE[rip]	# pretmp.320, p
	jmp	.L59	#
	.p2align 4,,10
	.p2align 3
.L87:
	mov	rax, rdx	# D.65565, D.65565
	mov	r10, rcx	# D.65566, mm
.L56:
	cmp	r10, rax	# D.65566, D.65565
	jae	.L53	#,
	mov	rax, QWORD PTR [r14+16]	# __j$_M_node, MEM[(struct _Rb_tree_node_base *)__j$_M_node_625 + 16B]
	mov	r10d, 1	# __comp,
	jmp	.L54	#
	.p2align 4,,10
	.p2align 3
.L88:
	mov	r10, rsi	# D.65566, mm
	jmp	.L56	#
	.p2align 4,,10
	.p2align 3
.L89:
	mov	r10, rdi	# D.65566, mm
	jmp	.L56	#
	.p2align 4,,10
	.p2align 3
.L145:
	mov	r10, r8	# D.65566, mm
	jmp	.L56	#
.L50:
	lea	rcx, [r13-2]	#,
	mov	rbx, QWORD PTR [rsp+72]	# ivtmp.381, %sfp
	mov	r14, -1	# best,
	mov	QWORD PTR [rsp+80], rcx	# %sfp,
	mov	rcx, QWORD PTR [rsp+464]	#, MEM[(struct _Rb_tree *)&right + 16B]
	xor	r12d, r12d	# i
	mov	QWORD PTR [rsp+88], rbp	# %sfp, s
	mov	QWORD PTR [rsp+40], rcx	# %sfp,
	mov	rcx, QWORD PTR [rsp+144]	#, Z.data
	mov	QWORD PTR [rsp+32], rcx	# %sfp,
	mov	rcx, QWORD PTR [rsp+152]	#, Z.data
	mov	QWORD PTR [rsp+48], rcx	# %sfp,
	mov	rcx, QWORD PTR [rsp+160]	#, Z.data
	mov	QWORD PTR [rsp+56], rcx	# %sfp,
	mov	rcx, QWORD PTR [rsp+168]	#, Z.data
	mov	QWORD PTR [rsp+64], rcx	# %sfp,
	.p2align 4,,10
	.p2align 3
.L73:
	mov	r15, QWORD PTR [rbx+24]	# d, MEM[base: D.65834_319, offset: 24B]
	xor	edx, edx	# tmp566
	mov	r8, QWORD PTR [rbx+16]	# c, MEM[base: D.65834_319, offset: 16B]
	mov	rbp, QWORD PTR [rbx]	# a, MEM[base: D.65834_319, offset: 0B]
	mov	rcx, QWORD PTR [rbx+8]	# b, MEM[base: D.65834_319, offset: 8B]
	mov	rsi, r15	# tmp562, d
	mov	rax, r8	# tmp564, c
	mov	QWORD PTR [rsp+8], r8	#,
	imul	rsi, rbp	# tmp562, a
	imul	rax, rcx	# tmp564, b
	mov	QWORD PTR [rsp+16], rcx	#,
	add	rsi, r13	# tmp568, pretmp.320
	div	r13	# pretmp.320
	sub	rsi, rdx	# tmp568, tmp566
	xor	edx, edx	#
	mov	rax, rsi	# tmp571, tmp568
	mov	rsi, QWORD PTR [rsp+80]	#, %sfp
	div	r13	# pretmp.320
	mov	rax, rdx	# tmp573, tmp570
	xor	edx, edx	#
	div	r13	# pretmp.320
	mov	rdi, rdx	# tmp572,
	mov	rdx, r13	#, pretmp.320
	call	_ZN12_GLOBAL__N_1L9fpow_implEmmm	#
	mov	rcx, QWORD PTR [rsp+16]	#,
	xor	edi, edi	# prephitmp.326
	mov	rsi, rax	# s,
	mov	r8, QWORD PTR [rsp+8]	#,
	test	rcx, rcx	# b
	je	.L62	#,
	mov	rax, r13	# tmp575, pretmp.320
	xor	edx, edx	#
	sub	rax, rcx	# tmp575, b
	imul	rax, rsi	# tmp575, s
	div	r13	# pretmp.320
	mov	rdi, rdx	# prephitmp.326,
.L62:
	xor	ecx, ecx	# prephitmp.326
	test	r8, r8	# c
	je	.L63	#,
	mov	rax, r13	# tmp579, pretmp.320
	xor	edx, edx	#
	sub	rax, r8	# tmp579, c
	imul	rax, rsi	# tmp579, s
	div	r13	# pretmp.320
	mov	rcx, rdx	# prephitmp.326,
.L63:
	mov	rax, r15	# tmp582, d
	xor	edx, edx	#
	mov	QWORD PTR [rsp+320], rcx	# D.59798.data, prephitmp.326
	imul	rax, rsi	# tmp582, s
	div	r13	# pretmp.320
	mov	rax, rbp	# tmp585, a
	mov	r11, rdx	# tmp583,
	imul	rax, rsi	# tmp585, s
	xor	edx, edx	#
	div	r13	# pretmp.320
	mov	rax, QWORD PTR [rsp+32]	# tmp588, %sfp
	mov	r10, rdx	# tmp586,
	mov	QWORD PTR [rsp+328], rdx	# D.59798.data, tmp586
	xor	edx, edx	#
	imul	rax, rdi	# tmp588, prephitmp.326
	div	r13	# pretmp.320
	mov	rax, QWORD PTR [rsp+32]	# tmp593, %sfp
	mov	r8, rdx	# tmp591,
	xor	edx, edx	# tmp595
	imul	rax, r11	# tmp593, tmp583
	div	r13	# pretmp.320
	mov	rax, QWORD PTR [rsp+48]	# tmp597, %sfp
	imul	rax, rcx	# tmp597, prephitmp.326
	add	rax, rdx	# D.65373, tmp595
	mov	rdx, QWORD PTR [rsp+48]	# tmp598, %sfp
	imul	rdx, r10	# tmp598, tmp586
	add	r8, rdx	# D.65373, tmp598
	xor	edx, edx	#
	div	r13	# pretmp.320
	mov	rax, r8	# tmp602, D.65373
	mov	rsi, rdx	# tmp599,
	mov	QWORD PTR [rsp+272], rdx	# F.data, tmp599
	xor	edx, edx	#
	div	r13	# pretmp.320
	mov	rax, QWORD PTR [rsp+56]	# tmp603, %sfp
	mov	r8, rdx	# tmp601,
	mov	QWORD PTR [rsp+280], rdx	# F.data, tmp601
	xor	edx, edx	#
	imul	rax, r11	# tmp603, tmp583
	div	r13	# pretmp.320
	mov	rax, QWORD PTR [rsp+56]	# tmp608, %sfp
	mov	r9, rdx	# tmp606,
	xor	edx, edx	# tmp611
	imul	rax, rdi	# tmp608, prephitmp.326
	mov	rdi, QWORD PTR [rsp+64]	# tmp614, %sfp
	imul	rdi, r10	# tmp614, tmp586
	div	r13	# pretmp.320
	mov	rax, QWORD PTR [rsp+64]	# tmp613, %sfp
	imul	rax, rcx	# tmp613, prephitmp.326
	mov	rcx, QWORD PTR [rsp+40]	# __j$_M_node, %sfp
	add	rdi, rdx	# D.65373, tmp611
	xor	edx, edx	#
	add	rax, r9	# D.65373, tmp606
	div	r13	# pretmp.320
	mov	rax, rdi	# tmp618, D.65373
	mov	r9, rdx	# tmp615,
	mov	QWORD PTR [rsp+288], rdx	# F.data, tmp615
	xor	edx, edx	#
	div	r13	# pretmp.320
	test	rcx, rcx	#
	mov	rdi, rdx	# tmp617,
	mov	QWORD PTR [rsp+296], rdx	# F.data, tmp617
	mov	r11, rdx	# D.65636, tmp617
	mov	rdx, QWORD PTR [rsp+24]	# __j$_M_node, %sfp
	je	.L65	#,
	.p2align 4,,10
	.p2align 3
.L123:
	mov	rax, QWORD PTR [rcx+32]	# D.65635, MEM[(const struct Matrix &)__j$_M_node_637 + 32].data
	cmp	rsi, rax	# tmp599, D.65635
	jne	.L96	#,
	mov	rax, QWORD PTR [rcx+40]	# D.65635, MEM[(const struct Matrix &)__j$_M_node_637 + 32].data
	cmp	rax, r8	# D.65635, tmp601
	jne	.L97	#,
	mov	rax, QWORD PTR [rcx+48]	# D.65635, MEM[(const struct Matrix &)__j$_M_node_637 + 32].data
	cmp	rax, r9	# D.65635, tmp615
	jne	.L98	#,
	mov	rax, QWORD PTR [rcx+56]	# D.65635, MEM[(const struct Matrix &)__j$_M_node_637 + 32].data
	cmp	rdi, rax	# tmp617, D.65635
	jne	.L148	#,
.L70:
	mov	rdx, rcx	# __j$_M_node, __j$_M_node
	mov	rcx, QWORD PTR [rcx+16]	# __j$_M_node, MEM[(struct _Rb_tree_node_base *)__j$_M_node_637 + 16B]
.L67:
	test	rcx, rcx	# __j$_M_node
	jne	.L123	#,
	cmp	rdx, QWORD PTR [rsp+24]	# __j$_M_node, %sfp
	je	.L65	#,
	mov	rax, QWORD PTR [rdx+32]	# D.65621, MEM[(const struct Matrix &)__j$_M_node_458 + 32].data
	cmp	rsi, rax	# tmp599, D.65621
	jne	.L100	#,
	mov	rax, QWORD PTR [rdx+40]	# D.65621, MEM[(const struct Matrix &)__j$_M_node_458 + 32].data
	cmp	rax, r8	# D.65621, tmp601
	jne	.L101	#,
	mov	rax, QWORD PTR [rdx+48]	# D.65621, MEM[(const struct Matrix &)__j$_M_node_458 + 32].data
	cmp	rax, r9	# D.65621, tmp615
	jne	.L102	#,
	mov	rax, QWORD PTR [rdx+56]	# D.65621, MEM[(const struct Matrix &)__j$_M_node_458 + 32].data
	cmp	rdi, rax	# tmp617, D.65621
	jne	.L71	#,
.L72:
	mov	rax, r12	# best, i
	add	rax, QWORD PTR [rdx+64]	# best, MEM[(const struct Pack *)__j$_M_node_458 + 32B].id
	cmp	r14, rax	# best, best
	cmova	r14, rax	# best,, best, best
.L65:
	add	r12, 1	# i,
	add	rbx, 32	# ivtmp.381,
	cmp	r12, QWORD PTR [rsp+88]	# i, %sfp
	jne	.L73	#,
.L81:
	cmp	QWORD PTR [rsp+136], r14	# d, best
	jb	.L74	#,
	mov	rsi, r14	#, best
	mov	edi, OFFSET FLAT:_ZSt4cout	#,
	call	_ZNSo9_M_insertImEERSoT_	#
.L75:
	mov	edx, 1	#,
	mov	edi, OFFSET FLAT:_ZSt4cout	#,
	mov	BYTE PTR [rsp+111], 10	# __c,
	lea	rsi, [rsp+111]	#,
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l	#
	mov	rsi, QWORD PTR [rsp+464]	#, MEM[(struct _Rb_tree *)&right + 16B]
	lea	rdi, [rsp+448]	#,
	call	_ZNSt8_Rb_treeIN12_GLOBAL__N_14PackES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE8_M_eraseEPSt13_Rb_tree_nodeIS1_E	#
	cmp	QWORD PTR [rsp+72], 0	# %sfp,
	je	.L76	#,
	mov	rdi, QWORD PTR [rsp+72]	#, %sfp
	call	_ZdlPv	#
.L76:
	mov	rax, QWORD PTR [rsp+112]	# z.2, z
	lea	rdx, [rax-1]	# tmp626,
	test	rax, rax	# z.2
	mov	QWORD PTR [rsp+112], rdx	# z, tmp626
	jne	.L77	#,
.L28:
	add	rsp, 504	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	pop	rbx	#
	.cfi_def_cfa_offset 48
	pop	rbp	#
	.cfi_def_cfa_offset 40
	pop	r12	#
	.cfi_def_cfa_offset 32
	pop	r13	#
	.cfi_def_cfa_offset 24
	pop	r14	#
	.cfi_def_cfa_offset 16
	pop	r15	#
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L96:
	.cfi_restore_state
	mov	r10, rsi	# D.65636, tmp599
.L69:
	cmp	rax, r10	# D.65635, D.65636
	jae	.L70	#,
	mov	rcx, QWORD PTR [rcx+24]	# __j$_M_node, MEM[(struct _Rb_tree_node_base *)__j$_M_node_637 + 24B]
	jmp	.L67	#
	.p2align 4,,10
	.p2align 3
.L97:
	mov	r10, r8	# D.65636, tmp601
	jmp	.L69	#
	.p2align 4,,10
	.p2align 3
.L98:
	mov	r10, r9	# D.65636, tmp615
	jmp	.L69	#
	.p2align 4,,10
	.p2align 3
.L148:
	mov	r10, rdi	# D.65636, tmp617
	jmp	.L69	#
.L102:
	mov	r11, r9	# D.65636, tmp615
.L71:
	cmp	r11, rax	# D.65636, D.65621
	jb	.L65	#,
	.p2align 4,,2
	jmp	.L72	#
	.p2align 4,,10
	.p2align 3
.L74:
	mov	edx, 1	#,
	mov	edi, OFFSET FLAT:_ZSt4cout	#,
	mov	BYTE PTR [rsp+110], 45	# __c,
	lea	rsi, [rsp+110]	#,
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l	#
.LEHE2:
	jmp	.L75	#
.L36:
	subsd	xmm0, QWORD PTR .LC1[rip]	# tmp448,
	movabs	rax, -9223372036854775808	# tmp450,
	cvttsd2si	rbp, xmm0	# s, tmp448
	xor	rbp, rax	# s, tmp450
	jmp	.L37	#
.L101:
	mov	r11, r8	# D.65636, tmp601
	cmp	r11, rax	# D.65636, D.65621
	jb	.L65	#,
	jmp	.L72	#
	.p2align 4,,10
	.p2align 3
.L100:
	mov	r11, rsi	# D.65636, tmp599
	cmp	r11, rax	# D.65636, D.65621
	jb	.L65	#,
	.p2align 4,,5
	jmp	.L72	#
	.p2align 4,,10
	.p2align 3
.L30:
	mov	rdx, rax	# tmp438, d
	mov	rcx, rax	# tmp439, d
	shr	rdx	# tmp438
	and	ecx, 1	# tmp439,
	or	rdx, rcx	# tmp438, tmp439
	cvtsi2sd	xmm0, rdx	# tmp435, tmp438
	addsd	xmm0, xmm0	# tmp435, tmp435
	sqrtsd	xmm0, xmm0	# tmp434, tmp435
	ucomisd	xmm0, xmm0	# tmp434, tmp434
	jnp	.L32	#,
.L141:
	test	rax, rax	# d
	js	.L34	#,
	cvtsi2sd	xmm0, rax	# tmp440, d
.L35:
	call	sqrt	#
	jmp	.L32	#
.L34:
	mov	rdx, rax	# tmp443, d
	and	eax, 1	# tmp444,
	shr	rdx	# tmp443
	or	rdx, rax	# tmp443, tmp444
	cvtsi2sd	xmm0, rdx	# tmp440, tmp443
	addsd	xmm0, xmm0	# tmp440, tmp440
	jmp	.L35	#
.L104:
	mov	rsi, QWORD PTR [rsp+464]	#, MEM[(struct _Rb_tree *)&right + 16B]
	lea	rdi, [rsp+448]	#,
	mov	rbx, rax	# tmp630,
	call	_ZNSt8_Rb_treeIN12_GLOBAL__N_14PackES1_St9_IdentityIS1_ESt4lessIS1_ESaIS1_EE8_M_eraseEPSt13_Rb_tree_nodeIS1_E	#
.L79:
	cmp	QWORD PTR [rsp+72], 0	# %sfp,
	je	.L80	#,
	mov	rdi, QWORD PTR [rsp+72]	#, %sfp
	call	_ZdlPv	#
.L80:
	mov	rdi, rbx	#, tmp629
.LEHB3:
	call	_Unwind_Resume	#
.LEHE3:
.L38:
	mov	rcx, QWORD PTR [rsp+24]	#, %sfp
	mov	DWORD PTR [rsp+456], 0	# MEM[(struct _Rb_tree_impl *)&right]._M_header._M_color,
	mov	r14, -1	# best,
	mov	QWORD PTR [rsp+464], 0	# MEM[(struct _Rb_tree_impl *)&right]._M_header._M_parent,
	mov	QWORD PTR [rsp+488], 0	# MEM[(struct _Rb_tree_impl *)&right]._M_node_count,
	mov	QWORD PTR [rsp+72], 0	# %sfp,
	mov	QWORD PTR [rsp+472], rcx	# MEM[(struct _Rb_tree_impl *)&right]._M_header._M_left,
	mov	QWORD PTR [rsp+480], rcx	# MEM[(struct _Rb_tree_impl *)&right]._M_header._M_right,
	jmp	.L81	#
.L103:
	mov	rbx, rax	# tmp629,
	jmp	.L79	#
.L144:
	mov	rdx, r13	# tmp648, tmp460
	mov	r14, -32	# prephitmp.357,
	movabs	rcx, 576460752303423487	#,
	sal	rdx, 6	# tmp648,
	cmp	rax, rcx	# __len,
	cmovbe	r14, rdx	# tmp648,, prephitmp.357
	jmp	.L43	#
	.cfi_endproc
.LFE3743:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA3743:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3743-.LLSDACSB3743
.LLSDACSB3743:
	.uleb128 .LEHB0-.LFB3743
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB3743
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L103-.LFB3743
	.uleb128 0
	.uleb128 .LEHB2-.LFB3743
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L104-.LFB3743
	.uleb128 0
	.uleb128 .LEHB3-.LFB3743
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
.LLSDACSE3743:
	.text
	.size	_ZN12_GLOBAL__N_1L8solutionEv, .-_ZN12_GLOBAL__N_1L8solutionEv
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB3747:
	.cfi_startproc
	sub	rsp, 8	#,
	.cfi_def_cfa_offset 16
	xor	edi, edi	#
	call	_ZNSt8ios_base15sync_with_stdioEb	#
	call	_ZN12_GLOBAL__N_1L8solutionEv	#
	xor	eax, eax	#
	add	rsp, 8	#,
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3747:
	.size	main, .-main
	.p2align 4,,15
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB4120:
	.cfi_startproc
	sub	rsp, 8	#,
	.cfi_def_cfa_offset 16
	mov	edi, OFFSET FLAT:_ZStL8__ioinit	#,
	call	_ZNSt8ios_base4InitC1Ev	#
	mov	edx, OFFSET FLAT:__dso_handle	#,
	mov	esi, OFFSET FLAT:_ZStL8__ioinit	#,
	mov	edi, OFFSET FLAT:_ZNSt8ios_base4InitD1Ev	#,
	add	rsp, 8	#,
	.cfi_def_cfa_offset 8
	jmp	__cxa_atexit	#
	.cfi_endproc
.LFE4120:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.local	_ZN12_GLOBAL__N_1L1pE
	.comm	_ZN12_GLOBAL__N_1L1pE,8,8
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1071644672
	.align 8
.LC1:
	.long	0
	.long	1138753536
	.hidden	__dso_handle
	.ident	"GCC: (Gentoo 4.7.2-r1 p1.5, pie-0.5.5) 4.7.2"
	.section	.note.GNU-stack,"",@progbits

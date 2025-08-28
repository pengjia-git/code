	.arch armv8-a
	.file	"main.c"
// GNU C11 (Ubuntu/Linaro 7.5.0-3ubuntu1~18.04) version 7.5.0 (aarch64-linux-gnu)
//	compiled by GNU C version 7.5.0, GMP version 6.1.2, MPFR version 4.0.1, MPC version 1.1.0, isl version isl-0.19-GMP

// GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
// options passed:  -imultiarch aarch64-linux-gnu main.c -mlittle-endian
// -mabi=lp64 -auxbase-strip main.s -fverbose-asm -fstack-protector-strong
// -Wformat -Wformat-security
// options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
// -fauto-inc-dec -fchkp-check-incomplete-type -fchkp-check-read
// -fchkp-check-write -fchkp-instrument-calls -fchkp-narrow-bounds
// -fchkp-optimize -fchkp-store-bounds -fchkp-use-static-bounds
// -fchkp-use-static-const-bounds -fchkp-use-wrappers -fcommon
// -fdelete-null-pointer-checks -fdwarf2-cfi-asm -fearly-inlining
// -feliminate-unused-debug-types -ffp-int-builtin-inexact -ffunction-cse
// -fgcse-lm -fgnu-runtime -fgnu-unique -fident -finline-atomics
// -fira-hoist-pressure -fira-share-save-slots -fira-share-spill-slots
// -fivopts -fkeep-static-consts -fleading-underscore -flifetime-dse
// -flto-odr-type-merging -fmath-errno -fmerge-debug-strings
// -fomit-frame-pointer -fpeephole -fplt -fprefetch-loop-arrays
// -freg-struct-return -fsched-critical-path-heuristic
// -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
// -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
// -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-fusion
// -fsemantic-interposition -fshow-column -fshrink-wrap-separate
// -fsigned-zeros -fsplit-ivs-in-unroller -fssa-backprop
// -fstack-protector-strong -fstdarg-opt -fstrict-volatile-bitfields
// -fsync-libcalls -ftrapping-math -ftree-cselim -ftree-forwprop
// -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
// -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop
// -ftree-reassoc -ftree-scev-cprop -funit-at-a-time -fverbose-asm
// -fzero-initialized-in-bss -mfix-cortex-a53-835769
// -mfix-cortex-a53-843419 -mglibc -mlittle-endian
// -momit-leaf-frame-pointer -mpc-relative-literal-loads

	.text
	.align	2
	.global	my_atomic_add
	.type	my_atomic_add, %function
my_atomic_add:
	sub	sp, sp, #48	//,,
	str	x0, [sp, 8]	// val, val
	str	x1, [sp]	// p, p
// main.c:8: 	asm volatile(
	ldr	x4, [sp]	// tmp75, p
	ldr	x2, [sp, 8]	// tmp76, val
	ldr	x1, [sp, 32]	// tmp77, tmp
	ldr	w0, [sp, 28]	// tmp78, result
	ldr	x3, [sp]	// tmp79, p
#APP
// 8 "main.c" 1
	1:ldxr x1,[x4]	// tmp, MEM[(long unsigned int *)p_2(D)]
add x1,x1,x2	// tmp, tmp76
stxr w0,x1,[x4]	// result, tmp, MEM[(long unsigned int *)p_2(D)]
cbnz w0,1b	// result

// 0 "" 2
#NO_APP
	str	x1, [sp, 32]	// tmp, tmp
	str	w0, [sp, 28]	// result, result
// main.c:17: 	tmp1=tmp;
	ldr	x0, [sp, 32]	// tmp80, tmp
	str	x0, [sp, 40]	// tmp80, tmp1
// main.c:18: }
	nop
	add	sp, sp, 48	//,,
	ret
	.size	my_atomic_add, .-my_atomic_add
	.section	.rodata
	.align	3
.LC0:
	.string	"%ld\n"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	stp	x29, x30, [sp, -64]!	//,,,
	add	x29, sp, 0	//,,
	str	w0, [x29, 28]	// argc, argc
	str	x1, [x29, 16]	// argv, argv
// main.c:21: {
	adrp	x0, :got:__stack_chk_guard	// tmp77,
	ldr	x0, [x0, #:got_lo12:__stack_chk_guard]	// tmp76, tmp77,
	ldr	x1, [x0]	// tmp87, __stack_chk_guard
	str	x1, [x29, 56]	// tmp87, D.3591
	mov	x1,0	// tmp87
// main.c:22: 	unsigned long a=4;
	mov	x0, 4	// tmp78,
	str	x0, [x29, 48]	// tmp78, a
// main.c:23: 	int b=3;
	mov	w0, 3	// tmp79,
	str	w0, [x29, 44]	// tmp79, b
// main.c:24: 	my_atomic_add(3,&a);
	add	x0, x29, 48	// tmp80,,
	mov	x1, x0	//, tmp80
	mov	x0, 3	//,
	bl	my_atomic_add	//
// main.c:25: 	printf("%ld\n",a);
	ldr	x1, [x29, 48]	// a.0_1, a
	adrp	x0, .LC0	// tmp82,
	add	x0, x0, :lo12:.LC0	// tmp81, tmp82,
	bl	printf	//
// main.c:26: 	return 0;
	mov	w0, 0	// _7,
// main.c:27: }
	adrp	x1, :got:__stack_chk_guard	// tmp85,
	ldr	x1, [x1, #:got_lo12:__stack_chk_guard]	// tmp84, tmp85,
	ldr	x2, [x29, 56]	// tmp88, D.3591
	ldr	x1, [x1]	// tmp86, __stack_chk_guard
	eor	x1, x2, x1	// tmp86, tmp88
	cmp	x1, 0	// tmp86,
	beq	.L4	//,
	bl	__stack_chk_fail	//
.L4:
	ldp	x29, x30, [sp], 64	//,,,
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits

.section .data
.align 3

my_data1:
	.quad 100

my_data2:
	.word 50

print_data:
	.string "data sum: %d\n"

.align 3
.section .text

.global _start 
_start:
	stp x29,x30,[sp,#-48]!
	ldr x3,=my_data1	
	ldr x4,my_data1
	adr x9,my_data1
	ldr x10,[x0]

	ldr x5,=my_data1
	ldr x2,[x5]

	ldr x6,=my_data2
	ldr x3,[x6]

	add x1,x2,x3
	ldr x0,=print_data
	bl printf	
	
	ldp x29,x30,[sp],#48
	ret

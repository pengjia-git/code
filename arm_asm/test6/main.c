#include <stdio.h>

static inline unsigned long array_index_mask_nospec(unsigned long idx,unsigned long sz)
{
	unsigned long mask;
	asm volatile("cmp %1,%2\n"
			"sbc %0,xzr,xzr\n"
			:"=r"(mask)
			:"r" (idx),"r" (sz)
			:"cc");
	printf("mask=%lx\n",mask);
	return mask;
}

int main(int argc,char *argv)
{
	printf("pengjia\n");
	asm("mov x1,#0");
	asm("mov x0,#0");
	printf("argc=%d\n",argc);
	array_index_mask_nospec(5,3);
	return 0;
}

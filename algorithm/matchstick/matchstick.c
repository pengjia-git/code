#include <stdio.h>

int sticks_index[] = { 6,2,	5,	5,	4,	5,	6,	3,	7,	6 };
/*��һ������������������ʹ�û�������*/
int getsticks(int a)
{
	int count = 0;
	 do{
		count += sticks_index[a % 10];
		a /= 10;
	 } while (a);
	return count;
}

/*����a��b��c�������ܹ��Ļ��������Ƿ�����޶��Ļ�������*/
int is_satisfy(int a, int b, int c, int target_num)
{
	int a_sticks, b_sticks, c_sticks;

	a_sticks = getsticks(a);
	if (a_sticks >= target_num)
		return 0;
	b_sticks = getsticks(b);
	if ((a_sticks + b_sticks) >= target_num)
		return 0;

	c_sticks = getsticks(c);

	if ((a_sticks + b_sticks + c_sticks) == target_num)
		return 1;

	return 0;
}


int main()
{
	int i, j;

	for (i = 0; i < 1111; i++) {
		for (j = 0; j < 1111; j++)
			if (is_satisfy(i, j, i + j, 20))
			printf("%d+%d=%d\n", i, j, i + j);
}

	return 0;
}
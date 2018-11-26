/*
 *learn how to use macro
 dispaly a few max code version
 * */
#include <stdio.h>

#define max1(x,y) x>y?x:y
#define max2(x,y) (x)>(y)?(x):(y)
#define max3(x,y) ({\
		typeof(x) _x = x;\
		typeof(y) _y = y;\
		_x > _y ? _x: _y;\
		})

#define max4(x,y) ({\
		typeof(x) _x = x;\
		typeof(y) _y = y;\
		(void)(&_x == &_y);\
		_x > _y ? _x: _y;\
		})


int main()
{
	int i,j;
	float k;
	printf("max1:%d\n",max1(3,4));
	printf("max1:%d\n",max1(4!=4,2!=3));
	printf("%d\n",4!=4>2!=3);
	printf("%d\n",3+max2(3,4));

	i=3;
	j=4;
	printf("%d\n",max2(i++,j++));
	
	i=3;
	j=4;
	printf("%d\n",max3(i++,j++));

	printf("%f\n",max3(i,k));
	printf("%d\n",max4(i,k));

	return 0;
}

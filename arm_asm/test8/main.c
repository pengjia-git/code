#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int generateAString(char *buf,int size)
{
	srand(time(NULL));
	for(int i=0;i<size;i++)	
		buf[i]=rand()%23+'a';
	return 0;
}

//每次读取16字节的数据进行比较
//1.将地址加载到寄存器中
//2.分别读取16个字节到寄存器中
//3.分别按八个字节比较，不同就跳转至结果不相同标签处
//4.len-16，等于0跳至结果相同标签处
//5.跳至步骤2进行下一轮比较
int charCompare(char *srcBuf,char *targetBuf,int len)
{
	int ret=0;
	__asm__ __volatile__(
		"1:ldp x4,x5,[%1],#16\n\t" //ldr from src
		"ldp x6,x7,[%2],#16\n\t" //ldr from target
		"cmp x4,x6\n\t"
		"b.ne diff\n\t"
		"cmp x5,x7\n\t"
		"b.ne diff\n\t"
		"sub %3,%3,#16\n\t"
		"cbz %3,same\n\t"
		"b 1b\n\t"
		"diff:mov %0,#-1\n\t"
		"same:\n\t"
		:"+r" (ret)
		:"r"(srcBuf),"r"(targetBuf),"r"(len)
		:"cc"
	);
	printf("ret=%d\n",ret);
	return ret;
}


#define BUF_SIZE 1024

int main()
{
	char *buf;

	buf=(char*)malloc(BUF_SIZE);
	if(buf==NULL)
		return -1;

	buf[BUF_SIZE-1]=0;
	generateAString(buf,BUF_SIZE-1);
	//printf("%s\n",buf);
	int ret=charCompare(buf,buf+10,32);

	printf("%d\n",ret);
	return 0;
}

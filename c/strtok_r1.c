#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
	char *p;
	char *saveptr=NULL;
	char *str;
	if(argc != 3)
		return 0;
	str=argv[1];		/*  */
	p=strtok_r(str,argv[2],&saveptr);
	while(p){
		printf("%s\n",p);  
		p=strtok_r(NULL,argv[2],&saveptr);
		if(p== NULL)
			break;
	};
	return 0;
}


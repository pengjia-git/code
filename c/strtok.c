#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
	char *p;
	char *str;
	if(argc != 3)
		return 0;
	str=argv[1];		/*  */
	p=strtok(str,argv[2]);
	while(p){
		printf("%s\n",p);  
		p=strtok(NULL,argv[2]);
		if(p== NULL)
			break;
	};
	return 0;
}


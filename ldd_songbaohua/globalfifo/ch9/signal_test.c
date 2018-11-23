#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int num)
{
	printf("sigal num=%d\n",num);
}

int main(void)
{
	int oflags;

	signal(SIGIO,signal_handler);
	fcntl(STDIN_FILENO,F_SETOWN,getpid());
	oflags=fcntl(STDIN_FILENO,F_GETFL);
	fcntl(STDIN_FILENO,F_SETFL,oflags|FASYNC);
	while(1);
	return 0;
}

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void signal_handler(int num)
{
	struct timeval t;
	gettimeofday(&t,NULL);

	printf("sigal num=%d %ld %ld\n",num,t.tv_sec,t.tv_usec);
	exit(0);
}

int main(void)
{
	int oflags;
	printf("pid=%d\n",getpid());
	signal(SIGUSR1,signal_handler);
	while(1);
	return 0;
}

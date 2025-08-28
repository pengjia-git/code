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

	exit(0);
}

int main(int argc,char *argv[])
{
	struct timeval t;
    int pid=atoi(argv[1]);
    printf("will kill pid=%d\n",pid);
    kill(pid,SIGUSR1);
	gettimeofday(&t,NULL);
	printf("%ld %ld\n",t.tv_sec,t.tv_usec);
	return 0;
}

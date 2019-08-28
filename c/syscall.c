#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <signal.h>

int
main(int argc, char *argv[])
{
   pid_t tid;

   printf("SYS_gettid=%d\n",SYS_gettid);
   printf("SYS_getpid=%d\n",SYS_getpid);
   tid = syscall(186);
   printf("tid=%d\n",(int)tid);
   syscall(SYS_tgkill, getpid(), tid, SIGHUP);
}


#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
  int ret;
  cpu_set_t set;
  pid_t pid;

  CPU_ZERO(&set);
  pid=getpid();

  // ret=sched_rr_get_interval(pid,&tp);
  ret=sched_getaffinity(pid,sizeof(set),&set);
  if(ret == 0)
      printf("cpu count=%d\n",CPU_COUNT(&set));
  return 0;
}

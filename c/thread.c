#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void * thread_1(void * p)
{
  while(1){
   usleep(3000);
  };
  printf("exit thread 1\n");
}

void * thread_2(void * p)
{
  while(1){
    usleep(3000);
  };
}

int main(int argc,char *arv[])
{
  pthread_t id;
  pthread_create(&id,NULL,&thread_1,NULL);
  pthread_create(&id,NULL,&thread_2,NULL);
  while(1);
  return 0;
}

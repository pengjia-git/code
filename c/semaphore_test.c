#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>


int main(int argc,char *argv)
{
    key_t key;
    int sem;

    key=ftok("/home/jia/code/c/semaphore_test.c",0x12341234);
    if(key < 0){
        printf("get key fail\n");
        return -1;
    }

    sem=semget(key,1,IPC_CREAT);
    if(sem < 0)
    {
        printf("create sem fail\n");
        return -1;
    }
    printf("sem=%x\n",sem);
    semctl(sem,0,SETVAL,0);
    return 0;
}

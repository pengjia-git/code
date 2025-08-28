#include <iostream>
#include <stdlib.h>


float get_wast_rate(int obj_size,int order)
{
    int slab_size=4096<<order;
    std::cout<<"slab_size="<<slab_size<<std::endl;
    int waste_size=slab_size-slab_size/obj_size*obj_size-obj_size;
    return (float)waste_size/slab_size;
}


int main(int argc, char *argv[])
{
    int obj_size=atoi(argv[1]);
    printf("obj_size=%d\n",obj_size);
    for(int i=0;i<5;i++)
        printf("obj_size=%d,order=%d,waste_rate=%f\n",obj_size,i,get_wast_rate(obj_size,i));
}
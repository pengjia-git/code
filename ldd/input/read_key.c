#include <stdio.h>
#include <linux/input.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define DEV_PATH "/dev/input/event8"   //difference is possible

int main()
{
	int keys_fd;
	char ret[2];
	struct input_event t;
	keys_fd=open(DEV_PATH, O_RDONLY);
	if(keys_fd <= 0)
	{
		printf("open %s fail\n",DEV_PATH);
		return -1;
	}
	while(1)
	{
		if(read(keys_fd, &t, sizeof(t)) == sizeof(t))
		{
			printf("time=%d\n",(int )t.time.tv_sec);
			if(t.type== EV_ABS)
//				if(t.value==0 || t.value==1)
				{
					printf("key %x %d\n", t.code, (t.value) /*? "Pressed" : "Released"*/);

				}
		}
	}
	close(keys_fd);
	return 0;
}


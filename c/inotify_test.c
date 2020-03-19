#include <stdio.h>
#include <unistd.h>
#include <sys/inotify.h>

#define NAME_MAX 64
#define EVENT_MAX_SIZE (sizeof(struct inotify_event) + NAME_MAX + 1)
int main()
{
	int fd,size;
	struct inotify_event *p;
	char  buf[EVENT_MAX_SIZE];

	fd=inotify_init();
	if(fd < 0)
		return -1;
	
	printf("fd=%d\n",fd);
	
	inotify_add_watch(fd,"test.txt",IN_OPEN|IN_MODIFY);
	inotify_add_watch(fd,"temp_dir",IN_CREATE|IN_DELETE);
	
	size=read(fd,buf,EVENT_MAX_SIZE);
	if(size <= 0){
		close(fd);
		return -1;
	}
	p=(struct inotify_event *)buf;
	printf("wd=%d\n",p->wd);
	printf("len=%d\n",p->len);
	if(p->len)
		printf("name=%s\n",p->name);
	if(p->mask & IN_OPEN)
		printf("test.txt has opened\n");

	if(p->mask & IN_MODIFY)
		printf("test.txt has modified\n");

	if(p->mask & IN_CREATE)
		printf("create a file :%s\n",p->name);

	close(fd);
	return 0;
}

#include <stdio.h>

struct file{
  int num;
  struct file *next;
};

struct file *file_p;

int register_file(struct file *fp)
{
  struct file **p;
  for(p=&file_p;*p;p=&((*p)->next));
  *p=fp;
  return 0;
}

int register_file2(struct file *fp)
{
  struct file *p;
  for(p=file_p;p;p=((p)->next));
  p=fp;
  return 0;
}

int main()
{
  struct file *p;
  struct file a={.num=1,.next=NULL};
  struct file b={.num=2,.next=NULL};
  register_file2(&a);
  register_file2(&b);
  p=file_p;
  for(;p;p=p->next)
    printf("%d\n",p->num);
  return 0;
}

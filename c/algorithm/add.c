#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct list{
	struct list *p;
	char 	     c;
};

struct list * create_a_node()
{
	struct list *p;

	p=(struct list *)malloc(sizeof(struct list));

	if(p == NULL)
	    return p;

	p->p=NULL;
	p->c=0;

	return p;
}

int is_list_empty(struct list *node)
{
	if (node->p ==NULL)
	    return 1;

	return 0;
}


struct list * copy_list(struct list *src)
{
	struct list *p,*node,*head;
	int i;

	if(src == NULL)
	    return NULL;

	p=src;
	for(i=0;;i++){
		node = create_a_node();
		if (node == NULL)
		    return NULL; 
		memcpy(node,p,sizeof(struct list));
		if(i == 0)
		    head=node;
		p=p->p;	
		if(p == NULL)
		    break;
	} 

	return head;
}


int list_len(struct list *p)
{
    int len=0;

	while(p){
		len++;
		p=p->p;
	}

   return len;
}

struct list *  add(struct list *a,struct list *b)
{
    struct list * more_len_list,*short_len_list,*return_list,*return_list_head; 
    int a_len,b_len;
    int jinwei_flag=0;

    a_len=list_len(a);
    b_len=list_len(b);

    if(a_len > b_len){
	more_len_list=a;
	short_len_list=b;
    }
    else{
   	more_len_list=b;
	short_len_list=a;
    }
   
    return_list=copy_list(more_len_list);

    if(return_list == NULL)
	return NULL;

    return_list_head=return_list;

    while(1){
   	return_list->c=return_list->c+short_len_list->c+jinwei_flag; 
	jinwei_flag=0;
	if(return_list->c >= 10){
	    return_list->c-=10;
	    jinwei_flag=1;
	}
	short_len_list=short_len_list->p;
	if(short_len_list == NULL)
	    break;
	return_list=return_list->p;
    }

    while(jinwei_flag){
	if(return_list->p == NULL){
		return_list->p=create_a_node();
		if(return_list->p == NULL)
		    return NULL;
	}
	return_list=return_list->p;
   	return_list->c+=1;
	jinwei_flag=0;
	if(return_list->c >= 10){
	    return_list->c-=10;
	    jinwei_flag=1;
	}
    }

    return return_list_head;
}


int test_unit_1()
{
	struct list *a,*b,*p,*pre;
	int i;

	pre=NULL;

	for(i=0;i<7;i++){
		p=create_a_node();
	    	if(i== 0){
			a=p;
		}
		p->c=9;
		if(pre)
			pre->p=p;
		pre=p;
	}

	pre=NULL;

	for(i=0;i<3;i++){
		p=create_a_node();
	    	if(i== 0){
			b=p;
		}
		p->c=i;
		if(pre)
			pre->p=p;
		pre=p;
	}

	p=add(a,b);
	
	while(p){
		printf("c=%d\n",p->c);	
		p=p->p;
	}
	printf("should be%d\n ",9999999+210);
}

/*typedef tu_fun;

tu_fun test_array[]={
	test_unit_1,
};*/
int main()
{
test_unit_1();
	return 0;
}

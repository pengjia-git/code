#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct list{
	struct list 	*next;
	int	 	val;
};

struct list * create_a_node()
{
	struct list 	*p;

	p=(struct list *)malloc(sizeof(struct list));

	if(p == NULL)
	    return p;

	p->next=NULL;
	p->val=0;

	return p;
}

struct list *  add(struct list *l1,struct list *l2)
{
    	struct list 	*l1_p,*l2_p,*p,*return_head,*ret_p,*pre_return_node;
	int 	carry_flag=0;

	if(l1 == NULL || l2 == NULL)
	    return NULL;

	l1_p=l1;
	l2_p=l2;
	pre_return_node=NULL;
	return_head=NULL;
	
	while(l1_p && l2_p){
	    ret_p=create_a_node();
	    if(ret_p == NULL)
		return NULL;

	    if(return_head == NULL)
		return_head=ret_p;

	    ret_p->val=l1_p->val+l2_p->val+carry_flag;
	    if(ret_p->val >= 10){
	   	ret_p->val-=10; 
		carry_flag=1;
	    } else
		carry_flag=0;

	    if(pre_return_node)
		pre_return_node->next=ret_p;

	    pre_return_node=ret_p;

	    l1_p=l1_p->next;
	    l2_p=l2_p->next;

	}

	if(l1_p == NULL)
	    p=l2_p;
	else
	    p=l1_p;

	while(p){
	    ret_p=create_a_node();
	    if(ret_p == NULL)
		return NULL;
	   
	    ret_p->val=p->val+carry_flag;
	    if(ret_p->val >= 10){
	   	ret_p->val-=10; 
		carry_flag=1;
	    } else
		carry_flag=0;

	    pre_return_node->next=ret_p;
	    pre_return_node=ret_p;

	    p=p->next;
	}

	if(carry_flag){
	    ret_p=create_a_node();
	    if(ret_p == NULL)
		return NULL;
	   
	    ret_p->val=carry_flag;
	    pre_return_node->next=ret_p;
	}

	return return_head;
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
		p->val=9;
		if(pre)
			pre->next=p;
		pre=p;
	}

	pre=NULL;

	for(i=0;i<3;i++){
		p=create_a_node();
	    	if(i== 0){
			b=p;
		}
		p->val=i;
		if(pre)
			pre->next=p;
		pre=p;
	}

	p=add(a,b);
	
	while(p){
		printf("c=%d\n",p->val);	
		p=p->next;
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

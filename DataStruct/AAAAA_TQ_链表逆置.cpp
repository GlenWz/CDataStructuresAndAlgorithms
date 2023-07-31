#include <stdio.h>
#include <stdlib.h>
#define len 10
typedef struct d{
	int data;
	struct d *next;
}node;
//完全逆置链表需要加一个尾节点,为什么要加？ 
 
node *build()
{
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
	for(int i=0;i<len;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=i*i;
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}
node *NIZHI(node *head)
{
	node *p,*q,*h,*ret;
	p=ret=head;
	h=p->next;
	for(;h!=NULL;)
	{
		q=h->next;
		h->next=p;
		p=h;
		h=q;
	}
	ret->next->next=NULL;
	ret->next=p;
	return ret;
 } 

void Print(node *head)
{
	node *h=head;
	for(h=h->next;h!=NULL;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}

int main()
{
	node *n=build();
	Print(n);
	node *NiZhi=NIZHI(n);
	Print(NiZhi);	
} 

#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}slink;

slink *build()
{
	slink *p1=(slink *)malloc(sizeof(slink));
	slink *p2=(slink *)malloc(sizeof(slink));
	slink *head;
	head=p1;
	p1->next=p2;p2->next=NULL;
	p2->data=2;p1->data=NULL;
	return head;	
}
slink *PUSH(int x)
{
	slink *head;
	head=build();
	slink *inp=(slink *)malloc(sizeof(slink));
	inp->data=x;
	inp->next=head->next;
	head->next=inp;
	return head;
}


int main()
{
	slink *head,*q,*p;
	head=build();
	for(q=head;q;q=q->next)
	{
		printf("%d\n",q->data);
	}
	slink *push;int x=15;
	push=PUSH(x);
	for(p=push;p;p=p->next)
	{
		printf("%d\n",p->data);
	}
	
	
	
	
	
}













#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dl{
	int data;
	struct dl *p;
	struct dl *n;
}dll;

dll *build()
{
	dll *head,*q,*p;
	int i=1;
	dll *p1=(dll*)malloc(sizeof(dll));
	dll *p2=(dll*)malloc(sizeof(dll));
	dll *p3=(dll*)malloc(sizeof(dll));
	head =p1;p1->n=p2;p2->n=p3;p3->n=NULL;
	p3->p=p2;p2->p=p1;p1->p=NULL;
	for(q=head;q;q=q->n,i++)
	{
		q->data=i;
	}
	return head;
}
dll *Del()
{
	dll *head,*q,*p;
	head=build();
	for(q=head;q;q=q->n)
	{
		if(q->data==2)
		{
			q->p->n=q->n;
			q->n->p=q->p;
			free(q);
			break;
		}
	}
	return head;
}





int main()
{
	dll *head,*q,*p;
	head=build();
	for(q=head;q;q=q->n)
	{
		printf("%d\n",q->data);
	}
	dll *del;
	del=Del();
	for(p=del;p;p=p->n)
	{
		printf("del:%d\n",p->data);
	}	
	while(head!=NULL)
	{
		dll *f;
		f=head;
		head=head->n;
		free(f);
	}
	
	
	return 0;
	
}

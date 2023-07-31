#include <stdio.h>
#include <stdlib.h>

typedef struct DLnode{
	int data;
	struct DLnode *p;
	struct DLnode *n;
}DL;

DL *build()
{
	DL *p1=(DL*)malloc(sizeof(DL));
	DL *p2=(DL*)malloc(sizeof(DL));
	DL *p3=(DL*)malloc(sizeof(DL));
	DL *head;
	DL *last;DL *q;int i=1;
	head->n=p1;
	p1->n=p2;p2->n=p3;p3->n=NULL;
	last->p=p3;
	p3->p=p2;p2->p=p1;p1->p=NULL;
	for(q=head;q;q=q->n,i++)
	{
		q->data=i;
	}
	return head;
}
DL *Del()
{
	DL *q,*p,*head;
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
	DL *head,*q,*p;
	head=build();
	for(q=head;q;q=q->n)
	{
		printf("%d\t",q->data);
	}
	DL *del;
	del=Del();
	for(p=head;p;p=p->n)
	{
		printf("\n%d\t",p->data);
	}
	while(head!=NULL)
	{
		DL *q=head;
		head=head->n;
		free(q);
	}
	return 0;
	
}

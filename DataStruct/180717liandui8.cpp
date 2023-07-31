#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}node;

typedef struct{
	node *front;
	node *rear;
}linkq;

linkq build()
{
	linkq q;
	node *p1=(node *)malloc(sizeof(node));
	node *p2=(node *)malloc(sizeof(node));
	p1=q.front->next;
	p1->next=p2;p2->next=NULL;
	p1->data=888;p2->data=888;
	q.rear->next=p2;
	return q;
}
void day(linkq head)
{
	node *p=head.front->next;
	for(p;p;p=p->next)
	{
		printf("%d\n",p->data);
	}
}


int main()
{
	linkq head;
	head=build();
	day(head);
}

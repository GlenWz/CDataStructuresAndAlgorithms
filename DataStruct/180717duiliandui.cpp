#include <stdio.h>
#include <stdlib.h>
#define len sizeof(Qnode)

typedef struct Qnode{
	int data;
	struct Qnode *next;
}Qnode;

typedef struct Q{
	Qnode *front;
	Qnode *rear;
}linkq;

linkq init()
{
	linkq head;
	head.front=head.rear=(Qnode *)malloc(len);
	head.front->next=NULL;
	return head;
}

linkq ADD()
{
	linkq head;
	head=init();
	Qnode *p1=(Qnode *)malloc(len);
	Qnode *p2=(Qnode *)malloc(len);
	p1->data=888;p2->data=66;
	head.front->next=p1;
	head.rear=p2;
	p1->next=p2;p2->next=NULL;
	return head;
}
void SCHU(linkq head)
{
	Qnode *h;
	for(h=head.front->next;h;h=h->next)
	{
		printf("%d\n",h->data);
	}
	printf("----------------------------end\n");
}

linkq DEL(linkq head)
{
	Qnode *p; int x;
	if(head.front==head.rear)
	{
		printf("the queue is empty!");
	}
	p=head.front->next;
	x=p->data;
	head.front->next=p->next;
	if(head.rear==p)
	{
		head.rear=head.front;
	}
	free(p);
	return head;
}

int main()
{
	linkq q,add,del;
	q=init();
	add=ADD();
	SCHU(add);
	del=DEL(add);
	SCHU(del);
	return 0;	
}

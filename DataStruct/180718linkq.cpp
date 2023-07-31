#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}qnode;

typedef struct {
	qnode *front;
	qnode *rear;
}linkq;

linkq build()
{
	linkq head;
	head.front=head.rear=(qnode *)malloc(sizeof(qnode));
	qnode *p1=(qnode *)malloc(sizeof(qnode));
	qnode *p2=(qnode *)malloc(sizeof(qnode));
	p1->data=888;p2->data=666;
	p1->next=p2;p2->next=NULL;
	head.front->next=p1;
	head.rear=p2;
	return head;
}

linkq shuchu(linkq head)
{
	qnode *p;
	for(p=head.front->next;p;p=p->next)
	{
		printf("%d\n",p->data);
	}
	printf("------------------------end\n");
}
linkq AD(linkq head)
{
	qnode *p3=(qnode *)malloc(sizeof(qnode));
	p3->data=132;
	p3->next=head.rear->next;
	head.rear->next=p3;
	head.rear=p3;
	return head;
}
linkq DELE(linkq head)
{
	qnode *p;
	p=head.front->next;
	head.front->next=p->next;
	if(p->next==head.rear)
	{
		head.front->next=head.rear;
	}
	return head;
}


int main()
{
	linkq head,add,del;
	head=build();
	shuchu(head);
	add=AD(head);
	shuchu(add);
	del=DELE(add);
	shuchu(del);
}

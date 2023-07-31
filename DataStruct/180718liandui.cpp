#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}qnode;

typedef struct x{
	qnode *fornt;
	qnode *rear;
}linkq;

linkq build()
{
	linkq head;
	head.fornt=head.rear=(qnode*)malloc(sizeof(qnode));
	qnode *p1=(qnode *)malloc(sizeof(qnode));
	qnode *p2=(qnode *)malloc(sizeof(qnode));
	head.fornt->next=p1;
	p1->next=p2;p2->next=NULL;
	p1->data=666;p2->data=888;
	head.rear=p2;
	return head;
}
void SCHU(linkq head)
{
	qnode *p;
	for(p=head.fornt->next;p;p=p->next)
	{
		printf("%d\n",p->data);
	}
	printf("------------------------------end\n");
}
linkq ADDD(linkq head)
{
	qnode *p=(qnode *)malloc(sizeof(qnode));
	p->data=555;
	p->next=head.rear->next;
	head.rear->next=p;
	head.rear=p;
	return head;
}
linkq DEL(linkq head)
{
	qnode *p;
	p=head.fornt->next;
	head.fornt->next=p->next;
	if(p->next==head.rear)
	{
		head.fornt=head.rear;
	}
	free(p);
	return head;
}



int main()
{
	linkq head,addd,del;
	head=build();
	SCHU(head);
	addd=ADDD(head);
	SCHU(addd);
	del=DEL(addd);
	SCHU(del);
}

#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}qnode;

typedef struct n{
	qnode *front;
	qnode *rear;
}linkq;


linkq build()
{
	linkq head;
	head.front=head.rear=(qnode *)malloc(sizeof(qnode));
	qnode *p1=(qnode *)malloc(sizeof(qnode));
	qnode *p2=(qnode *)malloc(sizeof(qnode));
	head.front->next=p1;
	p1->next=p2;p1->data=111;p2->data=222;
	p2->next=NULL;
	head.rear=p2;
	return head;
}

void SCHU(linkq head)
{
	qnode *p;
	for(p=head.front->next;p;p=p->next)
	{
		printf("%d\n",p->data);
	}
	printf("-------------------------end\n");
}
linkq indd(linkq head)
{
	qnode *p3=(qnode *)malloc(sizeof(qnode));
	p3->data=520;
	p3->next=head.rear->next;
	head.rear->next=p3;
	head.rear=p3;
	return head;
}
linkq DEL(linkq head)
{
	qnode *p;
	p=head.front->next;
	head.front->next=p->next;
	if(p->next==head.rear)
	{
		head.front=head.rear;
	}
	free(p);
	return head;
}

int main()
{
	linkq head,addd,del;
	head=build();
	SCHU(head);
	addd=indd(head);
	SCHU(addd);
	del=DEL(addd);
	SCHU(del);
	
	
}

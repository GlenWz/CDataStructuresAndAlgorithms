#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

typedef struct d{
	struct node *front;
	struct node *rear;
}qlink;

qlink *build()
{
	qlink *q=(qlink *)malloc(sizeof(qlink));
	q->front=q->rear=NULL;
	return q;
}
qlink *ins(qlink *q,int x)
{
	node *s=(node *)malloc(sizeof(node));
	s->data=x;
	s->next=NULL;
	if(q->front==NULL&&q->rear==NULL)
	{
		q->front=s;
	}else 
	{
		q->rear->next=s;
	}
	q->rear=s;
	return q;
}
qlink *DEL(qlink *h)
{
	node *s;
	if(h->front!=NULL&&h->rear!=NULL)
	{
		s=h->front;
		h->front=s->next;
		free(s);
	}
	return h;
}
void bianli(qlink *h)
{
	node *s=h->front;
	for(;s;s=s->next)
	{
		printf("%d\t",s->data);
	}
	printf("-------------------------end\n");
}



int main()
{
	qlink *q=build();
	int x=888;
	qlink *in=ins(q,x);
	qlink *in1=ins(in,x+111);
	bianli(in1);
	qlink *del=DEL(in1);
	bianli(del);
}

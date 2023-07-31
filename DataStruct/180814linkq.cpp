#include <Stdio.h>
#include <Stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

typedef struct d{
	struct node *front;
	struct node *rear;
}linkq;

linkq *build()
{
	linkq *s=(linkq *)malloc(sizeof(linkq));
	s->front=s->rear=NULL;
	return s;
}
linkq *INS(linkq *h,int x)
{
	node *s=(node *)malloc(sizeof(node));
	s->data=x;
	s->next=NULL;
	if(h->front==NULL&&h->rear==NULL)
	{
		h->front=s;
	}else 
	{
		h->rear->next=s;
	}
	h->rear=s;
	return h;
}

void bianli(linkq *h)
{
	node *s;
	s=h->front;
	for(s;s;s=s->next)
	{
		printf("%d\t",s->data);
	}
	printf("\n-----------------------------\n");
}
linkq *Del(linkq *h)
{
	if(h->front==NULL&&h->rear==NULL)
	{
		printf("error!");
		return 0;
	}else
	{
		node *s=h->front;
		h->front=s->next;
		free(s);
	}
	return h;
}

int main()
{
	linkq *h=build();
	int x=123;
	linkq *in=INS(h,x);
	linkq *ins=INS(h,x+123);
	bianli(ins);
	linkq *del=Del(ins);
	bianli(del);
}

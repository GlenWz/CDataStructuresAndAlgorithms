#include <Stdio.h>
#include<Stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

typedef struct link{
	struct node *front;
	struct node *rear;
}linkq;
bool isempty(linkq *q)
{
	if(q->front==NULL&&q->rear==NULL)
	{
		return 1;
	}else 
	{
		return 0;
	}
}
linkq *build()
{
	linkq *q=(linkq *)malloc(sizeof(linkq));
	q->front=q->rear=NULL;
	return q;
}

void insertq(linkq *q,int x)
{
	node *s=(node *)malloc(sizeof(node));
	s->next=NULL;
	s->data=x;
	if(isempty(q))
	{
		q->front=s;
	}else 
	{
		q->rear->next=s;
	}
	q->rear=s;
}
int del(linkq *q)
{
	int ret;
	node *s;
	s=q->front;
	q->front=s->next;
	ret=s->data;
	free(s);
	return ret;
	
}
void print(linkq *q)
{
	node *s=q->front;
	for(;s;s=s->next)
	{
		printf("%d\t",s->data);
	}
	printf("\n");
}

int main()
{
	linkq *q=build();
	for(int i=0;i<5;i++)
	{
		insertq(q,i*i);
	}
	int de=del(q);
	printf("del=%d\n",de);
	print(q);
	return 0;
}

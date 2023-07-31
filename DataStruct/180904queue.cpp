#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node{
	struct node *next;
	int data;
}node;

typedef struct qnode{
	struct node *front;
	struct node *rear;
}qnode;
bool isempty(qnode *q);

qnode *build()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=NULL;
	return q;
}
void push(qnode *q,int x)
{
	node *s=(node *)malloc(sizeof(node));
	s->data=x;
	s->next=NULL;
	if(isempty(q))
	{
		q->front=s;
	}else 
	{
		q->rear->next=s;
	}
	q->rear=s;
}
bool isempty(qnode *q)
{
	if(q->front==NULL&&q->rear==NULL)
	{
		return 1;
	}else 
	{
		return 0;
	}
}
void print(qnode *q)
{
	node *s=q->front;
	for(;s!=NULL;s=s->next)
	{
		printf("%d->",s->data);
	}
	printf("\n");
}
int pop(qnode *q)
{
	int tmp;
	node *del;
	del=q->front;
	q->front=del->next;
	tmp=del->data;
	free(del);
	return tmp;
}

int main()
{
	qnode *q=build();	
	for(int i=0;i<10;i++)
	{
		push(q,i*i);
	}
	print(q);
	int DEL=pop(q);
	printf("DEL:%d\n",DEL);
	print(q);
}

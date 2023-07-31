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

void insert(linkq *s,int x)
{
	node *n=(node *)malloc(sizeof(node));
	n->data=x;
	n->next=NULL;
	if(isempty(s))
	{
		s->front=n;
	}else 
	{
		s->rear->next=n;
	}
	s->rear=n;
}
int del(linkq *q)
{
	node *tmp;
	int ret;
	tmp=q->front;
	q->front->next=tmp->next;
	q->front=tmp->next;
	ret=tmp->data;
	free(tmp);
	return ret;
}



void print(linkq *s)
{
	node *q=s->front;
	for(q;q;q=q->next)
	{
		printf("%d\t",q->data);
	}
	printf("\n---------------------------------\n");
}

int main()
{
	linkq *q=build();
	for(int i=0;i<5;i++)
	{
		insert(q,i*i);
	}
	print(q);
	int d1=del(q);
	int d2=del(q);
	printf("%d\n",d2);
	print(q);
	return 0;
}

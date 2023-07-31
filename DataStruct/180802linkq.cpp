#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

typedef struct a{
	struct node *front;
	struct node *rear;
}linkq;
bool isempty(linkq *q);
linkq *build()
{
	linkq *q=(linkq *)malloc(sizeof(linkq));
	q->front=q->rear=NULL;
	return q;
}
linkq *insert(int x,linkq *h)
{
	node *s=(node *)malloc(sizeof(node));
	if(s!=NULL)
	{
		s->data=x;
		s->next=NULL;
		if(isempty(h))
		{
			h->front=s;
		}else 
		{
			h->rear->next=s;
		}
		h->rear=s;
	}
	return h;
}
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

linkq *DELETE(linkq *h)
{
	node *s;
	if(isempty(h))
	{
		printf("error!");
		return 0;
	}else 
	{
		s=h->front;
		h->front=s->next;
		free(s);
		return h;
	}
}

void bianli(linkq *h)
{
	node *s;
	for(s=h->front;s;s=s->next)
	{
		printf("%d\t",s->data);
	}
}


int main()
{
	linkq *q=build();
	int x=123;
	linkq *in=insert(x,q);
	bianli(in);	
	printf("\n---------------------------------\n");
	linkq *s=insert(x+123,in);
	bianli(s);
	printf("\n---------------------------------\n");
	linkq *del=DELETE(s);
	bianli(del);
	
}

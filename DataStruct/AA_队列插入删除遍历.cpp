#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

typedef struct n{
	struct node *front;
	struct node *rear;
}linkq;

linkq *buildq()
{
	linkq *head=(linkq *)malloc(sizeof(linkq));
	head->front=head->rear=NULL;
	return head;
}
linkq *Insert(linkq *head)
{
	linkq *ret=head;
	linkq *h=head;
	for(int i=0;i<8;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=i*i;
		s->next=NULL;
		if(h->front==NULL&&h->rear==NULL)
		{
			h->front=s;
		}else 
		{
			h->rear->next=s;
			
		}
		h->rear=s;
	}
	return ret;
}
linkq *Delete(linkq *head)
{
	if(head->front==NULL&&head->rear==NULL)
	{
		printf("error!");
		return 0;
	}else 
	{
		node *s=head->front;
		head->front=s->next;
		free(s);
	}
	return head;
}
void PrintQ(linkq *h)
{
	node *s;
	s=h->front;
	for(;s;s=s->next)
	{
		printf("%d->",s->data);
	}
	printf("\n");
}

int main()
{
	linkq *q1=buildq();	
	linkq *qq1=Insert(q1);
	PrintQ(qq1);
	linkq *qqq=Delete(qq1);
	PrintQ(qqq);
}

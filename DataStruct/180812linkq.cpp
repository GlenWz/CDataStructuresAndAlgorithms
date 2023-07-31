#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

typedef struct {
	struct node *front;
	struct node *rear;
}linkq;
bool isempty(linkq *q);

linkq *initq()
{
	linkq *q=(linkq *)malloc(sizeof(linkq));
	q->front=q->rear=NULL;
	return q;
}
linkq *insert(int x,linkq *p)
{
	linkq *q=p;
	node *s=(node *)malloc(sizeof(node));
	if(s!=NULL)
	{
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
		// q->size ++;
	}
	return q;
}
void bianli(linkq *q)
{
	node *s;
	for(s=q->front;s;s=s->next)
	{
		printf("%d\t",s->data);
	}
}

bool isempty(linkq *q)
{
	if(q->rear==NULL&&q->front==NULL)
	{
		return 1;
	}else 
	{
		return 0;
	}
}
int  DEL(linkq *q)
{
	node *s;
	int p;
	if(isempty(q))
	{
		printf("error");
		return 0;
	}else 
	{
		s=q->front;
		p=s->data;
		q->front=q->front->next;
		free(s);
		
		return p;
	}
}

int main()
{
	int x=111;
	int p;
	linkq *q1=initq();
	linkq *q2=insert(x,q1);
	linkq *q3=insert(x+111,q2);
	bianli(q3);
	printf("\n---------------woshinidie\n");
	p=DEL(q3);
	printf("p=%d\n",p);
	bianli(q3);
	printf("--------------end\n");
}

#include <stdio.h>
#include <Stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

typedef struct d{
	struct node *front;
	struct node *rear;
}qlink;
bool isempty(qlink *h);
qlink *build()
{
	qlink *s=(qlink *)malloc(sizeof(qlink));
	s->front=s->rear=NULL;
	return s;
}
qlink *insert(qlink *h,int x)
{
	node *s=(node *)malloc(sizeof(node));
	s->data=x;
	s->next=NULL;
	if(s!=NULL)
	{
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

bool isempty(qlink *h)
{
	if(h->front==NULL&&h->rear==NULL)
	{
		return 1;
	}else 
	{
		return 0;
	}
}
void output(qlink *h)
{
	node *s=(node *)malloc(sizeof(node));
	s=h->front;
	for(s;s;s=s->next)
	{
		printf("%d\t",s->data);
	}
	printf("\n--------------------------end\n");
}
qlink *DEL(qlink *h)
{
	node *s;
	if(isempty(h))
	{
		printf("the queue is empty");
	}else 
	{
		s=h->front;
		h->front=s->next;
		free(s);
	}
	return h;
}


int main()
{
	qlink *h=build();
	int x=123;
	qlink *in=insert(h,x);
	qlink *in1=insert(in,x+123);
	output(in1);
	qlink *del=DEL(in1);
	output(del);
	
}

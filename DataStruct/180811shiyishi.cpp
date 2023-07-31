#include <Stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *front;
	struct d *rear;
	struct d *next;
}linkq;

typedef struct a{
	int data;
	struct a *next;
}node;

linkq *build(linkq *head,int x)
{
	linkq *p=(linkq *)malloc(sizeof(linkq));
	p->next=NULL;
	p->data=x;
	if(head->rear==NULL)
	{
		head->front=head->rear=p;
	}else 
	{
		head->rear->next=p;
		head=p;
	}
	return head;
}
void initlinkq(linkq *&lqu)
{
	lqu=(linkq *)malloc(sizeof(linkq));
	lqu->front=lqu->rear=NULL;
}
int deq(linkq *lqu,int &x)
{
	linkq *p;
	if(lqu->rear==NULL)
	{
		return 0;
	}else 
	{
		p=lqu->front;
	}
	if(lqu->front==lqu->rear)
	{
		lqu->front=lqu->rear=NULL;
	}else 
	{
		lqu->front=lqu->front->next;
	}
	x=p->data;
	free(p);
	return 1;
}
void print(linkq *lqu)
{
	for(lqu;lqu;lqu=lqu->next)
	{
		printf("D=%d\n",lqu->data);
	}
}

int main()
{
	linkq *lqu;
	initlinkq(lqu);
	int x=555;
	linkq *head=build(lqu,x);
	head=build(lqu,x+10);
	head=build(lqu,x+20);
	deq(lqu,x);
	print(lqu);
}

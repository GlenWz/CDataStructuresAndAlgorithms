#include <Stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}node;

node *build()
{
	node *rear=(node *)malloc(sizeof(rear));
	rear->data=NULL;
	node *ret=rear;
	for(int i=1;i<10;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->next=NULL;
		s->data=i*i;
		rear->next=s;
		rear=s;
	}
	rear->next=ret;
	return rear;
}
node *pop(node *q,int &x)
{
	node *rear=q->next;
	node *ret=q;
	for(;rear->data==NULL;rear=rear->next)
	{
	}
	x=rear->data;
	rear->data=NULL;
	return ret;
}
node *Push(node *s,int y)
{
	node *ret;
	node *q=s;
	if(q->next->data==NULL)
	{
		q->next->data=y;
	}else
	{
		printf("the queue is full!\n");
	}
	return q->next;
}
void Print(node *h)
{
	node *stop=h->next;
	for(h=stop->next;h!=stop;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
	
}

int main()
{
	node *b=build();
	int x=0,y;
	node *s=pop(b,x);
	printf("%d",x);
	pop(s,y);
	printf("%d",y);
	node *p=Push(s,100);
//	node *t=Push(s,100);
	Print(p);

}

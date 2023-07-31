#include <Stdio.h>
#include <Stdlib.h>
#define max 100

typedef struct d{
	int data[max];
	int front;
	int rear;
}queue;

queue *build()
{
	queue *q=(queue *)malloc(sizeof(queue));
	q->front=q->rear=0;
	return q;
}
queue *insert(queue *head)
{
	queue *h=head;
	for(int i=0;i<10;i++)
	{
		h->data[i]=i*i;
		h->front=0;
		h->rear=i+1;
	}
	return head;
}
queue *del(queue *head)
{
	if(head->front==head->rear)
	{
		printf("error!");
		return 0;
	}else 
	{
		head->data[head->front]=NULL;
		head->front++;
		return head;
	}
}
void Printq(queue *head)
{
	for(int i=head->front;i<head->rear;i++)
	{
		printf("%d->",head->data[i]);
	}
	printf("\n");
}

int main()
{
	queue *q=build();
	queue *qq=insert(q);
	Printq(qq);
	queue *qqq=del(qq);
	Printq(qqq);
}

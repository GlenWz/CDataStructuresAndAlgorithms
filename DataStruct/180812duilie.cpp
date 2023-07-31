#include <stdio.h>
#include <stdlib.h>
#define maxsize 10
typedef struct d{
	int data[maxsize];
	int front;
	int rear;
}queue;

queue *initq()
{
	queue *q=(queue *)malloc(sizeof(queue));
	for(int i=0;i<maxsize;i++)
	{
		q->rear=i;
		q->data[i]=i*i;
	}
	q->front=0;
	return q;
}
queue *DEL(queue *q)
{
	printf("\nq->rear%d\n",q->rear);
	if(q->rear==q->front)
	{
		printf("the q is empty1");
		return NULL;
	}else 
	{
		q->data[q->front]=NULL;
		q->front++;
		return q;
	}
}
queue *INSERT(queue *q,int x)
{
	if(q->rear==maxsize-1&&q->front!=0)
	{
		q->data[0]=x;
		q->rear=0;
	}else if((q->rear+1)%q->front!=0)
	{
		q->rear++;
		q->data[q->rear]=x;
		
	}else
	{
		printf("the queue is full");
		return NULL;
	}
	return q;
}
void bianli(queue *q)
{
	if(q->front<q->rear)
	{
		for(int i=q->front;i<q->rear+1;i++)
		{
			printf("q=%d\t",q->data[i]);
		}
	}else 
	{
		for(int i=q->front;i<maxsize-1;i++)
		{
			printf("%d\t",q->data[i]);
		}
		for(int j=0;j<q->rear+1;j++)
		{
			printf("%d\t",q->data[j]);
		}
	}
}

int main()
{
	queue *q=initq();
	bianli(q);
	printf("\n----------------woshinidie\n");
	queue *del=DEL(q);
	bianli(del);
	printf("\n---------------woshi ni die\n");
	int x=888;
	queue *insert=INSERT(del,x);
	bianli(insert);
	printf("\n------------------------xxx\n");
}

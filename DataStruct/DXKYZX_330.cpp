#include <stdio.h>
#include <stdlib.h>
#define maxsize 8

typedef struct d{
	int data[maxsize];
	int length;
	int rear;
}queue;

queue *buildq()
{
	queue *head=(queue *)malloc(sizeof(queue));
	head->rear=0;
	head->length=0;
	for(int i=0;i<maxsize;i++)
	{
		head->data[i]=i*i+1;
		head->rear=i;
		head->length=head->rear+1;
	}
	return head;
}
void PrintQ(queue *head)
{
	printf("the rear is %d \n the length is :%d\n",head->rear,head->length);
	if(head->rear==maxsize-1)
	{
		for(int i=0;i<head->length;i++)
		{
			printf("%d->",head->data[i]);
		}
		printf("\n");
	}else 
	{
		printf("\n");
		int j;
		for(j=head->rear;head->data==NULL;j++)
		{
		}
		for(j;j<=head->rear;j++)
		{
			printf("%d->",head->data[j]);
		}
	}
	
}
int Pushq(queue *q,int x)
{
	if(q->length==maxsize)
	{
		printf("the queue is full!\n");
		return NULL;
	}
	if(q->rear==maxsize-1)
	{
		q->rear=(q->rear+1)%maxsize;
		q->data[q->rear]=x;
		q->length++;
	}else 
	{
		q->data[++q->rear]=x;
		q->length++;
	}
}
int DelQ(queue *q)
{
	int ret;
	int i;
	if(q->length==0)
	{
		printf("the queue is empty!\n");
	}
	if(q->rear==maxsize-1)
	{
		for(i=0;q->data[i]==NULL;i++)
		{
		}
		ret=q->data[i];
		q->data[i]=NULL;
		q->length--;
	}
	return ret;
}



int main()
{
	queue *q=buildq();
	PrintQ(q);
	Pushq(q,100);
	int x=DelQ(q);
	PrintQ(q);
	Pushq(q,88);
}







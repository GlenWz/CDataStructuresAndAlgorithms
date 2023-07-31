#include <stdio.h>
#include <stdlib.h>
#define maxsize 5

typedef struct d{
	int data[maxsize];
	int front;
	int rear;
}queue;

queue *build()
{
	queue *head=(queue *)malloc(sizeof(queue));
	int dat=10;
	for(int i=0;i<maxsize;i++,dat++)
	{
		head->data[i]=dat;
		head->front=0;
		head->rear=i;
	}
	return head;
}

void schu(queue *head)
{
	if(head->rear>head->front)
	{
		for(int i=head->front;i<=head->rear;i++)
		{
			printf("p:%d\n",head->data[i]);
		}
	}
	else
	{
		for(int i=head->rear+1;i<maxsize;i++)
		{
			printf("rear=%d\n",head->data[i]);
		}
		for(int i=0;i<head->rear+1;i++)
		{
			printf("or:%d\n",head->data[i]);
		}
	}
	printf("-------------------------------\n");
}
int Del(queue *head)
{
	int x;
	x=head->data[head->front];
	head->data[head->front]=NULL;
	head->front++;
	return x;
}

int ADD(queue *head,int x)
{
	int ret =0;
	if(head->rear+1%maxsize==head->front)
	{
		printf("the queue is full!");
	}
	else
	{
		head->rear++;
		if(head->rear>=maxsize)
		{
			head->rear=0;
			head->data[head->rear]=x;
			ret=head->data[head->rear];
		}
		else
		{
			head->data[head->rear]=x;
			ret=head->data[head->rear];
		}
	}
	return ret;
}
void test(queue *head)
{
	for(int i=0;i<maxsize;i++)
	{
		printf("TEST:%d\n",head->data[i]);
	}
}
int main()
{
	queue *head;
	head=build();
	schu(head);
	int del;
	del=Del(head);
	schu(head);
	int inp; int x=888;
	inp=ADD(head,x);
	schu(head);
	test(head);
	return 0;
}

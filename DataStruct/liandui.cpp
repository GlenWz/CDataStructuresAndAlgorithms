#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

typedef struct a{
	struct node *front;
	struct node *rear;
}queue;


queue *buildQ()
{
	queue *q=(queue *)malloc(sizeof(queue));
	q->front=q->rear=NULL;
	return q;
}
void Init_queue(queue *q)
{
	q->front=q->rear=NULL;	
}
int isempty(queue *q)
{
	int ret=0;
	if(q->front==NULL)
	{
		ret=1;
	}
	return ret;
}

void push(queue *&q,int x)
{
	node *s=(node *)malloc(sizeof(node));
	s->next=NULL;
	s->data=x;
	if(isempty(q))
	{
		q->front=s;
	}else
	{
		q->rear->next=s;
	}
	q->rear=s;
	
}
int pop(queue *q,int &x)
{
	int ret=0;
	if(!isempty(q))
	{
		node *f=q->front;
		x=q->front->data;
		q->front=f->next;
		free(f);
		ret=1;
	}
	return ret;
}

int main()
{
	queue *q=buildQ();
	int a,b,c,x;
	int i;
	do
	{
		printf("please input the NUM:0~5\n");
		scanf("%d",&i);
		if(i>5||i<0)
		{
			printf("Error!\n");
		}	
		switch(i)
		{
			case 0: break;
			case 1: Init_queue(q);
			        printf("initializaion is successful!\n");
			        break;
			case 2:
					if(isempty(q))
					{
						printf("yes,the queue is empyty!\n");
					}else 
					{
						printf("no! the queue is not empty!\n"); 	
					} 
					break;
			case 3: 
					printf("please input the push elementype!\n");
					scanf("%d",&x);
					push(q,x);
					printf("push successful!\n");
					break;
			case 4: 
					c=pop(q,a);
					if(c)
					{
						printf("successful!\tthe elementype is %d\n",a);
					}else 
					{
						printf("pop fail,the queue is empty!\n");
					}
					break;	
		}
	}while(i!=0);
}

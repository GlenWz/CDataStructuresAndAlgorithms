#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5


typedef struct d{
	int data[MAXSIZE];
	int front,rear;
}queue;

queue *buildQ()
{
	queue *q=(queue *)malloc(sizeof(queue));
	q->front=q->rear=0;
	return q;
}
void Init_Q(queue *q)
{
	q->front=q->rear=0;
}

int isempty(queue *q)
{
	int ret=0;
	if(q->front==q->rear)
	{
		ret=1;
	}
	return ret;
}
int isfull(queue *q)
{
	int ret=0;
	if((q->rear+1)%MAXSIZE==q->front)
	{
		ret=1;
		printf("the queue is full!");
	}
	return ret;
}


int push(queue *q,int x)
{
	int ret=0;
	if(!isfull(q))
	{
		q->data[q->rear]=x;
		q->rear=(++q->rear)%MAXSIZE;
		ret=1;
	}
	return ret;
}
int pop(queue *q,int &x)
{
	int ret=0;
	if(!isempty(q))
	{
		x=q->data[q->front];
		q->front=(++q->front)%MAXSIZE;
		ret=1;
	}
	return ret;
}

queue *Swap(queue *q)
{
	if(isempty(q))
	{
		printf("the queue is empty! Swapping is fail!");	
	}
	int tmp=q->front;
	q->front=q->rear;
	q->rear=tmp;
	return q;
}

int Isempty_P(queue *p)
{
	int ret=0;
	if(p->rear==p->front)
	{
		ret=1;
	}
	return ret;
}
int Isfull_P(queue *p)
{
	int ret=0;
	if(p->front==0&&p->rear==(MAXSIZE-1))
	{
		ret=1;
	}
	if((p->front-1)%MAXSIZE==p->rear)
	{
		ret=1;
	}
	return ret;
}
int Push_P(queue *p,int x)
{
	int ret=0;
	if(!isfull(p))
	{
		p->data[p->front]=x;
		p->front=(--p->front);
		if(p->front<0)
		{
			p->front=MAXSIZE-1;
		}
		ret=1;
	}
	return ret;
}
int POP_P(queue *p,int &x)
{
	int ret=0;
	if(!isempty(p))
	{
		x=p->data[p->rear];
		p->rear=--p->rear;
		if(p->rear<0)
		{
			p->rear=MAXSIZE-1;
		}
		ret=1;
	}
	return ret;
}

int main()
{
	queue *q=buildQ();
	int i;
	int x,a,b,c;
	do
	{
		printf("please input the NUM:1~5\n");
		scanf("%d",&i);
		if(i>5||i<0)
		{
			printf("Error\n");
		}
		switch(i)
		{
			case 0: break;
			case 1: Init_Q(q);
					printf("initialization is successful!\n");
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
					b=push(q,x);
					if(b==1)
					{
						printf("push successful!\n");
					}else 
					{
						printf("push fail!\n");
					}
					break;
			case 4: 
					c=pop(q,a);
					if(c)
					{
						printf("successful!\tthe elementype is %d\n",a);
					}else 
					{
						printf("the queue is empty!popping the elementype is fail\n");
					}
					break;	
		}
		
	}while(i!=0);
	//接下来就是见证奇迹的时刻
	queue *p=q;
	--p->rear;
	--p->front;
	if(p->front<0)
	{
		p->front=MAXSIZE-1;
	}
	if(p->rear<0)
	{
		p->rear=MAXSIZE-1;
	}
	int v,y,n,m; 
	do 
	{
		printf("please input the NUM_VVVVVV:2~4\n");
		scanf("%d",&v);
		if(v>4||v<1)
		{
			printf("error!\n");
		}
		switch(v)
		{
			case 1:break;
			case 2:
					if(Isempty_P(p))
					{
						printf("yes,the queue is empyty!\n");
					}else
					{
						printf("no! the queue is not empty!\n"); 
					}
			case 3:	
					printf("please input the push elementype!\n");
					scanf("%d",&y);	
					Push_P(p,y);
					printf("push successful!\n");
					break;
			case 4:	
					n=POP_P(p,m);
					if(n)
					{
						printf("successful!\tthe elementype is %d\n",m);
					}else 
					{
						printf("pop fail\n");
					}
					break;	
		}
		
	}while(v!=0);
}

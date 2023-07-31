#include <stdio.h>
#include <stdlib.h>

#define maxsize 20

typedef struct{
	
	int data[maxsize];
	int top1;
	int top2;
}qlink;

qlink *build()
{
	qlink *h=(qlink *)malloc(sizeof(qlink));
	int l=5;
	int r=20;
	for(int i=0;i<5;i++,l++)
	{
		h->data[i]=l;
		h->top1=i;
	}
	for(int i=maxsize;i>h->top1;i--,r++)
	{
		h->data[i]=r;
		h->top2=i;
	}
	return h;
}

int pop(qlink *head,int tag)
{
	int ret=0;
	if(tag==1)
	{
		if(head->top1==-1)
		{
			printf("the value is empty!");
		}
		else
		{
			ret=head->data[head->top1];
			head->data[head->top1]=NULL;
			head->top1--;
		}
	}
	else
	{
		if(head->top2==maxsize)
		{
			printf("the link is empty!");
		}
		else
		{
			ret=head->data[head->top2];
			head->data[head->top2]=NULL;
			head->top2++;
		}
	}
	return ret;
}

qlink *push(qlink *h,int tag,int x)
{
	if(h->top2-h->top1==0)
	{
		printf("the link is full!");
	}
	else
	{
		if(tag==1)
		{
			h->top1++;
			h->data[h->top1]=x;
		}
		else
		{
			h->top2--;
			h->data[h->top2]=x;
		}
	}
	return h;
}

void schu(qlink *h)
{
	for(int i=h->top1;i>-1;h--)
	{
		printf("L=%d\n",h->data[i]);
	}
	for(int i=h->top2;i<maxsize-1;h++)
	{
		printf("R=%d\n",h->data[i]);
	}
}

int main()
{
	qlink *head,*PPUSH;
	head=build();
	int tag1=1;int popL;
	popL=pop(head,tag1);
	schu(head);
	int x=888;
	PPUSH=push(head,tag1,x);
	schu(PPUSH);
	
	
}

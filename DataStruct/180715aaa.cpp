#include <stdio.h>
#include <stdlib.h>
#define maxsize 20
typedef struct d{
	int data[maxsize];
	int topL;
	int topR;
}dst;

dst *build()
{
	dst *head=(dst*)malloc(sizeof(dst));
	int l=5,r=20;
	for(int i=0;i<5;i++,l++)
	{
		head->data[i]=l;
		head->topL=i;
	}
	for(int i=maxsize-1;i>head->topL;i--,r--)
	{
		head->data[i]=r;
		head->topR=i;
	}
	return head;
}
int PUSH(dst *p,int tag,int x)
{
	int ret =0;
	if(p->topR-p->topL==1)
	{
		printf("the stack is full");
	}
	else
	{
		if(tag==1)
		{
			p->topL++;
			p->data[p->topL]=x;
			ret=p->data[p->topL];
		}
		else
		{
			p->topR--;
			p->data[p->topR]=x;
			ret=p->data[p->topR];
		}
	}
	return ret;
}
int POP(dst *head,int tag)
{
	int ret=0;
	if(tag==1)
	{
		if(head->topL==-1)
		{
			printf("the stack is empty!");
		}
		else
		{
			head->data[head->topL]=NULL;
			--head->topL;
			ret=head->data[head->topL];
		}
	}
	else
	{
		if(head->topR==maxsize)
		{
			printf("the stack is empty!");
		}
		else
		{
			head->data[head->topR]=NULL;
			head->topR++;
			ret=head->data[head->topR];
		}
	}
	return ret;
}


int main()
{
	dst *head;
	head=build();
	for(int i=head->topL;i>-1;i--)
	{
		printf("Left=%d\n",head->data[i]);
	}
	for(int i=head->topR;i<maxsize;i++)
	{
		printf("right=%d\n",head->data[i]);
	}
	int push,pop; int tag1=1;int tag2=2;
	pop=POP(head,tag1);
	int x=888;
//	push=PUSH(head,tag2,x);
	for(int i=0;i<maxsize-1;i++)
	{
		printf("t=%d\n",head->data[i]);
	}
	
	
}

#include <stdio.h>
#include <stdlib.h>
#define maxsize 20
// duizhan shuangxiang de 
typedef struct d{
	int data[maxsize];
	int topL;
	int topR;
}dst;

dst *build()
{
	dst *head=(dst *)malloc(sizeof(dst));
	int l=5;int r=20;
	for(int i=0;i<5;i++,l--)
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

void shuchu(dst *head)
{
	for(int i=head->topL;i>-1;i--)
	{
		printf("L=%d\n",head->data[i]);
	}
	for(int j=head->topR;j<maxsize;j++)
	{
		printf("R=%d\n",head->data[j]);
	}
	printf("--------------------------\n");
}

int POP(dst *head,int tag)
{
	int ret =0;
	if(tag==1)
	{
		if(head->topL==-1)
		{
			printf("the stack is empty");
		}
		else
		{
			head->data[head->topL]=NULL;
			head->topL--;
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

int PUSH(dst *head,int tag,int x)
{
	int ret=0;
	if(head->topR-head->topL==1)
	{
		printf("the stack is full!");
	}
	else
	{
		if(tag==1)
		{
			head->topL++;
			head->data[head->topL]=x;
			ret=head->data[head->topL];
		}
		else
		{
			head->topR--;
			head->data[head->topR]=x;
			ret =head->data[head->topR];
		}
	}
	return ret;
}

int main()
{
	dst *head;
	head=build();	
	shuchu(head);
	int pop; int tag1=1; int tag2=2;
	pop=POP(head,tag1);
	shuchu(head);
	int push; int x=888;
	push=PUSH(head,tag1,x);
	shuchu(head);
	
	
	
}































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
	dst *head=(dst *)malloc(sizeof(dst));
	int x=5;
	for(int i=0;i<5;i++,x++)   //zuobian  fuzhi 
	{
		head->data[i]=x;
		head->topL=i;
	}
	int y=10;
	for(int i=maxsize-1;i>head->topL;i--,y++)
	{
		head->data[i]=y;
		head->topR=i;
	}
	return head;
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
			head->topL--;
			ret= head->data[head->topL];
		}
		
	}else
	{
		if(head->topR==maxsize-1)
		{
			printf("the stack is empty");
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
int PUSH(dst *p,int tag,int x)
{
	int ret=0;
	if(p->topR-p->topL==1)
	{
		printf("the stack is full!");
	}
	else
	{
		if(tag==1)
		{
			p->data[p->topL+1]=x;
			p->topL++;
			ret=p->data[p->topL];
		}
		else
		{
			p->data[p->topR-1]=x;
			p->topR--;
			ret=p->data[p->topR];
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
	for(int j=head->topR;j<maxsize;j++)
	{
		printf("rigth=%d\n",head->data[j]);
	}
	
	int pop; int tag1=1; int tag2=2;
	pop=POP(head,tag2);
	printf("POP=%d\n",pop);
	int push;int x=999;
	push=PUSH(head,tag2,x);
	printf("PUSH=%d\n",push);
	return 0;
}


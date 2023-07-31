#include <stdio.h>
#include <stdlib.h>
#define maxsize 10
typedef struct d{
	int data[10];
	int top;
}stk;

stk *build()
{
	stk *p=(stk *)malloc(sizeof(stk));
	stk *head=p;
	int d=10;
	for(int i=0;i<maxsize-1;i++,d++)
	{
		head->data[i]=d;
		head->top=i;
	}
	return head;
}

int PUSH(stk *p,int x)
{
	if(p->top==maxsize-1)
	{
		printf("the stack is full!");
		return 0;
	}
	else
	{
		p->data[(p->top+1)]=x;
		p->top++;
		return p->data[p->top];
	}
}
int POP(stk *p)
{
	if(p->top==-1)
	{
		printf("the stack is empty!");
	}
	else
	{
		p->data[p->top]=NULL;
		p->top--;
		return p->data[p->top];
	}
}



int main()
{
	stk *head;
	head=build();
	for(int i=head->top;i>-1;i--)
	{
		printf("%d\n",head->data[i]);
	}
	int push; int x=888;
	push=PUSH(head,x);
	for(int i=head->top;i>-1;i--)
	{
		printf("push=%d\n",head->data[i]);
	}
	int pop;
	pop=POP(head);
	for(int i=head->top;i>-1;i--)
	{
		printf("pop=%d\n",head->data[i]);
	}
	
	return 0;	
}

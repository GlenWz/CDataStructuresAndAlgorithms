#include <stdio.h>
#include <stdlib.h>
#define maxsize 10

typedef struct d{
	int data[maxsize];
	int top;
}stack;
stack *build();
int POP(stack *head);

stack *build()
{
	stack *p=(stack *)malloc(maxsize*sizeof(stack));
	int d=10;
	stack *head=p;
	for(int i=0;i<maxsize;i++,d++)
	{
		head->data[i]=d;
		head->top=i;
	}
	return head;
}

int POP(stack *head)  // chu zhan
{
	int i=0;
	
	if(head->top==-1)
	{
		printf("stack is empty!");
	}
	else
	{
		i=head->top;
		head->top--;
		return head->data[i];
	}
}

int PUSH(stack *head,int x) //Push 888 
{
	if(head->top==maxsize-1)
	{
		printf("the stack is full");
	}else
	{
		int i=head->top;
		head->data[(head->top+1)]=x;
		head->top++;
		return head->data[(head->top)];
	}
}

int main()
{
	stack *head;
	head=build();
	for(int i=head->top;i>-1;i--)
	{
		printf("%d\n",head->data[i]);
	}
	int pop;
	pop=POP(head);
	printf("POP=%d\n",pop);
/*	for(int i=head->top;i>-1;i--)
	{
		printf("top=%d\t",head->data[i]);   //test
	} */
	int push; int x=888;
	push=PUSH(head,x);
	printf("push=%d\n",push);
	for(int i=head->top;i>-1;i--)
	{
		printf("pushText:%d\n",head->data[i]);
	}
	free(head);
	return 0;
	
}

#include <stdio.h>
#include <stdlib.h>
#define maxsize 10
typedef struct d{
	int data[maxsize];
	int top;
}stack;

stack *build()
{
	stack *s=(stack *)malloc(sizeof(stack));
	s->top=-1;
	for(int i=0;i<maxsize;i++)
	{
		s->data[i]=i+i;
		s->top=i;
	}
	return s;
}
int DEL(stack *s)
{
	int ret;
	if(s->top==-1)
	{
		printf("the stack is empty!");
		return NULL;
	}
	ret=s->data[s->top];
	s->data[s->top]==NULL;
	s->top--;
	return ret;
}
stack *insert(stack *s,int x)
{
	if(s->top==maxsize-1)
	{
		printf("the stack is full!");
		return NULL;
	}
	s->top++;
	s->data[s->top]=x;
	return s;
}
void print(stack *s)
{
	for(int i=s->top;i>-1;i--)
	{
		printf("%d\t",s->data[i]);
	}
	printf("\n-----------------------------------\n");
}

int main()
{
	stack *s=build();
	int del=DEL(s);
	int x=888;
	stack *in=insert(s,x);
	print(in);
	return 0;
}

#include <Stdio.h>
#include <Stdlib.h>
#define max 100
typedef struct d{
	int data[max];
	int top;
}stack;

stack *builda()
{
	stack *s=(stack *)malloc(sizeof(stack));
	s->top=-1;
	return s;
}
void push(int x,stack *h)
{
	if(h->top+1==max)
	{
		printf("flowover!");
	}
	h->data[++h->top]=x;
}
int pop(stack *h)
{
	if(h->top==-1)
	{
		printf("error!\n");
		return 0;
	}
	return h->data[h->top--];
}


int Fibonacci(stack *h,int x)
{
	int a1=pop(h);
	int a2=pop(h);
	int sum=a1+a2;
	printf("%d\t",sum);
	push(a1,h);
	push(sum,h);
	if(sum>x)
	{
		return 0;
	}else 
	{
		return Fibonacci(h,x); 
	}
}

int main()
{
	stack *a=builda();	
	push(1,a);
	push(1,a);
	Fibonacci(a,100000);
}

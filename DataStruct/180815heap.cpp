#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef struct d{
	int *ele;
	int size;
	int capacity;
}heap;
bool isfull(heap *s);
heap* build()
{
	heap *p=(heap *)malloc(sizeof(heap));
	if(p==NULL)
	{
		printf("error !");
		return NULL;
	}
	p->ele=(int *)malloc(sizeof(int)*(maxsize+1));
	if(p->ele==NULL)
	{
		printf("out of heap space");
	}
	p->capacity=maxsize;
	p->size=0;
	p->ele[0]=888;
	return p;
}
heap *INS(heap *s,int x)     //hexin  
{
	int i;
	if(isfull(s))
	{
		printf("error!");
		return 0;
	}else 
	{
		i=++s->size;
		for(;s->ele[i/2]<x;i=i/2)
		{
			s->ele[i]=s->ele[i/2];
		}
		s->ele[i]=x;
	}
	return s;
}
bool isfull(heap *s)
{
	if(s->size==s->capacity)
	{
		return 1;
	}else 
	{
		return 0;
	}
}
void shuchu(heap *h)
{
	for(int i=0;i<=h->size;i++)
	{
		printf("%d\t",h->ele[i]);
	}
}

int main()
{
	heap *h=build();
	int x=111;
	heap *in1=INS(h,x+1);	
	heap *in2=INS(in1,x+2);
	heap *in3=INS(in2,x+3);
	heap *in4=INS(in3,x-40);
	heap *in5=INS(in4,x-50);
	heap *in6=INS(in5,50);
	heap *in7=INS(in6,120);
	shuchu(in7);
}

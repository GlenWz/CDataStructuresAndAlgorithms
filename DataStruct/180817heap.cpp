#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef struct d{
	int *ele;
	int size;
	int capacity;
}heap;

bool isfull(heap *h);
bool isempty(heap *h);

heap *inite()
{
	heap *s=(heap *)malloc(sizeof(heap));
	s->ele=(int *)malloc(sizeof(int)*(maxsize+1));
	s->size=0;
	s->ele[0]=-1;
	s->capacity=maxsize;
	return s;
}
void *insert(heap *h,int x)
{
	int i;
	if(isfull(h))
	{
		printf("the xxx is full");
		return 0;
	}
	i=++h->size;
	for(;h->ele[i/2]>x;i/=2)
	{
		h->ele[i]=h->ele[i/2];
	}
	h->ele[i]=x;
}
int delmin(heap *h)
{
	int parent,child;
	int minvalue,last;
	if(isempty(h))
	{
		printf("the xxx is empty");
		return 0;
	}
	minvalue=h->ele[1];
	last=h->ele[h->size--];
	for(parent=1;parent*2<h->size;parent=child)
	{
		child=parent *2;
		if((child<h->size)&&h->ele[child+1]<h->ele[child])
		{
			child++;
		}else if(h->ele[child]<last)
		{
			h->ele[parent]=h->ele[child];
		}else
		{
			break;
		}
		h->ele[parent]=last;
	}
	return minvalue;
}
bool isfull(heap *h)
{
	if(h->size==h->capacity)
	{
		return 1;
	}else 
	{
		return 0;
	}
}
bool isempty(heap *h)
{
	if(h->size==0)
	{
		return 1;
	}else 
	{
		return 0;
	}
}
void bianli(heap *h)
{
	for(int i=1;i<=h->size;i++)
	{
		printf("%d\t",h->ele[i]);
	}
	printf("\n-----------------------------fnegexian\n");
}

int main()
{
	heap *s=inite();
	int x=100;
	insert(s,x);
	for(int i=2;i<10;i++)
	{
		insert(s,i*i);
		printf("%d\t",i*i);
	}
	printf("\n");
	int del=delmin(s);
	bianli(s);	
	
}

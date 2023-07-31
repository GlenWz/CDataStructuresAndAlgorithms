#include <stdio.h>
#include <Stdlib.h>
#define maxsize 100
typedef struct d{
	int *ele;
	int size;
	int capacity;
}heap;
bool isfull(heap *h);
bool isempty(heap *h);
heap *build()
{
	heap* s=(heap *)malloc(sizeof(heap));
	s->ele=(int *)malloc(sizeof(int)*(maxsize+1));
	s->ele[0]=-999;
	s->size=0;
	s->capacity=maxsize;
	return s;
}

void insert(heap *h,int x)
{
	int i;
	if(isfull(h))
	{
		printf("the xxx is full");
	}
	i=++h->size;
	for(;h->ele[i/2]>x;i/=2)
	{
		h->ele[i]=h->ele[i/2];
	}
	h->ele[i]=x;
}

int del(heap *h)
{
	if(isempty(h))
	{
		printf("the xxx is empty!");
		return NULL;
	}
	int parent,child;
	int min,last;
	min=h->ele[1];
	last=h->ele[h->size--];
	for(parent=1;parent*2<h->size;parent=child)
	{
		child=parent*2;
		if((child<h->size)&&h->ele[child+1]<h->ele[child])
		{
			child++;
		}
		if(h->ele[child]>last)
		{
			break;
		}else 
		{
			h->ele[parent]=h->ele[child];
		}	
	}
	return min;
}

void print(heap *h)
{
	for(int i=1;i<=h->size;i++)
	{
		printf("%d\t",h->ele[i]);
	}
	printf("\n \n");
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
int main()
{
	heap *s=build();
	for(int i=0;i<9;i++)
	{
		insert(s,82-i*i);
	}
	print(s);
	int de=del(s);
	print(s);
	printf("the min:%d\n",de);
	return 0;
}

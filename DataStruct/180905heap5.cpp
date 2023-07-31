#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxsize 100
typedef struct d{
	int *ele;
	int capacity;
	int size;
}heap;

bool isfull(heap *h)
{
	if(h->size==maxsize)
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

heap *initiative()
{
	heap *h=(heap *)malloc(sizeof(heap));
	h->ele=(int *)malloc(sizeof(int)*(maxsize+1));
	h->capacity=maxsize;
	h->size=0;
	h->ele[h->size]=-999;
	return h;
}
void insert(heap *h,int x)
{
	int i;
	i=++h->size;
	if(isfull(h))
	{
		printf("the heap is full;");
	}
	for(;h->ele[i/2]>x;i/=2)
	{
		h->ele[i]=h->ele[i/2];
	}
	h->ele[i]=x;
}
int delmin(heap *h)
{
	int min,last;
	int parent,child;
	min=h->ele[1];
	last=h->ele[h->size--];
	for(parent=1;parent*2<h->size;parent=child)
	{
		child=parent*2;
		if((child<h->size)&&h->ele[child+1]<h->ele[child])
		{
			child++;
		}
		if(h->ele[parent]>last)	
		{
			break;
		}else 
		{
			h->ele[parent]=h->ele[child];
		}
	}
	h->ele[parent]=last;
	return min;	
}
void print(heap *h)
{
	for(int i=1;i<h->size;i++)
	{
		printf("%d  ",h->ele[i]);
	}
	printf("\n-----------------------------------------\n");
}

int main()
{
	heap *h=initiative();
	int x=200;
	for(int i=0;i<9;i++)
	{
		insert(h,x-i*i);
	}
	int de=delmin(h);
	printf("DE:%d\n",de);
	print(h);
	
}

#include <stdio.h>
#include <Stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAXSIZE 100

typedef struct heap{
	int *ele;
	int capacity;
	int size;
}heap;

bool isfull(heap *h)
{
	return h->size==MAXSIZE;
}
bool isempty(heap *h)
{
	return h->size==0;
}

heap *buildheap()
{
	heap *h=(heap *)malloc(sizeof(heap));
	h->ele=(int *)malloc(sizeof(int)*(MAXSIZE+1));
	h->size=0;
	h->capacity=MAXSIZE;
	h->ele[h->size]=INT_MIN;
	return h;
}
int enheap(int a,heap *h)
{
	if(isfull(h))
	{
		printf("the heap is full!\n");
		return NULL;
	}
	int i=++h->size;
	for(;h->ele[i/2]>a;i/=2)
	{
		h->ele[i]=h->ele[i/2];         //放在最后一个位置 
	}
	h->ele[i]=a;
}
void print(heap *h,int len)
{
	for(int i=1;i<h->size;i++)
	{
		printf("%d->",h->ele[i]);
	}
}
int DelMin(heap *h)
{
	if(isempty(h))
	{
		printf("\nthe heap is empty!");
		return NULL;
	}
	int last,min;
	int parent,child;
	last=h->ele[h->size--];
	min=h->ele[1];
	for(parent=1;parent*2<=h->size;parent=child)
	{
		child=parent*2;
		if((child<=h->size)&&h->ele[child+1]<h->ele[child])
		{
			child++;
		}else if(h->ele[child]<last)
		{
			h->ele[parent]=h->ele[child];
		}else
		{
			break;
		}
	}
	h->ele[parent]=last;
	return min;
}
void heapsort(int b[],heap *h,int len)
{
	for(int i=0;i<len;i++)
	{
		b[i]=DelMin(h);
	}
}
void printb(int b[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d->",b[i]);
	}
}

int main()
{
	int a[]={5,8,9,7,12,67,2,10,20,34,68,21,36,35};
	int len=sizeof(a)/sizeof(a[0]);
	int b[len];
	heap *h=buildheap();
	for(int i=1;i<len;i++)
	{
		enheap(a[i],h);
	}
	print(h,len);
	heapsort(b,h,len);
	printf("\n");
	printb(b,len);
	
}

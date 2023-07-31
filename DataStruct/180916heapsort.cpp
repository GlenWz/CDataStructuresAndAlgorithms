#include <Stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAXSIZE 100
typedef struct heap{
	int *ele;
	int size;
	int capacity;
}heap;

bool isempty(heap *h)
{
	return h->size==0;
}
bool isfull(heap *h)
{
	return h->size==h->capacity;
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
void insertheap(heap *h,int a)
{
	if(isfull(h))
	{
		printf("the heap is full!");
		system("PAUSE");
	}
	int i=++h->size;
	for(;h->ele[i/2]>a;i/=2)
	{
		h->ele[i]=h->ele[i/2];
	}
	h->ele[i]=a;
}

int delmin(heap *h)
{
	int parent,child;
	int last,min;
	if(isempty(h))
	{
		printf("the heap is empty!");
		return NULL;
	}
	min=h->ele[1];
	last=h->ele[h->size];
	h->size--;
	for(parent=1;parent*2<h->size;parent=child)
	{
		child=parent*2;
		if((child<h->size)&&h->ele[child+1]<h->ele[child])
		{
			child++;
		}
		if(h->ele[parent]<last)
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
void heapsort(heap *h,int b[],int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		b[i]=delmin(h);
	}
}
void printB(int b[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d->",b[i]);
	}
}
void printheap(heap *h)
{
	for(int i=1;i<h->size;i++)
	{
		printf("%d->",h->ele[i]);
	}
	printf("\n");
}

int main()
{
	heap *h=buildheap();
	int a[]={5,9,7,8,6,3,4,12,58,96,45,32,21,20,10,71,19,30};
	int len=sizeof(a)/sizeof(a[0]);
	int b[len];
	for(int i=0;i<len;i++)
	{
		insertheap(h,a[i]);
	}
	printheap(h);
	heapsort(h,b,len);
	
//	printB(b,len);
}

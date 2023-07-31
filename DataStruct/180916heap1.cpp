#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAXSIZE 100
typedef int vertex;
typedef struct edge{
	vertex adjvex;
	struct edge *next;
	int weight;
}edgenode;

typedef struct heap{
	int *ele;
	int capacity;
	int size;
}heap;

heap *buildheap()
{
	heap *h=(heap *)malloc(sizeof(heap));
	h->ele=(int *)malloc(sizeof(int)*(MAXSIZE+1));
	h->capacity=MAXSIZE;
	h->size=0;
	h->ele[h->size]=-9999;
	return h;
}
void inserth(heap *h,int a)
{
	int i=++h->size;
	for(;h->ele[i/2]>a;i/=2)
	{
		h->ele[i]=h->ele[i/2];
	}
	h->ele[i]=a;
}
void printheap(heap *h)
{
	printf("the heap:\n");
	for(int i=1;i<h->size+1;i++)
	{
		printf("%d->",h->ele[i]);
	}
	printf("\n");
}
int delmin(heap *h)
{
	int parent,child;
	int last,min;
	min=h->ele[1];
	last=h->ele[h->size--];
	for(parent=1;parent*2<h->size;parent=child)
	{
		child=parent*2;
		if((child<h->size)&&h->ele[child+1]<h->ele[child])
		{
			child++;
		}
		if(h->ele[parent]>last) // 这个IF的问题！！！！！！！！ 
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
	int tmp;
	for(int i=0;i<len;i++)
	{
		tmp=delmin(h);
		b[i]=tmp;
		
	}
	
}
void print(int b[],int len)
{
	printf("the arry:\n");
	for(int i=0;i<len-1;i++)
	{
		printf("%d->",b[i]);
	}
	printf("\n");
}


int main()
{
	heap *h=buildheap();
	int a[]={9,8,45,6,7,1,2,54,98,67,52,19,28,10,46,37,20};
	int len=sizeof(a)/sizeof(a[0]);
	int b[len]={};
	for(int i=0;i<len;i++)
	{
		inserth(h,a[i]);
	}
	printheap(h);
	heapsort(h,b,len);
	print(b,len);
}

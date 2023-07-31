#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAXSIZE 100
typedef int vertex;


typedef struct heap{
	int *ele;
	int capacity,size;
}heap;

heap *buildheap()
{
	heap *h=(heap *)malloc(sizeof(heap));
	h->ele=(int *)malloc(sizeof(int));
	h->ele[0]=INT_MIN;
	h->size=0;
	h->capacity=MAXSIZE;
	return h;
}

void insertheap(heap *h,int x)
{
	int i=++h->size;
	for(;h->ele[i/2]>x;i/=2)
	{
		h->ele[i]=h->ele[i/2];
	}
	h->ele[i]=x;
}
void print(heap *h)
{
	for(int i=0;i<h->size;i++)
	{
		printf("%d->",h->ele[i]);
	}
}




int main()
{
	heap *h=buildheap();
	int a[]={5,9,7,6,3,98,52,41,32,12,36,20,10,97,84,67,65,21,36};
	int len=sizeof(a)/sizeof(a[0]);
	for(int i=0;i<len;i++)
	{
		insertheap(h,a[i]);
	}
	printf("\n");
	print(h);
	
}

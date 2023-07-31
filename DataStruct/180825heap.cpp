#include <Stdio.h>
#include <Stdlib.h>
#define maxsize 100

typedef struct d{
	int *ele;
	int size;
	int capacity;
}heap;

heap *creat()
{
	heap *h=(heap *)malloc(sizeof(heap));
	h->ele=(int *)malloc(sizeof(int));
	h->ele[0]=-99;
	h->size=0;
	h->capacity=maxsize;
	return h;
}

void insert(heap *h,int x)
{
	int i;
	if(h->size==h->capacity)
	{
		printf("the heap is fulll");
        system("PAUSE");
	}
	i=++h->size;
	for(;h->ele[i/2]>x;i/=2)
	{
		h->ele[i]=h->ele[i/2];
	}
	h->ele[i]=x;
}
void print(heap *h)
{
	for(int i=1;i<=h->size;i++)
	{
		printf("%d\t",h->ele[i]);
	}
	printf("\n---------------------------------------------------\n");
}
int del(heap *h)
{
	int parent,child;
	int last,min;
	if(h->size==0)
	{
		printf("the  heap is empty!");
		return NULL;
	}
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
	h->ele[parent]=last;
	return min;
}







int main()
{
	heap *h=creat();
	int x=3;
	for(int i=0;i<8;i++)
	{
		insert(h,x*i);
	}
	print(h);
	int d=del(h);
	print(h);
}

#include <Stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef struct d{
	int *ele;
	int size;
	int capacity;
}heap;

bool isfull(heap *h);
bool isempty(heap *s);

heap *build()
{
	heap *s=(heap *)malloc(sizeof(heap));
	s->ele=(int *)malloc(sizeof(int)*(maxsize+1));
	s->ele[0]=-1;
	s->size=0;
	s->capacity=maxsize;
	return s;
}

void insert(heap *h,int x)
{
	int i,tmp;
	if(isfull(h))
	{
		printf("the xxx  is full");
		system("PAUSE");
	}
	i=++h->size;
	for(;h->ele[i/2]>x;i/=2)
	{
		h->ele[i]=h->ele[i/2];
	}
	h->ele[i]=x;
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
bool isempty(heap *s)
{
	if(s->size==0)
	{
		return 1;
	}else 
	{
		return 0;
	}
}
int del(heap *h)
{
	int parent,child;
	int last,min;
	if(isempty(h))
	{
		printf("the sss is empty!");
		return 0;
	}
	last=h->ele[h->size--];
	min=h->ele[1];
	for(parent =1;parent*2<h->size;parent=child)
	{
		child=parent *2;
		if((child<=h->size)&&h->ele[child+1]<h->ele[child])
		{
			child++;
		}
		if(h->ele[child]<last)
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
void bianli(heap *h)
{
	for(int i=1;i<=h->size;i++)
	{
		printf("%d\t",h->ele[i]);
	}
	printf("\n-----------------------------------------\n");
}
int main()
{
	heap *h=build();
	int x=123;
	
	for(int i=0;i<10;i++)
	{
		insert(h,x+i*i);
	}
	bianli(h);
	int de=del(h);
	bianli(h);
	printf("\n The min is %d\n",de);
	return 0;
}

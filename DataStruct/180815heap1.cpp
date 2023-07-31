#include <Stdio.h>
#include <stdlib.h>
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
	heap *s=(heap *)malloc(sizeof(heap));
	s->ele=(int *)malloc(sizeof(int)*(maxsize+1));
	s->capacity=maxsize;
	s->ele[0]=888;
	s->size=0;
	return s;
}
void insert(heap *h,int x)
{
	int i;
	if(isfull(h))
	{
		printf("the xxx is full");
		//return 0;
	}else 
	
		i=++h->size;
		for(;h->ele[i/2]<x;i/=2)
		{
			h->ele[i]=h->ele[i/2];
		}
		h->ele[i]=x;
	
}
int delmax(heap *h)
{
	int maxv,tmp;
	int parent,child;
	if(isempty(h))
	{
		printf("the xxx is empty");
		return 0;
	}
	maxv=h->ele[1];
	tmp=h->ele[h->size--];
	for(parent =1;parent*2<h->size;parent=child)
	{
		child=parent*2;
		if((child!=h->size)&&h->ele[child+1]<h->ele[child])
		{
			child++;
		}
		if(tmp<=h->ele[child])
		{
			break;
		}else 
		{
			h->ele[parent]=h->ele[child];
		}
		h->ele[parent]=tmp;
		return maxv;
	}
	
}
bool isfull(heap *h)
{
	if(h->capacity==h->size)
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

void output(heap* s)
{
	for(int i=1;i<=s->size;i++)
	{
		printf("%d\t",s->ele[i]);
	}
	printf("\n-------------------------------------------\n");
}


int main()	




{
	heap *h=build();
	int x=13;
	heap *in;
	for(int i=0;i<9;i++)
	{
		insert(h,(x)+(i*i));
	}
	output(h);
	int del=delmax(h);
	output(h);
	printf("the max=%d\n",del);
//	system("PAUSE");
}

#include <Stdio.h>
#include <Stdlib.h>
#define maxsize 100

typedef struct d{
	int *ele;
	int size;
	int capacity;
}heap;
bool isfull(heap *h);
heap *creat()
{
	heap *p;
	p=(heap *)malloc(sizeof(heap));
	if(p==NULL)
	{
		printf("NO");
		return NULL;
	}
	p->ele=(int *)malloc(sizeof(int)*(maxsize+1));
	if(p->ele==NULL)
	{
		printf("out of heap space");
	}
	p->capacity=maxsize;
	p->size=0;
	p->ele[0]=888;    //shaobing
	return p;
}
heap *Insert(heap *h,int x)
{
	int i;
	if(isfull(h))
	{
		printf("the heap is full");
		return 0;
	}else 
	{
		i=++h->size;
		for(;h->ele[i/2]<x;i/=2)
		{
			h->ele[i]=h->ele[i/2];
		}
		h->ele[i]=x;
	}
	return h;
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

void bianli(heap *h)
{
	for(int i=0;i<=h->size;i++)
	{
		printf("%d\t",h->ele[i]);
	}
	printf("\n-------------------------woshinidie\n");
}


int main()
{
	heap *s=creat();
	int x=111;
	heap *i=Insert(s,x);
	bianli(i);
	heap *in=Insert(i,x+111);
	bianli(in);
	heap *ins=Insert(in,x+222);
	bianli(ins);
}

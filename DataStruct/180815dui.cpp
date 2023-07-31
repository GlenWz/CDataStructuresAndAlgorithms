#include <Stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef struct d{
	int *ele;
	int size;
	int capacity;
}heap;
bool isfull(heap *h);
heap *init()
{
	heap *s=(heap *)malloc(sizeof(heap));
	s->ele=(int *)malloc(sizeof(int));
	s->ele[0]=888;
	s->size=0;
	s->capacity=maxsize;
	return s;
}
int del(heap *h)
{
	int parent,child;
	int maxv,tmp;
	tmp=h->ele[h->size--];
	maxv=h->ele[1];
	for(parent=1;h->ele[parent]<h->size;parent=child)
	{
		child=parent*2;
		if(child!=h->size&&h->ele[child]<h->ele[child+1])
		{
			child++;
		}else if(tmp>=h->ele[child])
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

/*heap *build(int a[],heap *h)
{
	for(int i=0;i<15;i++)
	{
		h->ele[i]=a[i];
		h->size++;
	}                                                 //over
	int parent,child;
	int minv,tmp,tmp1;
	minv=h->ele[h->size];
	for(child=h->size;child>=2;child--)
	{
		parent=child/2;
		if(h->ele[parent]<h->ele[child])
		{
			tmp=h->ele[parent];
			h->ele[parent]=h->ele[child];
			h->ele[child]=tmp;
		}else if(h->ele[parent]<h->ele[child+1])
		{
			tmp=h->ele[parent];
			h->ele[parent]=h->ele[child-1];
			h->ele[child-1]=tmp;
		}
	}
	return h;
}*/

heap *insert(heap *in,int x)
{
	int i;
	if(isfull(in))
	{
		printf("the xx is full");
		return 0;
	}
	i=++in->size;
	for(;in->ele[i/2]<x;i/=2)
	{
		in->ele[i]=in->ele[i/2];
	}
	in->ele[i]=x;
	return in;
}

void bianli (heap *h)
{
	for(int i=0;i<h->size+1;i++)
	{
		printf("%d\t",h->ele[i]);
	}
	printf("\n---------------------------------------\n");
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


int main()
{
	int a[15]={50,88,12,64,52,35,89,16,76,75,13,37,45,79,99};
	heap *i=init();
//	heap *s=build(a,i);
	int x=55;
	heap *in=insert(i,x);
	heap *in1=insert(in,x+50);
	int d=del(in1);
	bianli(in1);
	
	
}

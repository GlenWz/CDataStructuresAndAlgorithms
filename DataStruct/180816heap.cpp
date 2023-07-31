#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef struct d{
	int  *ele;
	int size;
	int capacity;
}heap;
bool isfull(heap *h);
bool isempty(heap *h);
heap *initiative()
{
	heap *h=(heap *)malloc(sizeof(heap));
	h->ele=(int *)malloc(sizeof(int)*(maxsize+1));
	h->ele[0]=888;
	h->size=0;
	h->capacity=maxsize;
	return h;
}

heap *build(heap *h)
{
	int a[8]={0,15,53,89,12,31,39,70};
	int parent,child;
	int tmp,max;
	for(int i=1;i<8;i++)
	{
		h->ele[i]=a[i];
		h->size=i;
	}
	for(child=9;child>=2;child--)
	{
		parent=child/2;
		if((child-1)/2==parent&&h->ele[child-1]<h->ele[child]&&h->ele[parent]<h->ele[child])
		{
			if(h->ele[child-1]>h->ele[parent])
			{
				tmp=h->ele[parent];
				h->ele[parent]=h->ele[child];
				h->ele[child]=tmp;
			}else 
			{
				max=h->ele[child];
				tmp=h->ele[parent];
				h->ele[parent]=max;
				h->ele[child]=h->ele[child-1];
				h->ele[child-1]=tmp;
			}                      //   max                           min
		}else if((child/2)==parent&&h->ele[child-1]>h->ele[child]&&h->ele[parent]<h->ele[child-1])
		{
			if(h->ele[parent]<h->ele[child])
			{
				max=h->ele[child-1];
				tmp=h->ele[parent];
				h->ele[child-1]=h->ele[child];
				h->ele[child]=tmp;
				h->ele[parent]=max;
			}
		}
		else if((child-1)/2!=parent&&h->ele[child]>h->ele[parent])
		{
			tmp=h->ele[parent];
			h->ele[parent]=h->ele[child];
			h->ele[child]=tmp;
		}
	}
	return h;
}



heap *insert(heap *h,int x)
{
	int i;
	if(isfull(h))
	{
		printf("the xxx is full;");
		return 0;
	}
	i=++h->size;
	for(;h->ele[i/2]<x;i/=2)
	{
		h->ele[i]=h->ele[i/2];
	}
	h->ele[i]=x;
	return h;		
}

int DEL(heap *h)
{
	int parent,child;
	int maxv,tmp;
	tmp=h->ele[h->size--];
	maxv=h->ele[0];
	if(isempty(h))
	{
		printf("xxxx is empty!");
		return 0;
	}
	for(parent=1;parent<=h->size;parent=child)
	{
		child=parent*2;
		if((child<h->size)&&h->ele[child]<h->ele[child+1])
		{
			child++;
		}else if(h->ele[child]<tmp)
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
void bianli(heap *s)
{
	for(int i=1;i<=s->size;i++)
	{
		printf("%d\t",s->ele[i]);
	}
	printf("\n------------------------------------\n");
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



int main()
{
	heap *in=initiative();
	heap *s=build(in);
	bianli(s);
	int x=55;
	heap *ins=insert(s,x);
	heap *ins1=insert(ins,59);
	bianli(ins1);
	int del=DEL(ins);
	
}

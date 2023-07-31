#include <Stdio.h>
#include <Stdlib.h>
#include <stdbool.h>
#define maxsize 100
typedef struct d{
	int *ele;
	int capacity;
	int size;
}heap;

typedef struct treenode{
	int weight;
	int left;
	int right;
	int parent;
}huffman;
int demin(heap *h);
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
bool isfull(heap *h)
{
	if(h->size==maxsize)
	{
		return 1;
	}else
	{
		return 0;
	}
}
heap *build()
{
	heap *h=(heap *)malloc(sizeof(heap));
	h->ele=(int *)malloc(sizeof(int)*(maxsize+1));
	h->ele[0]=-999;
	h->size=0;
	h->capacity=maxsize;
	return h;
}
void insert(heap *h,int x)
{
	int i;
	if(isfull(h))
	{
		printf("the xxx if full;");
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
	for(int i=1;i<h->size;i++)
	{
		printf("%d  ",h->ele[i]);
	}
	printf("\n----------------------------------------\n");
}
int demin(heap *h)
{
	if(isempty(h))
	{
		printf("the heap is empty!");
		return NULL;
	}
	int last,min;
	int child,parent;
	last=h->ele[h->size--];
	min=h->ele[1];
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
huffman *huffmanbuild(heap *h1)
{
	int i;
	huffman *t;
	heap *h;
	for(i=1;i<h->size;i++)
	{
		t=(huffman *)malloc(sizeof(huffman));
		t->left=demin(h);
		t->right=demin(h);
		t->weight=t->left+t->right;
		insert(h,t->weight);
	}
	t->weight=demin(h);
	return t;
}

int main()
{
	heap *h=build();
	int x=20;
	for(int i=0;i<6;i++)
	{
		insert(h,x-(i+i));
	}
	print(h);
	int DE=demin(h);
	printf("the del:%d\n",DE);
	print(h);
	huffman *huff=huffmanbuild(h);
	print(h);
}

#include <stdio.h>
#include <Stdlib.h>
#define maxsize 100

typedef struct t{
	int weight;
	struct t *left,*right;
}huffman;

typedef struct {
	huffman *data[maxsize];
	int size,capacity;	
}huffheap;

huffheap *CreatH()
{
	huffheap *h=(huffheap *)malloc(sizeof(huffheap));
	h->capacity=maxsize;
	h->size=0;
	h->data[h->size]->weight=-999999;
	return h;

}
void PrintH(huffheap *h)
{
	int i;
	for(i=1;i<=h->size;i++)
	{
		printf("%d->",h->data[i]->weight);
	}
	printf("\n");
}

int Pdown(int i,huffheap *h)
{
	int parent,child;
	int tmp;
	tmp=h->data[i]->weight;
	for(parent=i;parent<=h->size;parent=child)
	{
		child=parent*2;
		if((h->data[child]->weight>h->data[child+1]->weight)&&child<h->size)
		{
			child++;
		}
		if(tmp<=h->data[child]->weight)
		{
			h->data[parent]->weight=h->data[child]->weight;
		}
	}
	h->data[parent]->weight=tmp;
}

huffheap *BuildHeap(huffheap *h)
{
	int i;
	for(i=h->size/2;i>0;i--)
	{
		Pdown(i,h);
	}
}

int main()
{
	int a[]={1,3,6,5,7,8,12,23,9,11,18,};
	int len=sizeof(a)/sizeof(a[0]);
	huffheap *h=CreatH();
	for(int i=0;i<len;i++)
	{
		++h->size;
		h->data[h->size]->weight=a[i];
	}
	PrintH(h);
	huffheap *h1=BuildHeap(h);
}


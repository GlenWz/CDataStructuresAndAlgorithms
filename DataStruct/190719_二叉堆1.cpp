#include <Stdio.h>
#include <Stdlib.h>
#define maxsize 100
typedef struct d{
	int data[maxsize];
	int size;
	int capacity;
}heap;

heap *buildheap()
{
	heap *h=(heap *)malloc(sizeof(heap));
	h->size=0;
	h->data[h->size]=9999;
	h->capacity=maxsize;
	return h;
}

int isfull(heap *h)
{
	return h->size==maxsize?1:0;
}

int isempty(heap *h)
{
	return h->size==0?1:0;
}



int insert(heap *h,int a)
{
	int i;
	if(isfull(h))
	{
		printf("the heap is full!\n");
		return NULL;
	}
	i=++h->size;
	for(;h->data[i/2]<a;i/=2)
	{
		h->data[i]=h->data[i/2];
	}
	h->data[i]=a;
}
void Print(heap *h)
{
	for(int i=0;i<h->size;i++)
	{
		printf("%d->",h->data[i]);
	}
	printf("\n");
}
int DeleteH(heap *h)
{
	int parent,child;
	int max,temp;
	if(isempty(h))
	{
		printf("the heap is empty!\n");
		return NULL;
	}
	max=h->data[1];
	temp=h->data[h->size--];
	for(parent=1;parent*2<=h->size;parent=child)
	{
		child=parent*2;
		if(child!=h->size&&h->data[child]<h->data[child+1])
		{
			child++;
		}
		if(temp>=h->data[child])
		{
			break;
		}else 
		{
			h->data[parent]=h->data[child];
		}
	}
	h->data[parent]=temp;
	return max;
}




int main()
{
	heap *h=buildheap();
	int a[]={5,6,8,99,63,32,10,45,23,26,89,36,20,10,};
	int len=sizeof(a)/sizeof(a[0]);
	for(int i=0;i<len;i++)
	{
		insert(h,a[i]);
	}
	Print(h);
	int num=DeleteH(h);
	printf("the max is %d\n",num);
	Print(h);
}










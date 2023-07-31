#include <Stdio.h>
#include <stdlib.h>
#define maxsize 100
typedef struct d{
	int data[maxsize];
	int size;
	int capacity;
}heap;

heap *buildh()
{
	heap *h=(heap *)malloc(sizeof(heap));
	h->capacity=maxsize;
	h->size=0;
	h->data[h->size]=9999;
	return h;
}
int PreDown(int i,heap *h)
{
	int parent,child,tmp;
	tmp=h->data[i];
	for(parent=i;parent*2<=h->size;parent=child)
	{
		child=parent*2;
		if((child!=h->size)&&(h->data[child]<h->data[child+1]))
		{
			child++;		
		}
		if(tmp>=h->data[child])
		{
			break;
		}else 
		{
			h->data[parent]=h->data[child];
		}
	}	
	h->data[parent]=tmp;
}

heap *Creat(heap *h)
{
	int i;
	for(i=h->size/2;i>0;i--)
	{
		PreDown(i,h);
	}
}
void Print(heap *h)
{
	for(int i=1;i<=h->size;i++)
	{
		printf("%d->",h->data[i]);
	}
	printf("\n");
}
int main()
{
	int a[]={1,8,9,63,233,566,45,66,33,775,12};
//	int a[]={1,2,3,4,5,};
	int len=sizeof(a)/sizeof(a[0]);
	heap *h=buildh();
	for(int i=0;i<len;i++)
	{
		++h->size;
		h->data[h->size]=a[i];
	}
	Print(h);
	heap *h1=Creat(h);
	Print(h1);
	
}

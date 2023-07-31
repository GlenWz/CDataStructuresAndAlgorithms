#include <stdio.h>
#include <stdlib.h>

void PercDown(int a[],int i,int len)
{
	int parent,child;
	int tmpa=a[i];
	for(parent=i;(parent*2+1)<len;parent=child)
	{
		child=parent*2+1;
		if((a[child+1]>a[child])&&(child!=len-1))
		{
			child++;
		}
		if(tmpa>=a[child])
		{
			break;
		}else 
		{
			a[parent]=a[child];
		}
	}
	a[parent]=tmpa;
}
void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
 } 

void Heap_sort(int a[],int len)
{
	int i;
	for(i=len/2-1;i>=0;i--)
	{
		PercDown(a,i,len);
	}
	for(i=len-1;i>0;i--)
	{
		swap(&a[0],&a[i]);
		PercDown(a,0,i);
	}
}

void Print(int a[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d->",a[i]);
	}
	printf("\n");
}

int main()
{
	int a[]={45,1,12,332,456,78,2,12,54,6,9,789,12,321,465,9,1};
	int len=sizeof(a)/sizeof(a[0]);
	Heap_sort(a,len);
	Print(a,len);
}

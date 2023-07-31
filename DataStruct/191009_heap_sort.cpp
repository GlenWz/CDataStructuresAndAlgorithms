#include <Stdio.h>
#include <Stdlib.h>

void Swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

void percdown(int a[],int i,int N)
{
	int parent,child;
	int tmpa=a[i];
	for(parent=i;(parent*2+1)<N;parent=child)
	{
		child=parent*2+1;
		if(a[child+1]>a[child]&&child!=N-1)
		{
			child++;
		}
		if(a[child]<tmpa)
		{
			break;
		}else 
		{
			a[parent]=a[child];
		}
	}
	a[parent]=tmpa;
}


void Heap_Sort(int a[],int N)
{
	int i,j;
	for(i=N/2-1;i>=0;i--)
	{
		percdown(a,i,N);
	}
	for(j=N-1;j>=0;j--)
	{
		Swap(&a[j],&a[0]);
		percdown(a,0,j);
	}
}
void Print(int a[],int N)
{
	for(int i=0;i<N;i++)
	{
		printf("%d->",a[i]);
	}
}
int main()
{
	int a[]={9,8,7,6,5,4,3,2,1,0};
	int N=sizeof(a)/sizeof(a[0]);
	Heap_Sort(a,N);
	Print(a,N);
}

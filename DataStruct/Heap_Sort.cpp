#include <Stdio.h>
#include <Stdlib.h>

void Percdown(int a[],int i,int N)
{
	int parent,child;
	int tmp=a[i];
	for(parent=i;parent*2+1<N;parent=child)
	{
		child=parent*2+1;
		if(a[child+1]>=a[child]&&child+1<N)
		{
			child++;
		}
		if(a[child]<=tmp)
		{
			break;
		}else 
		{
			a[parent]=a[child];
		}
	}
	a[parent]=tmp;
}
void Swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

void Heap_Sort(int a[],int N)
{
	int i,j;
	for(i=N/2-1;i>=0;i--)
	{
		Percdown(a,i,N);
	}
	for(j=N-1;j>=0;j--)
	{
		Swap(&a[j],&a[0]);
		Percdown(a,0,j);
	}
}
void Print(int a[],int N)
{
	for(int i=0;i<N;i++)
	{
		printf("%d->",a[i]);
	}
	printf("\n");
}

int main()
{
	int a[]={123,45,65,32,20,159,357,2,3,6,9,7,4};
	int N=sizeof(a)/sizeof(a[0]);
	Heap_Sort(a,N);	
	Print(a,N);
}

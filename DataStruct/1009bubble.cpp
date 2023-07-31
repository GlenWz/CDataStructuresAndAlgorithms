#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

void Bubble(int a[],int N)
{
	int i,j,flag=0;
	for(int i=0;i<N;i++)
	{
		for(j=N-1;j>i;j--)
		{
			if(a[j]<a[j-1])
			{
				swap(&a[j],&a[j-1]);
			}
		}
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
	int a[]={45,12,332,456,78,2,12,54,6,9,789,12,321,465,9};
	int N=sizeof(a)/sizeof(a[0]);
	Bubble(a,N);
	Print(a,N);
}

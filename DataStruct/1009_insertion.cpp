#include <Stdio.h>
#include <stdlib.h>

void Insertion(int a[],int N)
{
	int i,j,tmp;
	for(i=1;i<N;i++)
	{
		tmp=a[i];
		for(j=i;j>=0&&a[j-1]>tmp;j--)
		{
			a[j]=a[j-1];
		}
		a[j]=tmp;
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
	int a[]={2,8,9,7,12,3,5,6,8,9,3,555,666,78,45};
	int N=sizeof(a)/sizeof(a[0]);
	Insertion(a,N);
	Print(a,N);
}

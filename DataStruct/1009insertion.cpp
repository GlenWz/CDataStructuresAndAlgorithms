#include <stdio.h>
#include <stdlib.h>

void Insertion(int a[],int N)
{
	int i,j,tmp;
	for(int i=1;i<N;i++)
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
	printf("\n");
}




int main()
{
	int a[]={45,1,12,332,456,78,2,12,54,6,9,789,12,321,465,9,1};
	int N=sizeof(a)/sizeof(a[0]);
	Insertion(a,N);
	Print(a,N);
}

#include <stdio.h>
#include <stdlib.h>

void shell(int a[],int N)
{
	int num=6,i,j,tmp;
	for(num;num>0;num/=2)
	{
		for(i=num;i<N;i++)
		{
			tmp=a[i];
			for(j=i;j>=num&&a[j-num]>tmp;j-=num)
			{
				a[j]=a[j-num];
			}
			a[j]=tmp;
		}
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
	int a[]={45,1,12,332,456,78,2,12,54,6,9,789,12,321,465,9,1};
	int N=sizeof(a)/sizeof(a[0]);
	shell(a,N);
	Print(a,N);
}

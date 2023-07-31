#include <stdio.h>
//maopao

void swap(int *p,int *q)
{
	int j=*p;
	*p=*q;
	*q=j;
}

int main()
{
	int a[]={5,3,2,5,4,9,7,1,};
	int n=sizeof(a)/sizeof(a[0]);
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>i;j--)
		{
			if(a[j-1]>a[j])
			{
				swap(&a[j],&a[j-1]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}

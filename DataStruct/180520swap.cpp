#include <stdio.h>

void swap(int *px,int *py)
{
	int j=*px;
	*px=*py;
	*py=j;
}

int main()
{
	int a[]={3,5,2,6,5,6,4,7,9,6,2,3,66,1,5};
	int i,j,n;
	n=sizeof(a)/sizeof(a[0]);
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

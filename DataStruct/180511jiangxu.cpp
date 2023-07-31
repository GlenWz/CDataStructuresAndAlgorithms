#include <stdio.h>

void swap(int *px,int *py)
{
	int j=*px;
	*px=*py;
	*py=j;
}

int main()
{
	int i,j,n;
	int a[]={8,2,4,6,7,6,1,9,7,5,3,4,2,5,};
	n=sizeof(a)/sizeof(a[0]);
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>i;j--)
		{
			if(a[j-1]<a[j])
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

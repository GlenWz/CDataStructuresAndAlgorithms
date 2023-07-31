#include <stdio.h>

void swap(int *px,int *py)
{
	int j=*px;
	*px=*py;
	*py=j;
}

void dsort(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(a[j-1]>a[j])
			{
				swap(&a[j-1],&a[j]);
			}
		}
	
	}
}

int main()
{
	int a[]={8,5,6,7,9,2,4,6,3,};
	int n=sizeof(a)/sizeof(a[0]);
    dsort(a,n);
    printf("n=%d\n",n);
    for(int i=0;i<n;i++)
    {
    	printf("%d\t",a[i]);
	}
	return 0;
}

#include <Stdio.h>

void swap(int *px,int *py)
{
	int j=*px;
	*px=*py;
	*py=j;
}

int main()
{
	int a[]={2,5,6,7,7,6,3,55,9,46,12,6,45,33,6,1,};
	int i,n;
	n=sizeof(a)/sizeof(a[0]);
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
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}

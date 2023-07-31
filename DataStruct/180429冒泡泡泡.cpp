#include <stdio.h>
#define nub 5

void swap(int *px,int *py)
{
	int j=*px;
	*px=*py;
	*py=j;
}
void sort(int a[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>i;j--)
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
	int a[nub];
	int i,n;
	for(i=0;i<nub;i++)
	{
		printf("ÇëÊäÈë£º");
		scanf("%d",&a[i]);
	}
	n=sizeof(a)/sizeof(a[0]);
	sort(a,n);
	for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}

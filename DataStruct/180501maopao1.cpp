#include <stdio.h>
//maopao
void swap(int *px,int *py)
{
	int j=*px;
	*px=*py;
	*py=j;
}

void bsort(int a[],int n)
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
	int i,n;
	int a[]={5,2,3,1,2,6,8,};
	n=sizeof(a)/sizeof(a[0]);
	bsort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}

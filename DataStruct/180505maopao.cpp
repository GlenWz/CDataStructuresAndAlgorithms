#include <stdio.h>

void swap(int *px,int *py)
{
	int j=*px;
	*px=*py;
	*py=j;
	
}
void dsort(int a[],int n)
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
	int a[]={3,1,2,5,6,7,9,};
	int n=sizeof(a)/sizeof(a[0]);
	dsort(a,n); 
	for(int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}

#include <stdio.h>

void maxmin(int a[],int l,int *max,int *min);
int main()
{
	int max,min,l;
	int a[]={10,5,2,9,5,7,5,68,6,5,45,6,123,};
	l=sizeof(a)/sizeof(a[0]);
	maxmin(a,l,&max,&min);
	printf("max=%d min=%d",max,min);
	return 0;
}

void maxmin(int a[],int l,int *max,int *min)
{
	int i;
	*max=*min=a[0];
	for(i=0;i<l;i++)
	{
		if(a[i]>*max)
		{
			*max=a[i];
		}
		if(a[i]<*min)
		{
			*min=a[i];
		}
	}
}

#include <stdio.h>

void maxmin(int a[],int *max,int len,int *min);
int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10,11,12,15,18,19,};
	int max;
	int min;
	int len;
	len=sizeof(a)/sizeof(a[0]);
	maxmin(a,&max,len,&min);
	printf("max=%d min=%d",max,min);
	return 0;
}
void maxmin(int a[],int *max,int len,int *min)
{
	int i=1;
	*max=*min=a[0]; //zhe yibu zhende niu !
	for(i=0;i<len;i++)
	{
		if(a[i]<*min)
		{
			*min=a[i];
		}
		if(a[i]>*max)
		{
			*max=a[i];
		}
	}
}

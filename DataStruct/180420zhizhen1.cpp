#include <stdio.h>

void maxmin(int *max,int *min,int len,int a[]);
int main()
{
	int a[]={1,2,5,4,6,5646,5,58,5656,3,664,878,454,45646,};
	int max,min,len;
	printf("main sizeof (a)=%lu\n",sizeof(a));
	printf("main a=%p\n",a);
	len=sizeof(a)/sizeof(a[0]);
	maxmin(&max,&min,len,a);
	printf("max=%d min=%d  \n",max,min);
	int *p=&min;
	printf("*p=%d",*p);
	printf("p[0]=%d\n",p[0]);
	printf("*a=%d",*a);
}

void maxmin(int *max,int *min,int len,int a[])
{
	int i;
	printf("minmax sizeof a=%lu\n",sizeof(a));
	printf("maxmina=%p\n",a);
	a[0]=1000;
	*max=*min=a[0];
	
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

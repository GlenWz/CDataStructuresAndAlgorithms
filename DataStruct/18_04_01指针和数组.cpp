#include <stdio.h>
//传入数组进入指针 
void minmax(int a[],int len,int *min,int *max);
int main()
{
	int a[]={1,5,3,7,21,28,};
	int min,max;
	printf("main sizeof(a)=%lu\n",sizeof(a));
	printf("main a=%p\n",a);
	minmax(a,sizeof(a)/sizeof(a[0]),&min,&max);
	printf("a[0]=%d\n",a[0]);
	printf("min=%d,max=%d\n",min,max);
	int *p=&min;
	printf("*p=%d\n",*p);
	printf("p[0]=%d\n",p[0]);
	printf("*a=%d\n",*a);
	return 0;
	
}
void minmax(int *a,int len,int *min,int *max)
{
	int i;
	*min=*max=a[0];
	a[0]=1000;
	for(i=1;i<len;i++)
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

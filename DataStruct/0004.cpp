#include <stdio.h>

int main()
{
	int i;
	int a[5]={0,1,2,3,4};
	int *p=a;
	for(i=0;i<5;i++)
	{
		printf("a[%d]=%d *(a+%d)=%d p[%d]=%d *(p+%d)=%d\n",i,a[i],i,(a+i),i,&p[i],i,(p+i));
		return 0;
	}
}

#include <stdio.h>

int main()
{
	int i;
	int a[5]={1,2,3,4,5,};
	int *p=a;
	for(i=0;i<5;i++)
	{
		printf("&a[%d]=%p p+%d=%p\n",i,&a[i],i,p+i);
		//printf("ai=%d	ai+1=%d		ai-1=%d \n",&a[i]),&a[i+1],&a[i-1];
	}
	return 0;
}

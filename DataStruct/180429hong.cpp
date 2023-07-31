#include <stdio.h>

int main()
{
	int a[]={0,1,2,3,4,5,};
	int *p=a;
	printf("%d\n",&a);
	printf("%d\n",&a[1]);
	printf("%d\n",p);
	printf("%d\n",(p+1));
	printf("%p\n",p);
	printf("%p\n",(p+1));
	return 0;
	
}

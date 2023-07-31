#include <stdio.h>

int main()
{
	char ac[]={0,1,5,4,5,45,78,9};
	char *p=&ac[0];
	int i;
	for(i=0;i<sizeof(ac)/sizeof(ac[0]);i++)
	{
		printf("%d\n",ac[i]);
	}
	printf("\n");
	printf("\n");
	int a[]={1,5,6,8,9,47,5,6,2,3,5,6,0,-1};
	int *q=&a[0];
	while(*q!=-1)
	{
		printf("%d\n",*q++);
	}
	return 0;
}

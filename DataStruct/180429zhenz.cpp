#include <stdio.h>

void any_set(int v[],int n,int val)
{
	int i;
	for(i=0;i<n;i++)
	{
		v[i]=val;
	}
}

int main()
{
	int i;
	int a[]={1,2,3,4,5};
	any_set(a,5,99);
	for(i=0;i<5;i++)
	{
		printf("a[%d]=%d\n",i,a[i]);
	}
	return 0;
}

#include <stdio.h>

int main()
{
	int a[]={1,2,3,2,4,6,3,6,9,};
	int n=sizeof(a)/sizeof(a[0]);
	int j=0;
	for(int i=0;i<n;i++)
	{
		j++;
		printf("%d\t",a[i]);
		if(j%3==0)
		{
			printf("\n");
		}
	}
}

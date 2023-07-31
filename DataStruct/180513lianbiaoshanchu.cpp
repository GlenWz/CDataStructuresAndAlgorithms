#include <Stdio.h>

int main()
{
	int a[]={1,2,3,3,4,5,6,7,};
	int n=sizeof(a)/sizeof(a[0]);
	int j,i;
	printf("please input the number of delete");
	scanf("%d",&j);
	if(j>n||j<0)
	{
		printf("xxxx");
	}
	else
	{
		for(i=j;i<n;i++)
		{
			a[i]=a[i+1];
		}
	}
	for(i=0;i<sizeof(a)/sizeof(a[0])-1;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}

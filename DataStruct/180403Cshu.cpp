#include <stdio.h>

int main()
{
	int a[3]={0,};
	int x;
	int j=0;
	scanf("%d",&x);
	while(x!=-1)
		{
	     a[j]=x;
		j++;	
		scanf("%d",&x);	
	}
	if(a[1]>a[2]&&a[1]>a[0])
	{
		printf("max=%d\n",a[1]);
	}
	if(a[2]>a[1]||a[2]>a[0])
	{
		printf("max=%d\n",a[2]);
	}
	if(a[0]>a[2]||a[0]>a[1])
	{
		printf("max=%d\n",a[0]);
	}
	return 0;
	
	
	
}

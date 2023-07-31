#include <stdio.h>
//判断一个属是否可以被3和5整除 
int main()
{
	int x;
	int i=1;
	scanf("%d",&x); 
	if(x%3==0||x%5==0)
	{
		i=0;
	}
	if(i==0)
	{
		printf("neng");
	}
	else
	{
		printf("buneng");
	}
	return 0;
}

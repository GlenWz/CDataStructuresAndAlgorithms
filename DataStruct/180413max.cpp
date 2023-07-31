#include <stdio.h>
//依次输入十个数字，求出最大值 
int main()
{
	int max=0;
	int s[10]={0,};
	printf("输入十个数字");
	for(int i=0;i<10;i++)
	{
	    scanf("%d",&s[i]);
	}
	for(int i=0;i<10;i++)
	{
		if(s[i]>max)
		{
			max=s[i];
		}
	}
	printf("max=%d\n",max);
	return 0;
}

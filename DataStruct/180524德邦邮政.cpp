#include <stdio.h>

int main()
{
	int i,sum;
	sum=0;
	for(i=1;i<13;i++)
	{
		sum=7+3*i;
		printf("德邦%d公斤,总价为%d\n",i,sum);
	}
	for(i=1;i<13;i++)
	{
		sum=15+2*i;
		printf("邮政%d公斤,总价为%d\n",i,sum);
	}
	return 0;
}

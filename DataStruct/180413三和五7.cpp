#include <stdio.h>
//�ж�һ�����Ƿ���Ա�3��5���� 
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

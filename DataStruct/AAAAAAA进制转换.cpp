#include <Stdio.h>

int main()
{
	int num,con;
	int stack[100];
	int top=-1; 
	printf("please input the 10 jinzhi num:\n");
	scanf("%d",&num);
	printf("please input the jinzhi :\n");
	scanf("%d",&con);
	while(num!=0)
	{
		stack[++top]=num%con;
		num/=con;
	}
	printf("The result: ");
	while(top!=-1)
	{
		printf("%d ",stack[top--]);
	}
}

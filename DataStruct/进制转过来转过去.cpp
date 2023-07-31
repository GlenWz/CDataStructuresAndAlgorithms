#include <Stdio.h>

int main()
{
	int num,con,sum,count,SumA,gd,gd1;
	int stack[100]={0,};
	int q[100]={0,};
	int front=0,rear=0;
	int top=-1;
	count=0;
	sum=0; 
	SumA=1;
	printf("please input the num:\n");
	scanf("%d",&num);
	printf("please input the con:\n");
	scanf("%d",&con);
	while(num!=0)
	{
		stack[++top]=q[rear++]=num%con;
		num/=con;
	}	
	while(top!=-1)
	{
		gd=stack[top--];
		gd1=q[front++];
		printf("%d ",gd);
		sum=sum+(gd1*SumA);
		SumA*=con;
	}
	printf("\n");
	printf("the jinzhi :%d\n",sum);
}




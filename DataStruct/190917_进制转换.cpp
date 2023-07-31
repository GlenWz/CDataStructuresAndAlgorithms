#include <Stdio.h>
#include <Stdlib.h>
#define max 100

void Convert102(int num,int stack[],int &top)
{
	for(;num>0;)
	{
		stack[top++]=num%2;
		printf("num:%d\n",num%2);
		num/=2;
	}
	
}
int Convert210(int stack[],int top)
{
	int stack2[max];
	int top2=0;
	int sum=0,mi=2;
	for(int i=top-1;i>=0;i--)
	{
		stack2[top2++]=stack[i];
	}
	sum=stack2[--top2]*1;
	for(int i=--top2;i>=0;i--)
	{
		sum+=(stack2[i]*mi);
		mi*=2;
	}
	return sum;
}
void PrintS(int stack[],int top)
{
	printf("output:\n"); 
	for(int n=top;n>0;)
	{
		printf("%d",stack[--n]);
	}
	printf("\n");
}
void Convert108(int &num,int stack[],int &top)
{
	for(;num>0;)
	{
		stack[top++]=num%8;
		num/=8;
	}
}
int Convert810(int stack[],int top)
{
	int stack2[max];
	int top2=0;
	int sum;
	int mi=8;
	for(int i=top-1;i>=0;i--)
	{
		stack2[top2++]=stack[i];
	}
	sum=stack2[--top2]*1;
	for(int i=top2-1;i>=0;i--)
	{
		sum+=(stack2[i]*mi);
		mi*=8;
	}
	return sum;
} 


int main()
{
	printf("please input the num!\n");
	int num;
	scanf("%d",&num);
	int stack[max];
	int top=0;
	Convert102(num,stack,top);
	PrintS(stack,top);
	int sum=Convert210(stack,top);
	printf("\n%d\n",sum);
	
	printf("\n十进制转8进制:\n");
	top=0;
	Convert108(sum,stack,top);
	PrintS(stack,top);
	printf("\n八进制转十进制:\n");
	int Con8=Convert810(stack,top);
	printf("%d",Con8);
}












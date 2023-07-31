#include <stdio.h>
#include <stdlib.h>

void Fb(int n)
{
	int a=1,b=1,c,queue[5],front=0,rear=0;
	queue[rear++]=a;
	queue[rear++]=b;
	for(int i=0;i<n;i++)
	{
		if(front%5==0)
		{
			front=0;
		}
		a=queue[front++];
		printf("%d  ",a);
		if(front%5==0)
		{
			front=0;
		}
		b=queue[front++];
		printf("%d  ",b);
		if(rear%5==0)
		{
			rear=0;	
		}
		c=a+b;
		queue[rear++]=c;
		if(rear%5==0)
		{
			rear=0;
		}
		a=b+c;
		queue[rear++]=a;
		
	}
}




int main()
{
	int n;
	printf("please input the n:\n");
	scanf("%d",&n);
	Fb(n);	
}




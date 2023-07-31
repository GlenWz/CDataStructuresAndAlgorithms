#include <stdio.h>
#include <stdlib.h>

void output(int a[])
{
	for(int i=0;i<20;i++)
	{
		printf("%d\n",a[i]);
	}
}




int main()
{
	int x=1; int n,m;
	int a[20]={0,};
	for(int i=0;i<20;i++,x+=2)
	{
		a[i]=x;
	}
//	printf("yao shan chu ji dao ji de ?");
//	scanf("%d %d",&n,&m);
	for(int i=4;(i+5)<20;i++)
	{
		
		if((i+5)==19)
		{
			for(int j=i;i<20;i++)
			{
				a[i]=NULL;
			}
		}
		a[i]=a[i+5];
	}
	
	output(a);
 } 

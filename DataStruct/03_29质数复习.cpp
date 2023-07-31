#include <stdio.h>

int isP(int c,int a[],int i);
int main()
{
	int i=3;
	int c=1;
	int a[100]={2,};
	while(c<100)
	{
		if(isP(i,a,c))
		{
			a[c++]=i;
		}
		i++;
	}
	for( i=0;i<100;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}
int isP(int x,int k[],int j)
{
	
	int i;
	int ret=1;
	for(i=0;i<x;i++)
	{
		if(x%k[i]==0)
		{
			ret=0;
			break;
		}
	}
	return ret;
}

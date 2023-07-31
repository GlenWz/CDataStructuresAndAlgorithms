#include <stdio.h>
//判断是否为质数
int isP(int i,int knownprimes[],int numberOfKnownprimes);
int main()
{
	int count=1;
	int prime[100]={2,};
	int x=0;
	int i=3;
	
	while(count<100)
	{
		if(isP(i,prime,count))
		{
			prime[count++]=i;
		}
		i++;
	}
	for(i=0;i<100;i++)
	{
		printf("%d",prime[i]);
		if((i+1)%5)
		{
			printf("\t");
		}
		else
		{
			printf("\n");
		}
	}
	return 0;
 } 
 int isP(int x,int knownprimes[],int numberOfKnownprimes)
{
	int ret=1;
	int i;
	for(i=0;i<numberOfKnownprimes;i++)
	{
		if(x%knownprimes[i]==0)
		{
				ret=0;
				break;
		}
	}
	return ret;
}

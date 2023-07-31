#include <Stdio.h>
#include <math.h>
//100 - 200 zhishu 

int isPrime(int x)
{
	int ret=1;
	for(int i=2;i<sqrt(x);i++)
	{
		if(x%i==0)
		{
			ret=0;
		}
	}
	return ret;
}

int main()
{
	int cnt=0;
	int num=100;
	int prime[num]={101,};
	int i=102;
	for(i;i<200;i++)
	{
		if(isPrime(i))
		{
			prime[++cnt]=i;
		}
	}
	for(i=0;prime[i]!='\0';i++)
	{
		printf("%d\t",prime[i]);
	}
}

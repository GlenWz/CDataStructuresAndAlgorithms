#include <Stdio.h>
#include <Stdlib.h>
#include <math.h>

int isprime(int num)
{
	int ret=1;
	for(int i=2;i<sqrt(num)+1;i++)
	{
		if(num%i==0)
		{
			ret=0;
		}
	}
	return ret;
}
void Prime_Print()
{
	int j=1000;
	for(int i=2;i<1000;i++)
	{
		if(isprime(i))
		{
			printf("%d\t",i);
		}
	}
}


int main()
{
	Prime_Print();
	
	
}

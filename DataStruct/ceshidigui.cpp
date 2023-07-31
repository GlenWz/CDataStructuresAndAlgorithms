#include <Stdio.h>

int DG(int n,int sum)
{
	if(n==0)
	{
		return sum;		
	}else 
	{
		sum*=n;
		n--;
		DG(n,sum);
	}
}



int main()
{
	int n=5;
	int sum=1;
	int s=DG(n,sum);
	printf("%d",s);
}

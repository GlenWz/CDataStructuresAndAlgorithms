#include <Stdio.h>

void fdg(int &sum)
{
	int x;
	for(;;)
	{
		scanf("%d",&x);
		if(x==0)
		{
			break;
		}else 
		{
			sum+=x;
		}
	}
}
void ZHUAN10(int &sum)
{
	int tmp=sum,s,ts;
	int count=0;
	int n=2;
	tmp=sum;
	s=tmp%10;
	tmp/=10;
	for(;tmp>0;)
	{
		ts=tmp%10;
		tmp/=10;
		ts=ts*n;
		n*=2;
		s+=ts;
	}
	
	sum=s;
}


int main()
{
	int sum=0;
	fdg(sum);
	printf("\nthe sum is %d\n",sum);
	ZHUAN10(sum);
	printf("\nthe sum is %d\n",sum);
}

#include <stdio.h>

int main()
{
	double sum=300000.0;
	int m=0;
	while(sum>=0)
	{
		sum=sum-(6000-sum*0.01);
		printf("%lf\n",sum);
		m++;
	}
	printf("%d\n",m);
}

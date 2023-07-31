#include <Stdio.h>

int main()
{
	double sum=3900000;
	double x=0.0;
	for(;;)
	{
		scanf("%lf",&x);
		if(x==0)
		{
			break;
		}else 
		{
			sum*=x;
		}
	}
	printf("%lf",sum);
}

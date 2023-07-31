#include <Stdio.h>


int main()
{
	double n=60000.0;
	for(int i=0;i<5;i++)
	{
		n/=1.03;
	}
	printf("%lf\n",n);
}

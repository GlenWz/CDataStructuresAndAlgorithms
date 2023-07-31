#include <Stdio.h>
#include <math.h>

void sum_e()
{
	double sum=0.0;
	double fz=1.0;
   	double fm=1.0;
   	double jc=0.0;
	int j=1;
	for(int i=0;i<10;i++)
	{
		for(int k=1;k<=j;k++)
		{
			fm*=k;
		}
		jc=fz/fm*1.0;
		sum+=jc;
		fm=1.0;
		j++;
	 } 
	 printf("%lf",sum);
}



int main()
{
	sum_e();
}

#include <Stdio.h>
#include <Stdlib.h>

int main()
{
	//qiu xu nie 
	double fz=3;
	double fm=2;
	double tmp=0;
	double prfz=2;
	double prfm=1;
	double sum=2.0; 
	for(int i=0;i<20;i++)
	{
		printf("%lf\n",fz/fm*1.0);
		sum+=(fz/fm);
		tmp=prfz;
		prfz=fz;
		fz+=tmp;
		tmp=prfm;
		prfm=fm;
		fm+=tmp;
	}
	printf("%lf\n",sum);
}

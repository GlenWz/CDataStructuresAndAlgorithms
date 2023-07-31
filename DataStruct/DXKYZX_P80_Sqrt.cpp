#include <Stdio.h>
#include <Stdlib.h>
#include <math.h>

int Sqrt(int A,double &p,double e)
{
	if(abs((p*p-A))<e)
	{
		return 0;
	}else 
	{
		double p_2=0.5*(p+A/p);
		p=p_2;
		Sqrt(A,p,e);
	}
}
double SqrtFDG(int A,double p1,double e)
{
	double p_2=p1;
	while(abs((p1*p1-A))>=e)
	{
		p_2=(p1+A/p1)/2;
		p1=p_2;
	}
	return p1;
}




int main()
{
	int A=8;
	double p=2.0,p1=2.0;
	double e=0.001;
	Sqrt(A,p,e);	
	printf("the %d Sqrt is %lf \n",A,p);
	double p2=SqrtFDG(A,p1,e);
	printf("the %d Sqrt is %lf \n",A,p2);
}

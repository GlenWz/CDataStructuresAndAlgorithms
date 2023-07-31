#include <Stdio.h>
#include <math.h>
#include <Stdlib.h>

double NewtonSqrt(int x)
 {
	if (x == 0) return 0;
	double result = 1, pre = 0;
	while (result != pre)
	{
		pre = result;
		result = (result + x / result) / 2;
	}
	return result;
}

double NewTON(int w)
{
	int x=1.1,x0=0,root,fd,f;
	if(x==0)
	{
		return 0;
	}
	while(x0!=x)
	{
		x0=x;
		f=x*x-w;
		fd=2*x;
		root=x-f/fd;
		x=root;
	}
}



int main()
{
	int b=5;
	double v=NewtonSqrt(b);
	double w=NewTON(b);
	printf("%lf\n%lf\n",v,w);
	
}

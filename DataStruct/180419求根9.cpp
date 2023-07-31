#include <stdio.h>
#include <math.h>
//x^2+2xy+c;
int main()
{
	double a,b,c;
	double dx,x1,x2;
	printf("ÇëÊäÈëabc");
	scanf("%lf %lf %lf",&a,&b,&c);
	dx=b*b-4*a*c;
	if(dx>0)
	{
		dx=sqrt(b*b-4*a*c);
		x1=(-1*b+dx)/2.0*a;
		x2=(-1*b-dx)/2.0*a;
		printf("x1=%lf x2=%lf",x1,x2);
	}
	 return 0;
}

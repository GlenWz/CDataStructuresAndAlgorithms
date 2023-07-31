#include <stdio.h>
#include <math.h>
//hailun qin jiusao
int main()
{
	double t,s;
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	if(a+b>c&&a+c>b&&b+c>a)
	{
		t=(a+b+c)/2.0;
		s=sqrt(t*(t-a)*(t-b)*(t-c));
		printf("area is %lf",s);
	}
	
	return 0;
	
	
}

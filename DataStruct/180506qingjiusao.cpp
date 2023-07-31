#include <stdio.h>
#include <math.h>
int main()
{
	double a,b,c,t,s;
	printf("请分别输入三边：");
	scanf("%lf %lf %lf",&a,&b,&c);
	if(a+b<c||a+c<b||b+c<a)
	{
		printf("fault");
	}
	else
	{
		t=1.0/2*(a+b+c);
		s=sqrt(t*(t-a)*(t-b)*(t-c));
		printf("mianjishi%lf",s);
	}
	return 0;
}

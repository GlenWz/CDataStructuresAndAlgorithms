#include <Stdio.h>
#include <math.h>
//���Ԫһ�η��� 
int main()
{
	double a, b,c;
	double d,x,x2;
	printf("��ֱ�����abc");
	scanf("%lf %lf %lf",&a,&b,&c);
	d=b*b-4*a*c;
	if(d<0)
	{
		printf("�޽�");
		return 0;
	 } 
	else
	{
		x=(-b+sqrt(d))/2*a;
		x2=(-b-sqrt(d))/2*a;
		printf("%lf %lf",x,x2);
	}
	return 0;
	
}

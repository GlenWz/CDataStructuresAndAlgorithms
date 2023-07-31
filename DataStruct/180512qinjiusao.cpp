#include <Stdio.h>

int main()
{
	int n=5;
	double sum,i,x;
	double a[n+1];
	sum=0.0;
	printf("x shi?");
	scanf("%lf",&x);
	for(int j=0;j<n+2;j++)
	{
		printf("cong a0 kaishi shuru xi shu \n");
		scanf("%f",&a[j]);
	}
	for(int j=n+1;j>0;j++)
	{
		sum=x*a[j]*1.0+a[j-1];
	}
	printf("sum=%f",sum);
}

#include <Stdio.h>
//qijjiushao suanfa shixian

void qin(double sum,double x,double a[],int n)
{
	if(n!=0)
	{
		sum=a[n]*x*1.0;
		n=n-1;
		qin(sum,x,a[n-1],n);
	}
    printf("%lf",sum);
}



int main()
{
	printf("zuigaoweidejishushi:\n");
	int n;
	double x,sum;
	sum=0.0;
	scanf("%d",&n);
	printf("Please input X");
	scanf("%lf",&x);
	double a[n];
	for(int i=0;i<i;i++)
	{
		printf("shurujishu,cong a0 kaishi");
		scanf("%lf",&a[i]);
	}
	qin(sum,x,a[n],n);
	return 0;
}

#include <Stdio.h>
#include <stdlib.h>
#define MONTHS 54

int main()
{
	//double Months[MONTHS]={0.0,500.0,300.0,300.0,};
	double Months[MONTHS]={0.0};
	double sum[MONTHS]={0.0,};
	double benj[MONTHS]={0.0,};
	double interestMonth[MONTHS]={0.0,};
	int COUNT_Y=0;
	for(int i=1;i<MONTHS;i++)
	{
		if(i%12==1)
		{
			++COUNT_Y;
			printf("请输入第 %d 年每月定投:\n",COUNT_Y);
			double M;
			scanf("%lf",&M);
			for(int j=i;j<i+10;j++)
			{
				Months[j]=M;
			}
		
		}
		benj[i]=(Months[i]+sum[i-1])*1.0082;
		sum[i]=benj[i];
		interestMonth[i]+=(interestMonth[i-1]+(Months[i]+sum[i-1])*0.0082);
		if(i%12==1)
		{
			printf("\n第%d年的利息总和：%lf\n",COUNT_Y-1,interestMonth[i]);
		}
		printf("本月利息和本金：%lf		,利息和本金总和：%lf\n",benj[i],sum[i]);
	}	
	printf("\n%lf\n",interestMonth[53]);
	double n=sum[MONTHS-1];
	for(int C=COUNT_Y;C>0;C--)
	{
		n/=1.03;
	}
	printf("Before:%lf\nLater:%lf\n",sum[MONTHS-1],n);
}



#include <Stdio.h>
#include <Stdlib.h>
#include <math.h>

double Yingyong(int years,double sum,double bz)
{
	sum+=(bz*12);
	years--;
	bz=(1+0.1)*bz;
	if(years==0)
	{
		return sum;
	}
	return Yingyong(years,sum,bz);
}
double Kaifa(int y,double sum, double bj)
{
	sum+=(bj*12);
	y--;
	bj=(1+0.2)*bj;
	if(y==0)
	{
		return sum;
	}
	return Kaifa(y,sum,bj);
}



int main()
{
	int years;
	double sumYY,bzyy,sumkf,bjkf;
	bzyy=3000.0;
	sumYY=0;
	bjkf=8000;
	sumkf=-15000;
	printf("please input the years!\n");
	scanf("%d",&years);
	double al=Yingyong(years,sumYY,bzyy);
	double kf=Kaifa(years-4,sumkf,bjkf);
	printf("%d years later sum YY is %lf\tKaifa is %lf",years,al,kf);
	
}

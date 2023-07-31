#include <stdio.h>
#include <stdbool.h>

struct date{
	int y;int m;int d;
};

int numberofday(struct date d);
bool isleap(struct date d);
bool isleap(struct date d)
{
	bool leap=false;
	if((d.y%4==0&&d.y%100!=0)||d.y%400==0)
	{
		leap=true;
	}
	return leap;
}

int numberofday(struct date d)
{
	int days;
	const int numberpermonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(d.m==2&&isleap(d))
	{
		days=29;
	}
	else
	{
		days=numberpermonth[d.m-1];
	}
	return days;
}

int main()
{
	struct date today,tom;
	printf("please input a date y,m,d");
	scanf("%i %i %i",&today.y,&today.m,&today.d);
	if(today.d!=numberofday(today))
	{
		tom.d=today.d+1;
		tom.m=today.m;
		tom.y=today.y;
	}
	else if(today.m!=12)
	{
		tom.d=1;
		tom.m=today.m+1;
		tom.y=today.y;
	}
	else
	{
		tom.d=1;
		tom.m=1;
		tom.y=today.y+1;
	}
	printf("%d-%d-%d",tom.m,tom.d,tom.y);
	return 0;
	
	
	
	
}

#include <stdio.h>
#include <stdbool.h>

struct date{
	int y;
	int m;
	int d;
};
int numberosdays(struct date d);
bool isleap(struct date d);
int numberofdays(struct date d)
{
	int days;
	const int daypermonth[12]={31,28,31,30,31,30,31,31,30,31,30,31,};
	if(d.m==2&&isleap(d))
	{
		days=29;
	}
	else
	{
		printf("printf=%d\n",d.m);
		days=daypermonth[d.m-1];
		printf("printf=%d\n",days);
	}////*********************************  less a return number of int
	return days;
}
bool isleap(struct date d)
{
	bool leap=false;
	if((d.y%4==0&&d.y%100!=0)||d.y%400==0)
	{
		leap=true;
	}
	return leap;
}
int main()
{
	struct date today,day,tom;
	printf("please input y,m,d");
	scanf("%d %d %d20",&today.y,&today.m,&today.d);
	if(today.d!=numberofdays(today))
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
	printf("%i-%i-%i",tom.m,tom.d,tom.y);
}

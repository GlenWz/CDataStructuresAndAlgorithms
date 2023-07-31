#include <stdio.h>
#include <stdbool.h>
struct date{
	int year;
	int month;
	int day;
};
bool isleap(struct date d);
int numberofdays(struct date d);
int mian()
{
	struct date today,tom;
	printf("please input year month day");
	scanf("%i %i %i",&today.year,&today.month,&today.day);
	if(today.day!=numberofdays(today))
	{
		tom.day=today.day+1;
		tom.month=today.month;
		tom.year=today.year;
	}
	else if(today.month==12)
	{
		tom.day=1;
		tom.month=1;
		tom.year=today.year+1;
	}
	else{
		tom.day=1;
		tom.month=today.month+1;
		tom.year=today.year;
	}
	printf("tom date is %i-%i-%i",tom.month,tom.day,tom.year);
	
}
int numberofdays(struct date d)
{
	int days;
	const int dayspermonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(d.month==2&&isleap(d))
	{
		days=29;
	}
	else
	{
		days=dayspermonth[d.month-1];
	}
	return days;
}
bool isleap(struct date d)
{
	bool leap=false;
	if((d.year%4==0&&d.year%100!=0)||d.year%400==0)
	{
		leap=true;
	}
	return leap;
}









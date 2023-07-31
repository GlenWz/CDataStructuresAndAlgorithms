#include <stdio.h>
#include <stdbool.h>
typedef struct dat{
	int year;int month;int day;
}date;

bool isleap(date d)
{
	bool leap=false;
	if((d.year%4==0&&d.year%100!=0)||d.year%400==0)
	{
		leap=true;
	}
	return leap;
}


int numberofdays(date d)
{
	int days;
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31,};
	if(d.month==2&&isleap(d))
	{
		days=29;
	}else
	{
		days=a[d.month-1];
	}
	return days;
}


int main()
{
	date today,tom;
	printf("please input the date of today,m,d,y");
	scanf("%d %d %d",&today.month,&today.day,&today.year);
	if(today.day!=numberofdays(today))
	{
		tom.day=today.day+1;
		tom.month=today.month;
		tom.year=today.year;
	}
	else if(today.month!=12)
	{
		tom.day=1;
		tom.month=today.month+1;
		tom.year=today.year;
	}
	else
	{
		tom.day=1;
		tom.month=1;
		tom.year=today.year+1;
	}
	printf("tom is %d-%d-%d",tom.month,tom.day,tom.year);
	return 0;
	
}

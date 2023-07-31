#include <stdio.h>
#include <stdbool.h>

typedef struct day{
	int year;int month;int day;
}days;

bool isleap(days d)
{
	bool leap=false;
	if((d.year%4==0&&d.year%100!=0)||d.year%400==0)
	{
		leap=true;
	}
	return leap;
}


int numberofdays(days d)
{
	int dd;
	int daypermonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(d.month=2&&isleap(d))
	{
		dd=29;
	}
	else
	{
		dd=daypermonth[d.month-1];
	}
	return dd;
}




int main()
{
	days today,tom;
	printf("please input  the date of today");
	scanf("%d %d %d",&today.year,&today.month,&today.day);
	if(today.day!=numberofdays(today))
	{
		tom.day=today.day+1;
		tom.month=today.month;
		tom.year=today.year;
	}else if(today.month!=12)
	{
		tom.day=1;
		tom.month=today.month+1;
		tom.year=today.year;
	}else
	{
		tom.day=1;
		tom.month=1;
		tom.year=tom.year+1;
	}
	printf("%i-%i-%i",tom.month,tom.day,tom.year);
	return 0;
}

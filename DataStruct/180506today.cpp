#include <stdio.h>
#include <stdbool.h>

struct date
{
	int month;
	int day;
	int year;
};
bool isLeap(struct date d);
int numberofdays(struct date d);
int main()
{
	struct date today,tom;
	printf("enter today's date(mm dd yyy):");
	scanf("%i %i %i",&today.month,&today.day,&today.year);
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
	printf("%i-%i-%i\n",tom.month,tom.day,tom.year);
	return 0;
	
}
int numberofdays(struct date d)
{
	int days;
	const int dayspermonth[12]={31,28,31,30,31,30,31,31,30,31,30,31,};
	if(d.month==2&&isLeap(d))
	{
		days=29;
	}
	else
	{
		days=dayspermonth[d.month-1];
	}
	return days;
}
bool isLeap(struct date d)
{
	bool leap=false;
	if((d.year%4==0&&d.year%100!=0)||d.year%400==0)
	{
		leap=true;
	}
	return leap;
}












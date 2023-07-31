#include <stdio.h>
#include <time.h>

int TimeKy()
{
	time_t timep;
	struct tm *p;
	time(&timep);
	p=gmtime(&timep);
	int Month=p->tm_mon;
	int Day=p->tm_mday;
	int DayOfMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31,};
	int SumDay=0;
	int Kyday=0;
	for(int i=0;i<Month;i++)
	{
		SumDay+=DayOfMonth[i];
	}
	SumDay+=Day;
	printf("sumday:%d\n",SumDay);
	Kyday=365-SumDay-10;
	return Kyday;
	
}


int main()
{
	int kyt=TimeKy();
	printf("%d",kyt);
}

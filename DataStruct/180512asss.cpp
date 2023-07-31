#include <Stdio.h>


int main()
{
	struct{
	int month;int day;int year;
}myday;
	struct date *p=&myday;
	(*p).month=12;
	p->month=12;
	printf("%d %d",p.month,*p);
}

#include <Stdio.h>

struct date{
	int y;
	int d;
	int m;
};

int main()
{
	struct date today;
	today=(struct date){2018,31,7	};
	struct date day;
	day=today;
	today.y=2017;
	struct date *pDate=&today;
	
	printf("%i-%i-%i\n",day.y,day.m,day.d);
	printf("%i-%i-%i\n",today.y,today.m,today.d);
	printf("address is %p\n",pDate);
	
	return 0;
	
}

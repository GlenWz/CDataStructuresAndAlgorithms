#include <stdio.h>

struct time{
	int hour;int minutes;int seconds;
};
struct time timeupdate(struct time now);
int main()
{
	struct time testtime[5]={
		{11,59,59},{12,0,0},{1,29,59},{23,59,59},{19,12,27}
	};
	int i;
	for(i=0;i<5;++i)
	{
		printf("time is %.2i:%.2i:%.2i",testtime[i].hour,testtime[i].minutes,
		testtime[i].seconds);
		testtime[i]=timeupdate(testtime[i]);
		printf("...one secnd later it's %.2d:%.2d:%.2d\n",
		testtime[i].hour,testtime[i].minutes,testtime[i].seconds);
	}
	return 0;
}
struct time timeupdate(struct time now)
{
	++now.seconds;
	if(now.seconds==60)
	{
		now.seconds=0;
		++now.minutes;
		if(now.minutes==60)
		{
			now.minutes=0;
			++now.hour;
			if(now.hour==24)
			{
				now.hour=0;
			}
		}
	}
	return now;
}

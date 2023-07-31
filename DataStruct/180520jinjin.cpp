#include <stdio.h>

struct time{
	int hour;int min;int sec;
};

struct time timeupdate(struct time now);

int main()
{
	struct time testtime[5]={
		{11,59,59},{12,59,59},{13,59,21},{23,59,59},{12,46,42}
	};
	int i;
	for(i=0;i<5;i++)
	{
		printf("time is %d:%d:%d",
		testtime[i].hour,testtime[i].min,testtime[i].sec);
		testtime[i]=timeupdate(testtime[i]);
		printf("one second ....%d:%d:%d\n",
		testtime[i].hour,testtime[i].min,testtime[i].sec);
	}
	return 0;
}

struct time timeupdate(struct time now)
{
	++now.sec;
	if(now.sec==60)
	{
		now.sec=0;
		now.min=now.min+1;
		if(now.min==60)
		{
			now.min=0;
			now.hour=now.hour+1;
			if(now.hour==24)
			{
				now.hour=0;
			}
		}
	}
	return now;
}

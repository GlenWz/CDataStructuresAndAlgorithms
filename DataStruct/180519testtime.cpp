#include <stdio.h>

struct time{
	int hour;int min;int sec;
};

struct time tx(struct time now)
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

int main()
{
	struct time testtime[]={
		{12,59,59},{11,59,59},{2,30,31},{23,59,59},{13,15,19}
	};
	int i;
	for(i=0;i<sizeof(testtime)/sizeof(testtime[0]);i++)
	{
		printf("now is %.2d:%.2d:%.2d",testtime[i].hour,testtime[i].min,testtime[i].sec);
		testtime[i]=tx(testtime[i]);
		printf("one second later is %.2d:%.2d:%.2d\n",testtime[i].hour,testtime[i].min,testtime[i].sec);
	}
	return 0;
}

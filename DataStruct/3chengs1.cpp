#include <stdio.h>
#include <time.h>
clock_t start,stop;
double duration;
int main()
{
	start=clock();
	for(int c=0;c<1000;c++)
  	{
	int i,n;
	for(i=1;i<=3;i++)
	{
		for(n=1;n<=3;n++)
		{
			printf("%d\t",i*n);
			if(n%3==0)
           {
        	printf("\n");
        	}
		}
    }
	}
	stop=clock();
	duration=((double)(stop-start))/CLK_TCK;
	printf("t1=%lf",duration);
	return 0;
}

#include <stdio.h>

int main()
{
	int i=3;
	int j=2;
	int r=1;
	for(i=3;i<200;i++)
	{
		for(j=2;j<20;j++)
		{
			r=i%j;
			if(r==0)
			{
				break;
			}
		}
		if(r!=0&&i>100)
		{
			printf("%d\t",i);
		}
	}
	return 0;
}

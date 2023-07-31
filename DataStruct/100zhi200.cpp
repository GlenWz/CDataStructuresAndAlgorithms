#include <stdio.h>

int main()
{
	int ret=1;
	int p=3;
	int j=2;
	for(p=3;p<200;p++)
	{
		for(int j=2;j<20;j++)
		{
			ret=p%j;
			if(ret==0)
			{
				break;
			}
		}
		if(ret!=0&&p>100)
		{
			printf("%d\t",p);
		}
	}
	return 0;
}

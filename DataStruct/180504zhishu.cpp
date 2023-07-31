#include <stdio.h>

int main()
{
	int i=3;
	int ret=1;
	for(i=3;i<1000;i++)
	{
		for(int j=2;j<i&&j<35;j++)
		{
			
			ret=i%j;
			if(ret==0)
			{
				break;
		    }
		}
		if(ret!=0)
		{
			printf("%d\t",i);
		}
	}
	return 0;
}


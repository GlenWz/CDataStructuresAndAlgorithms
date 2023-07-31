#include <stdio.h>

int main()
{
	int i,j;
	int ret=1;
	for(i=3;i<100;i++)
	{
		for(j=2;j<11&&j<i;j++)
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

#include <stdio.h>

int main()
{
	int p=3;
	int i=0;
	int d=1;
	
	for(int p=3;p<100;p++)
	{
		for(i=2;i<p;i++)
		{
			if(p%2==0)
			{
				d=0;
				break;
			}
		}
		
		if(d!=0)
		{
			printf("%d\t",p);
		}
	
	}
	return 0;
}

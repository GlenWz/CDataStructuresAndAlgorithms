#include <stdio.h>
//求100到200之间的质数 
int main()
{
	int x;
	int i=2;
	for(int j=3;j<200;j++) 
	{
		for(i=2;i<20;i++)
		{
			x=j%i;
			
			if(x==0)
			{
				break;
			}
			
		}
		if(x!=0&&j>100)
		{
			printf("%d\t",j);
		}
		
	}
	
	return 0;
}

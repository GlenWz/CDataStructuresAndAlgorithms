#include <stdio.h>

int main()
{
	int j=0;
	int p=3;
	int i=2;
	int k=1;
	for(int j=3;j<100;j++)
	{
		for(i=2;i<j;i++)
		{
			if(j%i==0)
			{
				k=0;
				break;
			}
		}
		if(k!=0)
		{
			printf("%d\t",j);
		}	
	}
	return 0;
}

#include <stdio.h>

int main()
{
	int j=1;
	int sum=0;
	for(int i=0;i<100;i++)
	{
		sum+=j;
		j++;
	}
	printf("%d\n",sum);
	return 0;
	
	
}

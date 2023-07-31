#include <stdio.h>

int main()
{
	int x;
	int i=0;
	scanf("%d",&x);
	while(x!=1)
	{
		if(x%2==0)
		{
			x/=2;
			i++;
		}
		else
		{
			x=3*x+1;
			i++;
		}
	}
	printf("%d\n",i);
	return 0;
}

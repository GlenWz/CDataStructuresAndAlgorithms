#include <stdio.h>
#include <stdlib.h>

int main()
{
	int s=1,h;
	printf("input cengshu");
	scanf("%d",&h);
	printf("1\n");
	for(int i=2;i<=h;s=1,i++)
	{
		printf("1 ");
		for(int j=1;j<=i-2;j++)
		{
			printf("%d ",(s=(i-j)*s/j));
		}
		printf("1\n");
	}
	return 0;
}

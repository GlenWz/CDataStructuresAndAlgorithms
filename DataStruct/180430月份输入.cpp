#include <stdio.h>

int main()
{
	char a[][20]={}; 
	printf("qingshuruyuefen:\n");
	for(int i=0;i<12;i++)
	{
		scanf("%c",&a[i][10]);
	}
	for(int i=0;i<12;i++)
	{
		printf("%cÔÂ\n",a[i][10]);
	}
	return 0;
}

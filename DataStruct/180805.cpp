#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a=1;
	int b=1;
	int c;
	
	for(int i=0;i<20;i++)
	{
		c=a+b;
		printf("%d\t",c);
		a=b;
		b=c;
	}
	printf("end\n");
}

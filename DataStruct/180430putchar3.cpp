#include <stdio.h>

int main()
{
	int i;
	while((i=getchar())!=EOF)
	{
		putchar(i);
	}
	printf("EOF\n");
	return 0;
}

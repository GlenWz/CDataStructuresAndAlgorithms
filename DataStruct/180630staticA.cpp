#include <stdio.h>

int f(void);
int f()
{
	static int all=1;
	printf("all====%d\n",all);
	all+=2;
	printf("All=%d\n",all);
	return all;
}

int main()
{
	f();
	f();
	f();
	return 0;
}

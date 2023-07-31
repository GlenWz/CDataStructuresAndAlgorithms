#include <stdio.h>
int f(void);
int gAll=12;

int f(void)
{
	static int all=1;
	printf("in %s all=%d\n",_func_,all);
	all+=2;
	printf("agn in %s all=%d\n",_func_,all);
	return all;
}



int main()
{
	f();
	f();
	f();
	return 0;
}

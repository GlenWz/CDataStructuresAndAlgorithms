#include <stdio.h>

void f(void)
{
	printf("in f()\n");
}

int main()
{
	int i=0;
	int a[]={1,2};
	void (*pf)(void)=f;
	//f()
	(*pf)();
	printf("******");
	
	
	return 0;
	
}

#include <stdio.h>

int main()
{
	int i;
	i=6;
	int *p=&i;
	printf("%p\n",&*p);
	printf("%p\n",*p);
	printf("%p\n",&i);
	printf("%p\n",i);
	return 0;
}

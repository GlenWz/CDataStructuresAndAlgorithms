#include <stdio.h>


int main()
{
	int i=5;
	int *p=&i;
	int *q=&i;
	
	printf("%d\n",*p);
	printf("%d\n",&i);
	printf("%d\n",&p);
	printf("%d\n",*&p);
	printf("%d\n",&*p);
	printf("%d\n",*&p*5);
	printf("=====\n");
	printf("%d\n",q);
}

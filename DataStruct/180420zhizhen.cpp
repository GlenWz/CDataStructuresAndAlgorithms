#include <stdio.h>

void swap(int *a,int *b);
int main()
{
	int a=6;
	int b=5;
	swap(&a,&b);
	printf("a=%d b=%d",a,b);
	return 0;
	
}

void swap(int *a,int*b)
{
	int j=*a;
	*a=*b;
	*b=j;
}

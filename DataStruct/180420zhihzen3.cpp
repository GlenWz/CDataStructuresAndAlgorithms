#include <stdio.h>

void swap(int *pa,int *pb);
int main()
{
	int a=6;
	int b=5;
	swap(&a,&b);
	printf("%d %d",a,b);
	return 0;
}
void swap(int *pa,int *pb)
{
	int j=*pa;
	*pa=*pb;
	*pb=j;
}

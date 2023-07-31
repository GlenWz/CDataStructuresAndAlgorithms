#include <stdio.h>
#define nub 5

void sort(int a[])
{
	printf("sizeof=%d",sizeof(a)/sizeof(a[0]));
}
int main()
{
	int i,n;
	int a[nub];
	for(i=0;i<nub;i++)
	{
		printf("ÇëÊäÈë£º");
		scanf("%d",&a[i]);
	}
	sort(a);
	return 0;
}

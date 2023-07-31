#include <Stdio.h>

void di(int n)
{
	if(n!=0)
	{
		printf("%d ",n);
		di(n-1);
	}
}

int main()
{
	int j;
	scanf("%d",&j);
	di(j);
	return 0;
}

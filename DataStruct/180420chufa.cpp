#include <stdio.h>
// ruguochufa chenggong fan hui 1 fouze 0
int divide(int a,int b,int *result);
int main()
{
	int a=5;
	int b=0;
	int c;
	divide(a,b,&c);
	printf("%d/%d=%d\n",a,b,c);
	return 0;
}
int divide(int a,int b,int *result)
{
	int ret=1;
	ret=a/b;
	if(b==0)
	{
		ret=0;
	}
	else
	{
		*result=a/b;
	}
	return ret;
}

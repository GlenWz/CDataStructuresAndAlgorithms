#include <stdio.h>

int FB(int n)
{
	if(n==1||n==2)
	{
		return 1;
	}
	return FB(n-1)+FB(n-2);
}


int main(){
	int n=6;
	int sum=FB(n);
	printf("%d",sum);
}

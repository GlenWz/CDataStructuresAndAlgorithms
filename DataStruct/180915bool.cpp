#include <stdio.h>
#include <stdbool.h>

bool panduan(int a,int b)
{
	return a==b;
}
bool panduan2(int a,int c)
{
	return a==c;
}


int main()
{
	int a=10;
	int b=15;
	int c=10;
	bool bol=panduan(a,b);
	bool bll=panduan2(a,c);
	printf("%d\n%d",bol,bll);
}

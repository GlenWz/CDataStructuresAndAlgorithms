#include <stdio.h>
#include <stdlib.h>

void nizhi(int a[])
{
	int tmp;
	int i,j;
	for(i=0,j=9;i<=j;i++,j--)
	{
		tmp=a[i];
		a[i]=a[j];
		a[j]=tmp;
	}
}

void print(int a[])
{
	for(int i=0;i<10;i++)
	{
		printf("%d\n",a[i]);
	}
}




int main()
{
	int a[10]={0,};
	int x=1;
	for(int i=0;i<10;i++,x+=2)
	{
		a[i]=x;
	}
	nizhi(a);
	print(a);
}

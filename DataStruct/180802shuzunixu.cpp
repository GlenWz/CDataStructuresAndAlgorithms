#include <stdio.h>
#include <stdlib.h>

void nixu(int a[])
{
	int tmp;
	int j;
	for(int i=0,j=9;i<j;i++,j--)
	{
		tmp=a[i];
		a[i]=a[j];
		a[j]=tmp;
	}
	
}



int main()
{
	int a[9]={0,};
	for(int i=0;i<9;i++)
	{
		a[i]=i+2;
	}
	nixu(a);
	for(int i=0;i<9;i++)
	{
		printf("%d\n",a[i]);
	}
}

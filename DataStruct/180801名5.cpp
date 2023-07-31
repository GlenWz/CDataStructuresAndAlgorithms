#include <stdio.h>
#include <stdlib.h>

void print(int a[])
{
	for(int i=0;i<15;i++)
	{
		printf("%d\n",a[i]);
	}
	printf("--------------------------------end\n");
}

void swapp(int a[])
{
	int tmp;
	int i=0,j=14;
	int ttp=a[i];
	
	while(i<j)
	{
		while(i<j&&a[j]>ttp)
		{
			--j;
		}
		if(i<j)
		{
			a[i]=a[j];
			++i;
		}
		while(i<j&&a[i]<ttp)
		{
			++i;
		}
		if(i<j)
		{
			a[j]=a[i];
			--j;
		}
	}
	a[i]=ttp;
}


int main()
{
	int a[15]={9,};
	int x=15; int y=20;
	for(int i=1;i<9;i++,x-=2)
	{
		a[i]=x;
	}
	for(int j=14;j>8;j--,y-=3)
	{
		a[j]=y;
	}
	print(a);
	swapp(a);
	print(a);
 } 

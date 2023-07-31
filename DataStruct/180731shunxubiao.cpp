#include <stdio.h>
#include <stdlib.h>

void output(int a[])
{
	for(int i=0;i<20;i++)
	{
		printf("%d\n",a[i]);
	}
	printf("-------------------end\n");
}

void swap(int a[],int m,int n)
{
	int i,j;
	int tmp;
	for(i=m;i<m+n;++i)
	{
		tmp=a[i];
		for(j=i-1;j>=0&&tmp<a[j];--j)
		{
			a[j+1]=a[j];
		}
		a[j+1]=tmp;
	}
}


int main()
{
	int a[20]={0,};
	int x=2; int y=1;
	for(int i=0;i<9;i++,x+=2)
	{
		a[i]=x;
	}
	for(int i=8;i<20;i++,y+=2)
	{
		a[i]=y;
	}
	output(a);
	swap(a,8,11);
	output(a);
}




#include <Stdio.h>
#include <stdlib.h>

void build(int a[])
{
	int x=1;int y=2;
	for(int i=0;i<10;i++,x+=2)
	{
		a[i]=x;
	}
	for(int i=10;i<20;i++,y+=2)
	{
		a[i]=y;
	}
}

void print(int a[])
{
	for(int i=0;i<20;i++)
	{
		printf("%d\n",a[i]);
	}
	printf("0-------------------------end\n");
}

void maopao(int a[],int m,int n)
{
	int i,j,tmp;
	for(i=10;i<m+n;i++)
	{
		tmp=a[i];
		for(j=i-1;j>=0&&tmp<a[j];j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=tmp;
	}
}


int main()
{
	int a[20]={0,};
	build(a);
	print(a);
	maopao(a,10,10);
	print(a);
}

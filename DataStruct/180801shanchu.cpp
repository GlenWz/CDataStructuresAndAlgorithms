#include <stdio.h>
#include <stdlib.h>

void del(int a[],int n,int m)
{
	int mn=m-n;
	int j;
	for(int i=n;(i+mn)<20;i++)
	{
		a[i]=a[i+mn];	
	}
	for(j=(20-mn);j<20;j++)
	{
		a[j]=NULL;
	}
}
void print(int a[])
{
	for(int i=0;i<20;i++)
	{
		printf("%d\n",a[i]);
	}
}



int main()
{
	int a[20]={0,};
	int x=1;
	for(int i=0;i<20;i++,x+=2)
	{
		a[i]=x;
	}
	int n,m;
	printf("shanchu n~ m");
	scanf("%d %d",&n,&m);
	del(a,n,m);
	print(a);
}

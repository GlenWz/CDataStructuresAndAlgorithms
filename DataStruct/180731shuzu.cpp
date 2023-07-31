#include <stdio.h>
#include <stdlib.h>

void swit(int *p,int *q)
{
	int i=*p;
	*p=*q;
	*q=i;
}


void swap(int a[])
{
	int tmp;
	tmp=a[0];
	for(int i=1;i<20;i++)
	{
		for(int j=19;j>i;j--)
		{
			if(a[j]<tmp)
			{
				swit(&a[i],&a[j]);
			}
		}
	}
}
void bianli(int a[])
{
	for(int i=0;i<20;i++)
	{
		printf("%d\n",a[i]);
	}
}



int main()
{
	int i,j;
	int a[20]={15,};
	int x=1; int y=26;
	for(i=1,j=19;i<=j;i++,j--,x+=2,y-=2)
	{
		a[i]=x;
		a[j]=y;
	}
	swap(a);
	bianli(a);
 } 

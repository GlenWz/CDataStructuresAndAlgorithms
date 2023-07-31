#include <Stdio.h>
#include <stdlib.h>

void nixu(int a[])
{
	int i,j;
	int tmp=0;
	for(i=0,j=19;i<=j;i++,j--)
	{
		tmp=a[i];
		a[i]=a[j];
		a[j]=tmp;
	}
	for(int i=0;i<20;i++)
	{
		printf("ai=%d\n",a[i]);
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
	int a[20]={0,};
	int x=2;
	for(int i=0;i<20;i++,x+=2)
	{
		a[i]=x;
	}
	nixu(a);
	bianli(a);
}

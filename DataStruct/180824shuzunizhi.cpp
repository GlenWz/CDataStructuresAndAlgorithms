#include <Stdio.h>
#include <Stdlib.h>
#define maxsize 15


int *build(int a[])
{
	for(int i=0;i<maxsize;i++)
	{
		a[i]=i+i;
	}
	return a;
}

int *nizhi(int a[])
{
	int i,j,tmp;
	for(i=0,j=maxsize-1;i<j;i++,j--)
	{
		tmp=a[i];
		a[i]=a[j];
		a[j]=tmp;
	}
	return a;
}
void print(int a[])
{
	for(int i=0;i<maxsize;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n------------------------------------\n");
}

int main()
{
	int a[maxsize]={};
	int *s=build(a);
	print(s);
	nizhi(s);
	print(s);
}

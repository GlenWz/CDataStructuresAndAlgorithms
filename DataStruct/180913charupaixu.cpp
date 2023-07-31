#include <stdio.h>
#include <Stdlib.h>
#include <Stdbool.h>

void inertort(int a[],int len)
{
	int i,p,tmp;
	for(p=1;p<len;p++)
	{
		tmp=a[p];
		for(i=p;i>0&&a[i-1]>tmp;--i)
		{
			a[i]=a[i-1];
		}
		a[i]=tmp;
	}
	
}
void print(int a[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}

int main()
{
	int a[]={5,8,9,3,45,2,5,62,31,12,19,776,398,32,115,65,94};
	int len=sizeof(a)/sizeof(a[0]);
	inertort(a,len);
	print(a,len);
}

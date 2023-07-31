#include <stdio.h>
#include <Stdlib.h>

void insertort(int a[],int len)
{
	int p,i,tmp;
	int cnt=0;
	for(p=1;p<len;p++)
	{
		tmp=a[p];
		for(i=p;i>=0&&a[i-1]>tmp;i--)
		{
			a[i]=a[i-1];
			cnt++;
		}
		a[i]=tmp;
	}
	printf("insertore:%d\n",cnt);
}
void print(int a[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}

void swap(int *q,int *p)
{
	int j=*q;
	*q=*p;
	*p=j;
}


void bubble(int a[],int len)
{
	int cnt=0;
	int i,j;
	for(i=0;i<len;i++)
	{
		for(j=len-1;j>i;j--)
		{
			if(a[j-1]>a[j])
			{
				cnt++;
				swap(&a[j-1],&a[j]);
				
			}
		}
	}
	printf("the bubble:%d\n",cnt);
}


int main()
{
	int a[]={1,2,5,9,7,3,4,6,12,6,566,87,66,49};
	int len=sizeof(a)/sizeof(a[0]);
//	insertort(a,len);
	
	print(a,len);
	bubble(a,len);
	print(a,len);
}

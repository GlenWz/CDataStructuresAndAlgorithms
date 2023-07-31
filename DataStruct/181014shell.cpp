#include <stdio.h>

void shell(int a[],int len)
{
	int tmp,i,j,k;
	for(i=5;i>0;i=i/2)
	{
		for(j=i;j<len;j+=i)
		{
			tmp=a[j];
			for(k=j;k>=i&&a[k-i]>tmp;k-=i)
			{
				a[k]=a[k-i];
			}
			a[k]=tmp;
		}
	}
}
void prints(int a[],int len)
{
	printf("\n");
	for(int i=0;i<len;i++)
	{
		printf("%d->",a[i]);
	}
}

void del(int a[],int s,int j,int len)
{
	int tmp;
	for(int i=0;i+s<=len;i++)
	{
		tmp=a[s+i];
		a[s+i]=a[j+i];
	}
}




int main()
{
	int a[]={5,8,7,6,13,647,952,123,9722,399,521,3,13,23,65,1};
	int len=sizeof(a)/sizeof(a[0]);
	shell(a,len);
	prints(a,len);
	int i=3,j=8;
	del(a,i,j,len);
	
	prints(a,len-5);
}

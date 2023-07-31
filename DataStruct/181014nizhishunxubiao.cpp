#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Adjust(int a[],int len,int i)
{
	int tmp=a[i];
	for(int j=i*2+1;j<len;j=j*2+1)
	{
		if(j+1<len&&a[j]<a[j+1])
		{
			j++;
		}
		if(tmp<a[j])
		{
			a[i]=a[j];
			i=j;
		}else 
		{
			break;
		}
	}
	a[i]=tmp;
}

void heapsort(int a[],int len)
{
	for(int i=len/2;i>=0;i--)
	{
		Adjust(a,len,i);
	}
	for(int j=len-1;j>0;j--)
	{
		int tmp=a[0];
		a[0]=a[j];
		a[j]=tmp;
		Adjust(a,len,j);
	}
}
void nizhi(int a[],int len)
{
	
	for(int i=0,j=len-1;i<=j;i++,j--)
	{
		int tmp=a[i];
		a[i]=a[j];
		a[j]=tmp;
	}
}
void printt(int a[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d->",a[i]);
	}
}



int main()
{
	int a[]={1,56,1321,456,78,45,65,32,21,542,1235,10,9};
	int len=sizeof(a)/sizeof(a[0]);
	heapsort(a,len);
	printt(a,len);
	printf("\n");
	nizhi(a,len);
	printt(a,len);
}

#include <Stdio.h>

void ShellSort(int a[],int len)
{
	int i,j,n,tmp;
	for(n=6;n>0;n/=2)
	{
		for(i=n;i<len;i+=n)
		{
			tmp=a[i];
			for(j=i;j-n>=0&&a[j-n]>tmp;j-=n)
			{
				a[j]=a[j-n];
			}
			a[j]=tmp;
		}
	}
}
void PrintA(int a[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d->",a[i]);
	}
	printf("\n");
}
int ErFind(int a[],int &len,int x)
{
	int ret=-1;
	int i=0,j=len,h,s;
	for(;i<j;)
	{
		h=(i+j)/2;
		if(a[h]>x)
		{
			j=h;
		}else if(a[h]<x)
		{
			i=h+1;
		}else if(a[h]==x)
		{
			ret=h;
		}
	}
	if(ret==-1)
	{
		for( s=++len;s>j;s--)
		{
			a[s]=a[s-1];
		}
		a[s]=x;
	}
	return ret;
}
void Swap(int a[],int len,int n)
{
	int i,j,tmp;
	for(i=0,j=n;j<len;i++,j++)
	{
		tmp=a[i];
		a[i]=a[j];
		a[j]=tmp;
	}
}


int main()
{
	int a[20]={12,11,10,9,8,7,6,5,4,3,2,1,0,};
	int len=13;
	ShellSort(a,len);/*
	PrintA(a,len);
	int x=22;
	int pos=ErFind(a,len,x);
	printf("%d->\n",pos);
	PrintA(a,len);
	ErFind(a,len,53);
	PrintA(a,len);
	int n=5;*/
	int n=12;
	Swap(a,len,n);
	PrintA(a,len);
}

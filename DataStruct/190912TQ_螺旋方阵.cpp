#include <Stdio.h>
#include <stdlib.h>

void sq(int n,int a[][5])
{
	int i=0,j=0,ret=1,tmp;
	int t;
	if(n%2==0)
	{
		t=n/2;
	}else 
	{
		t=(n)/2+1;
	}
	
	for(i=0;i<t;++i)
	{
		for(j=i;j<n-i;++j)
		{
			a[i][j]=ret;
			ret++;
		}
		for(j=i+1;j<n-i;++j)
		{
			a[j][n-i-1]=ret;
			ret++;
		}
		for(j=n-i-2;j>=i;--j)
		{
			a[n-i-1][j]=ret;
			ret++;
		}
		t++;
		for(j=n-i-2;j>=i+1;--j)
		{
			a[j][i]=ret;
			ret++;
		}
	}
}
void Print(int a[][5],int n)
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}



int main()
{
	int n=5;
/*	printf("please input the n:\n");
	scanf("%d",&n);*/
	int a[5][5];
	sq(n,a);
	Print(a,n);
}

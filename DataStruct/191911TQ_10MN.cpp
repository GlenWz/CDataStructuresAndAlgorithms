#include <Stdio.h>
#include <Stdlib.h>
#define max 5

int WaiWei(int a[][max])
{
	//这样看起来很蠢，分为四部计算，不遍历的主要原因是降低时间复杂度！ 
	
	int ret=0,i;
	for(i=0;i<max;i++)
	{
		ret+=a[0][i];
	}
	for(i=max-1;i>0;i--)
	{
		ret+=a[i][max-1];
	}
	for(i=1;i<max;i++)
	{
		ret+=a[i][0];
	}
	for(i=max-2;i>0;i--)
	{
		ret+=a[max-1][i];
	}
	return ret;
}

int HBXL(int a[][max])
{
	int ret=0,tmp=0,i,j;
	for(i=0;i<max;i++)
	{
		if(i%2==0)
		{
			j=0;
		}else
		{
			j=1;
		}
		for(j;j<max;j+=2)
		{
			ret+=a[i][j];
		}
	}
	return ret;
}
int guantajiaoshane(int a[][max])
{
	int ret=0;
	for(int i=0;i<max;i++)
	{
		ret+=a[i][i];
	}
	for(int i=0,j=max-1;i<max;i++,j--)
	{
		ret+=a[i][j];
	}
	return ret;
}


int main()
{
	int a[max][max];
	
	for(int i=0;i<max;i++)
	{
		for(int j=0;j<max;j++)
		{
			a[i][j]=i*i+1;
		}
	}
	
	for(int i=0;i<max;i++)
	{
		for(int j=0;j<max;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	int waiwei=WaiWei(a);
	printf("the wai wei :%d\n",waiwei);
	int hbxl=HBXL(a);
	int woyebuzhidaojiaosha=guantajiaoshane(a);
	
	printf("this wai wei %d\nthis HBXL:%d\nthis woyebuzhidaojiaosha:%d\n",waiwei,hbxl,woyebuzhidaojiaosha);
	
}











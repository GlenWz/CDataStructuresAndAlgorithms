#include <Stdio.h>
#define size 5

void judgeRow(int a[][size])
{
	int off1,off0;
	for(int i=0;i<size;i++)
	{
		off1=0;
		off0=0;
		for(int j=0;j<size;j++)
		{
			if(a[i][j]==0)
			{
				off0++;
			}else
			{
				off1++;
			}
		}
	}
	if(off1==3)
	{
		printf("the Row 1 win \n");
	}
	if(off0==3)
	{
		printf("the Row 0 win \n");
	}
}
void judgeLine(int a[][size])
{
	int off1,off0;
	for(int i=0;i<size;i++)
	{
		off1=0;
		off0=0;
		for(int j=0;j<size;j++)
		{
			if(a[j][i]==0)
			{
				off0++;
			}else 
			{
				off1++;
			}
		}
	}
	if(off1==size)
	{
		printf("the Line 1 win\n");
	}
	if(off0==size)
	{
		printf("the Line 0 win\n");
	}
}
void judgeDJ(int a[][size])
{
	int off0,off1;
	off0=off1=0;
	for(int i=0;i<size;i++)
	{
		if(a[i][i]==0)
		{
			off0++;
		}else
		{
			off1++;
		}
	}
	if(off1==size)
	{
		printf("the Dj 1 WIN\n");
	}
	if(off0==size)
	{
		printf("the Dj 0 win\n");
	}
}

int main()
{
	int a[size][size]={};
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(i==j)
			{
				a[i][j]=1;
			}else 
			{
				a[i][j]=0;
			}
		}
	}
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	judgeRow(a);
	judgeLine(a);
	judgeDJ(a);
}

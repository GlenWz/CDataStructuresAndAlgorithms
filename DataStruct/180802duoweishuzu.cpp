#include <stdio.h>

int main()
{
	int a[4][4]={};
	int x=1;int y=1;
	for(int i=0;i<4;i++,x+=2)
	{
		for(int j=0;j<4;j++,y+=2)
		{
			a[i][j]=y;
		}
	}

	int b[4][4]={};
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			b[i][j]=a[j][i];
		}
	}
		
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			printf("%d\t",b[i][j]);
			if(j==3)
			{
				printf("\n");
			}
		}
	}
	
	int ab[4][4]={};
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			ab[i][j]=a[i][j]+b[i][j];
		}
	}
	printf("--------------------end\n");
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			printf("%d\t",ab[i][j]);
			if(j==3)
			{
				printf("\n");
			}
		}
	}
	
}

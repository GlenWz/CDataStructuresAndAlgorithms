#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[5][5]={};
	for(int  i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			str[i][j]='s';
			str[i][j]=str[i][j]+i;		}
	}
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			printf("%c\t",str[i][j]);
			if(j==4)
			{
				printf("\n");
			}
		}
	}
}

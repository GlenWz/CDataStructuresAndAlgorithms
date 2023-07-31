#include <Stdio.h>
#include <Stdlib.h>

void Max(int polygon[3][4])
{
	int max=0;
	int x=0,y=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(polygon[i][j]>max)
			{
				max=polygon[i][j];
				x=i;
				y=j;
			}
		}
	}
	printf("the Max %d position is %d %d",max,x,y);
}



int main()
{
	int polygon[3][4]={};
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			polygon[i][j]=i*j;
		}
	}
	Max(polygon);
}

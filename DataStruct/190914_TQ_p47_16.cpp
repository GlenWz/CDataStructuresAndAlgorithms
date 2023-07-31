#include <stdio.h>
#include <stdlib.h>
#define num 5

int POS(int x,int y,int aa[])
{
	int tmp=5,ret=0,i=0,sum=0;
	if(y<x||x>=num||y>=num)
	{
		printf("the num is not exist!\n");
		return -1;
	}
	for(i=0;i<x;i++)
	{
		sum+=tmp;
		tmp--;
	}
	sum=sum+(y-x)-1;
	ret=sum;
	return ret;
}

int main()
{
	int a[num][num];
	int tmp,i,j,k=0;
	int AA[25];
	for(i=0;i<num;i++)
	{
		for(j=0,tmp=i;j<num;j++)
		{
			if(j!=tmp)
			{
				a[i][j]=0;
			}else 
			{
				a[i][j]=k+1;
				AA[k++]=k+1;
				tmp++;
			}
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	int x,y;
	printf("please input the x and y\n");
	scanf("%d%d",&x,&y);
	int pos=POS(x,y,AA);
	if(pos!=-1)
	{
		printf("the POS is %d\tvalues:%d\n",pos,AA[pos]);
	}
}

#include <stdio.h>

int search(int len,int a[],int x)
{
	int ret=-1;
	for(int i=0;i<len;i++)
	{
		if(x==a[i])
		{
			ret=i;
		}
	}
	return ret;
}



int main()
{
	int a[]={1,3,5,7,9,11,13,2,14,15,17,19,21,25,};
	int len=sizeof(a)/sizeof(a[0]);
	int x;
	printf("please input the num:\n");
	scanf("%d",&x);
	int pos=search(len,a,x);
	if(pos==-1)
	{
		printf("NO exist!");
	}else 
	{
		printf("the num of position is %d \n",pos);
	}
	
}

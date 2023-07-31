#include <stdio.h>

int erfen(int x,int Y,int a[])
{
	int ret=-1;
	int mid;
	int R=Y-1; int L=0;
	while(R>L)
	{
		mid=(R+L)/2;
		if(a[mid]==x)
		{
			ret=mid;
			break;
		}
		else if(a[mid]>x)
		{
			R=mid-1;
		}
		else
		{
			L=mid+1;
		}
	}
	return ret;
}

int main()
{
	int a[]={1,2,3,4,5,6,8,9,12,15,18,20,23,28,30,39,46,58,68,78,86,99,};
	int l,x,q;
	printf("shuru x de zhi");
	scanf("%d",&x);
	l=sizeof(a)/sizeof(a[0]);
	q=erfen(x,sizeof(a)/sizeof(a[0]),a);
	printf("----- %d --\n",q);
	
	return 0;
}

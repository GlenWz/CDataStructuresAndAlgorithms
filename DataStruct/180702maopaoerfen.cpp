#include <stdio.h>


void swap(int *px,int *py)
{
	int j=*px;
	*px=*py;
	*py=j;
}

void maopao(int a[],int length)
{
	int i,j;
	for(i=0;i<length;i++)
	{
	//	printf("size=%d\n",sizeof(a)/sizeof(a[0]));
		for(j=length-1;j>i;j--)
		{
			if(a[j-1]>a[j])
			{
				swap(&a[j-1],&a[j]);
			}
		}
	}
/*	for(int i=0;i<length;i++)
	{
		printf("ai=%d\n",a[i]);
	} */
}

int erfen(int a[],int x,int length)
{
	int len,L,R;
	int ret=-1;
	R=length-1;
	L=0;
	int mid;
	while(R>L)
	{
		mid=R+L/2;
		if(a[mid]==x)
		{
			ret=mid;
			return ret;
			break;
		}
		else if(a[mid]<x)
		{
			L=mid+1;
		}
		else
		{
			R=mid-1;
		}
	}
	return ret;
}





int main()
{
	int x;
	int a[]={1,5,6,8,9,3,7,6,9,33,5,8,6,1,3,79,9,6,75,15,87,65,32,23,45,68,46,17,};
	int length=sizeof(a)/sizeof(a[0]);
	maopao(a,length);
	scanf("%d",&x);
	int j=erfen(a,x,length);

	printf("%d\n",j);
	return 0;
	
}


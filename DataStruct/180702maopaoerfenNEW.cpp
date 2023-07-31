#include <stdio.h>
void swap(int *px,int *py);

void maop(int a[],int len)
{
	for(int i=0;i<len;i++)
	{
		for(int j=len-1;j>i;j--)
		{
			if(a[j-1]>a[j])
			{
				swap(&a[j-1],&a[j]);
			}
		}
	}
}

void swap(int *px,int *py)
{
	int j=*px;
	*px=*py;
	*py=j;
}

int erfen(int a[],int x,int len)
{
	int R,L,mid;
	int ret=-1;
	R=len-1;L=0;
	while(R>L)
	{
		mid=R+L/2;
		if(a[mid]==x)
		{
			ret=mid;
			break;
		}else if(a[mid]>x)
		{
			R=mid-1;
		}
		else{
			L=mid+1;
		}
	}
	return ret;
}



int main()
{
	int a[]={1,5,6,8,9,3,7,6,9,33,5,8,6,1,3,79,9,6,75,15,87,65,32,23,45,68,46,17,};
	int len=sizeof(a)/sizeof(a[0]);
	int x,RET;
	printf("qingshuru cha zhao de shu zi");
	scanf("%d",&x);
	maop(a,len);
	RET=erfen(a,x,len);
	printf("%d\n",RET);
	for(int i=0;i<len;i++)
	{
		printf("a=%d\t",a[i]);
	}
	return 0;
	
	
}

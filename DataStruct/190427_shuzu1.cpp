#include <Stdio.h>

void swap(int *a,int *b)
{
	int j=*a;
	*a=*b;
	*b=j;
}

int *PAIXU(int a[],int len)
{
	for(int i=0;i<len;i++)
	{
		for(int  j=0;j<len;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(&a[j],&a[j+1]);
			}
		}
	}
	for(int i=0;i<len;i++)
	{
		printf("%d\t",a[i]);
	}
	return a;
}
int Search(int *a,int len,int x)
{
	int ret=-1;
	for(int i=0;i<len;i++)
	{
		if(a[i]==x)
		{
			ret=i;
		}
	}
	return ret;
}


int main()
{
	int a[]={5,1,7,9,3,2,18,122,12,135,149,133,179,20,123,};
	int *aa=PAIXU(a,sizeof(a)/sizeof(a[0]));
	int x;
	printf("please input:\n");
	scanf("%d",&x);
	int pos=Search(aa,sizeof(a)/sizeof(a[0]),x);
	if(pos==-1)
	{
		printf("NO EXIST!\n");
	}else 
	{
		printf("\nthe position is %d\n",pos);
	}
}

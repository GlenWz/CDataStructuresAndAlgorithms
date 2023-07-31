#include <Stdio.h>

void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

void Bubble_Sort(int *a,int len)
{
	int flag;
	for(int i=len-1;i>=0;i--)
	{
		flag=0;
		for(int j=0;j<i;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j],&a[j+1]);
				flag=1;
			}
		}
		if(flag==0)
		{
			break;
		}
	}
}
void Print(int *a,int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d\t",a[i]);
	}
}


int main()
{
	int a[]={9,8,7,6,5,4,3,2,1,0};
	int len=sizeof(a)/sizeof(a[0]);
	Bubble_Sort(a,len);
	Print(a,len);
}

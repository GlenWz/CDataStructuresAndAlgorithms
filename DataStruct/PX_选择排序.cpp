#include <Stdio.h>

int FindMin(int a[],int j,int len)
{
	int tmp,min;
	tmp=a[j];
	min=j;
	for(int i=j;i<len;i++)
	{
		if(tmp>a[i])
		{
			tmp=a[i];
			min=i;
		}
	}
	return min;
}

void Swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}


void Selection(int a[],int len)
{
	int i,MinPosition;
	for(i=0;i<len;i++)
	{
		MinPosition=FindMin(a,i,len);
		Swap(&a[i],&a[MinPosition]);
	}
}
void Print(int a[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d->",a[i]);
	}
	printf("\n");
}


int main()
{
	int a[]={1,5,6,8,96,66,32,12,56,23,542,866,789,13};
	int len=sizeof(a)/sizeof(a[0]);
	Selection(a,len);
	Print(a,len);
}

#include <Stdio.h>
#include <stdlib.h>

int FindMin(int a[],int i,int len)
{
	int tmp,minpos;
	tmp=a[i];
	minpos=i;
	for(i;i<=len;i++)
	{
		if(a[i]<tmp)
		{
			tmp=a[i];
			minpos=i;
		}
	}
	return minpos;
}
void Swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

void Selection(int a[],int len)
{
	int MinPos;
	for(int i=0;i<len;i++)
	{
		MinPos=FindMin(a,i,len-1);
		Swap(&a[i],&a[MinPos]);
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
	int a[]={5,78,123,456,78,45,66,33,21,12,20,1};
	int len=sizeof(a)/sizeof(a[0]);
	Selection(a,len);	
	Print(a,len);
}







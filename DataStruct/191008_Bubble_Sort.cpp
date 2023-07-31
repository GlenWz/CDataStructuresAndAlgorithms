#include <Stdio.h>
#include <Stdlib.h>

void Swap(int *a,int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}

void Bubble(int a[],int N)
{
	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if(a[i]>a[j])
			{
				Swap(&a[i],&a[j]);
			}
		}
	}
}
void Print(int a[],int N)
{
	for(int i=0;i<N;i++)
	{
		printf("%d->",a[i]);
	}
	printf("\n");
}

int main()
{
	int a[]={10,8,15,1,5,9,3,5,7,8,5,2,6,5,4,1,0,12,1,335,36,69,64,21,75,23,10,102,};
	int N=sizeof(a)/sizeof(a[0]);
	Bubble(a,N);
	Print(a,N);	
}

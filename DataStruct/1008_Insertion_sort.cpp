#include <Stdio.h>
#include <Stdlib.h>

void Insertion_Sort(int a[],int N)
{
	int tmp,p,i;
	for(p=1;p<N;p++)
	{
		tmp=a[p];
		for(i=p;i>0&&a[i-1]>tmp;i--)
		{
			a[i]=a[i-1];
		}
		a[i]=tmp;
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
	Insertion_Sort(a,N);
	Print(a,N);
}

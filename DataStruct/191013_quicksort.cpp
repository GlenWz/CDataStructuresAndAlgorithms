#include <Stdio.h>

void Quick_Sort(int a[],int left,int right)
{
	if(left>=right)
	{
		return;
	}
	int i,j;
	i=left;
	j=right;
	int tmp=a[i];
	while(i<j)
	{
		while(i<j&&a[j]>=tmp)
		{
			j--;
		}
		a[i]=a[j];
		while(i<j&&a[i]<=tmp)
		{
			i++;
		}
		a[j]=a[i];
	}	
	a[i]=tmp;
	Quick_Sort(a,left,i-1);
	Quick_Sort(a,i+1,right);
}

void Quick_sort(int a[],int N)
{
	int left,right;
	left=0,right=N-1;
	Quick_Sort(a,left,right);
}
void Print(int a[],int N)
{
	for(int i=0;i<N;i++)
	{
		printf("%d->",a[i]);
	}
}
int main()
{
	int a[]={456,12,32,21,20,159,362,201,1,3,5,46,6};
	int N=sizeof(a)/sizeof(a[0]);
	Quick_sort(a,N);
	Print(a,N);
}





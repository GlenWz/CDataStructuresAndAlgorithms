#include <Stdio.h>
#include <stdlib.h>

void QuickSort(int a[],int left,int right)
{
	if(left>=right)
	{
		return;
	}
	int l,r;
	l=left;
	r=right;
	int key=a[l];
	while(l<r)
	{
		while(l<r&&a[r]>=key)
		{
			r--;
		}
		a[l]=a[r];
		while(l<r&&a[l]<=key)
		{
			l++;
		}
		a[r]=a[l];
	}
	a[l]=key;
	QuickSort(a,left,l-1);
	QuickSort(a,l+1,right);
}

void Quick(int a[],int N)
{
	int left=0;
	int right=N-1;
	QuickSort(a,left,right);
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
	int a[]={456,31,45,78,1,54,78,9,20};
	int N=sizeof(a)/sizeof(a[0]);
	Quick(a,N);
	Print(a,N);
}

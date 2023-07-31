#include <Stdio.h>
#include <Stdlib.h>

void QuickSort(int a[],int left,int right)
{
	if(left>=right)
	{
		return;
	}
	int i=left,j=right;
	int key=a[left];
	while(i<j)
	{
		while(i<j&&key<=a[j])
		{
			j--;
		}
		a[i]=a[j];
		while(i<j&&key>=a[i])
		{
			i++;
		}
		a[j]=a[i];
	}
	a[i]=key;
	QuickSort(a,left,i-1);
	QuickSort(a,i+1,right);
}




void Quick_sort(int a[],int N)
{
	int left=0,right=N-1;
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
	int a[]={10,2,5,3,9,7,5,6,10,25,36,8};
	int N=sizeof(a)/sizeof(a[0]);
	Quick_sort(a,N);
	Print(a,N);
} 
 
 
 
 
 
 
 
 

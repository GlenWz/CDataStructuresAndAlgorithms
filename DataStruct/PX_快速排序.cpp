#include <Stdio.h>

void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

int Median3(int a[],int L,int R)
{
	int center=(L+R)/2;
	int tmp;
//	printf("L:%d  R:%d   center:%d\n",L,R,center);
	if(a[L]>a[center])
	{
		tmp=a[L];
		a[L]=a[center];
		a[center]=tmp;
	}
	if(a[L]>a[R])
	{
		tmp=a[L];
		a[L]=a[R];
		a[R]=tmp;
	}
	if(a[center]>a[R])
	{
		tmp=a[center];
		a[center]=a[R];
		a[R]=tmp;
	}
	swap(&a[center],&a[R-1]);
	printf("%d\n",a[R-1]);
	return (a[R-1]);
}

void Quick_sort(int a[],int L,int right)
{
	int pivot;
	pivot=Median3(a,L,right);
//	printf("pivot:%d\tL:%d\tR:%d\n",pivot,L,right);
	int i,j;
	i=L;
	j=right-1;
	while(1)
	{
		while(a[++i]<pivot);
		while(a[--j]>pivot);
		if(i<j)
		{
			swap(&a[i],&a[j]);
		}else 
		{
			break;
		}
	}
	swap(&a[i],&a[right-1]);
	Quick_sort(a,L,i-1);
	Quick_sort(a,i+1,right);
}
void QuickSort(int a[],int len)
{
	Quick_sort(a,0,len-1);
}
void PrintQ(int a[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d->",a[i]);
	}
	printf("\n");
}

int main()
{
	int a[]={123,12,2,345,45,1,7,89,3,20,69,6,8};
	int len=sizeof(a)/sizeof(a[0]);
	printf("Len:%d\n",len);
	QuickSort(a,len-1);
	PrintQ(a,len);
}

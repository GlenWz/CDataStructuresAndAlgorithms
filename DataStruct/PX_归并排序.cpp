#include <Stdio.h>
#include <Stdlib.h>
#include <time.h>
void Merge_1(int a[],int tmpa[],int L,int R,int rightend)
{
	int leftend=R-1;
	int NumEle=rightend-L+1;
	int Tmp=L;
	while(L<=leftend&&R<=rightend)
	{
		if(a[L]<=a[R])
		{
			tmpa[Tmp++]=a[L++];
		}else 
		{
			tmpa[Tmp++]=a[R++];
		}
	}
	while(L<=leftend)
	{
		tmpa[Tmp++]=a[L++];
	}
	while(R<=rightend)
	{
		tmpa[Tmp++]=a[R++];
	}
	for(int i=0;i<NumEle;i++,rightend--)
	{
		a[rightend]=tmpa[rightend];
	}
}

void MSort(int a[],int tmpa[],int L,int rightend)
{
	int center;
	if(L<rightend)
	{
		center=(L+rightend)/2;
		MSort(a,tmpa,L,center);
		MSort(a,tmpa,center+1,rightend);
		Merge_1(a,tmpa,L,center+1,rightend);
	}
}

void Merge_sort1(int a[],int len)
{
	int *tmpa;
	tmpa=(int *)malloc(sizeof(int)*len);
	if(tmpa!=NULL)
	{
		MSort(a,tmpa,0,len-1);
		free(tmpa);
	}else 
	{
		printf("kong jian buzu !\n");
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

	int b[]={45,1,12,332,456,78,2,12,54,6,9,789,12,321,465,9,1};
	int len=sizeof(b)/sizeof(b[0]);
	Merge_sort1(b,len);
	Print(b,len);
	
}







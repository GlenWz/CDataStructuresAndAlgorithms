#include <stdio.h>
#define nub 5

void swap(int *px,int *py)
{
	int temp=*px;
	*px=*py;
	*py=temp;
}
void bsort(int a[],int n)
{
	int i,j;
	n=sizeof(a)/sizeof(a[0]);
	for(i=0;i<n-1;i++)
	{
		for(j=4;j>i;j--)
		{
			if(a[j-1]>a[j])
			{
				swap(&a[j],&a[j-1]);
			}	
		}
	}
}
int main()
{
	int i;
	int point[nub];
	printf("请输入%d分数\n",nub);
	for(i=0;i<nub;i++)
	{
		printf("%2d号:",i+1);
		scanf("%d",&point[i]);
	}
	bsort(point,nub);
	puts("按升序排列：");
	for(i=0;i<nub;i++)
	{
		printf("%2d号：%d\n",i+1,point[i]);
	}
	return 0;
}

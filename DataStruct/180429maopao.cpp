#include <stdio.h>
#define nub 5

void swap(int *px,int *py)
{
	int j=*px;
	*px=*py;
	*py=j;
}
void bsort(int p[],int n)
{
	int j,i;
//	n=sizeof(a)/sizeof(a[0]);
	for(i=0;i<n-1;i++)
	{
		for(j=n-1;j>i;j--)
		{
			if(p[j-1]>p[j])
			{
				swap(&p[j],&p[j-1]);
			}
		}
	}
}

int main()
{
	int i;
	int a[nub];
	printf("q请输入%d人的分数：\n",nub);
	for(i=0;i<nub;i++)
	{
		printf("%2d号：",i+1);
		scanf("%d",&a[i]);
	}
	bsort(a,nub);
	puts("按升序排列：");
	for(i=0;i<nub;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
	
 } 

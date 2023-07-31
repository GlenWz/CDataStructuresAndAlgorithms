#include <stdio.h>
#define nub 5

void swap(int *px,int *py)
{
	int j=*px;
	*px=*py;
	*py=j;
}

void bsort(int a[])
{
	int j,i;
	for(i=0;i<sizeof(a)/sizeof(a[0])-1;i++)
	{
		for((j=sizeof(a)/sizeof(a[0]))-1;j>i;j--)
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
	int a[nub];
	int i;
	for(i=0;i<nub;i++)
	{
		printf("ÇëÊäÈë·ÖÊý£º\n");
		scanf("%d",&a[i]);
	}
	bsort(a); 
	puts("paixushi");
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
	{
		printf("%d",a[i]);
	} 
	return 0;
}





#include <stdio.h>
#define nub 5

void swap(int *px,int *py)
{
	int j=*px;
	*px=*py;
	*py=j;
	
}
void dsort(int a[])
{
	int i,j;
	for(i=0;i<sizeof(a)/sizeof(a[0])-1;i++)
	{
		for((j=sizeof(a)/sizeof(a[0]))-2;j>i;j--)
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
	printf("ÇëÊäÈëÊı×Ö£º");
	for(int i=0;i<nub;i++)
	{
		scanf("%d",&a[i]);
	}
	dsort(a);
	puts("°´ÕÕÉıĞòÅÅĞò");
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
	{
		printf("%d",a[i]);
	 } 
	return 0;
}

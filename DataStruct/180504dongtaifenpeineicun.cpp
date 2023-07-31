#include <stdio.h>
#include <stdlib.h> 
//动态分配内存 
int main()
{
	int nub;
	int i=0;
	int *a;
//	int a[nub];
	printf("输入数量：");
	scanf("%d",&nub); 
	a=(int*)malloc(nub*sizeof(int));
	for(int i=0;i<nub-1;i++)
	{
		scanf("%d",&a[i]); 
	} 
	int *s=&a[0];
	for(i=0;i<nub;i++)
	{
		printf("%d",*s++);
	}
	free(a);
	return 0;
	
}

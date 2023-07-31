#include <Stdio.h>

int main()
{
	int i,j,n;
	int a[6]={1,2,3,5,6};
	n=sizeof(a)/sizeof(a[0]);
	printf("please input the number of insert \n %d \n",n);
	scanf("%d",&j);
	for(i=6;i>2;i--)
	{
		a[i+1]=a[i];
	}
	a[3]=4;
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}

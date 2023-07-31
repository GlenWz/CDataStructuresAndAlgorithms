#include <Stdio.h>
//charu
int main()
{
	int n,j,x,i;
	int a[6]={1,2,3,4,6,};
	j=sizeof(a)/sizeof(a[0]);
	printf("please input the value of location and the value of insertion\n");
	scanf("%d %d",&n,&x);
	if((n>sizeof(a)/sizeof(a[0]))||n<0)   
	{
		printf("the value of location is error");
	}
	else
	{
		printf("s1=%d\n",sizeof(a)/sizeof(a[0]));
		for(i=j+1;i>n;i--)
		{
			a[i]=a[i-1];
		}
		a[n]=x;
	}
	for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
	{
		printf("%d\t",a[i]);
	}
	printf("s2=%d\n",sizeof(a)/sizeof(a[0]));
	return 0;
	
}

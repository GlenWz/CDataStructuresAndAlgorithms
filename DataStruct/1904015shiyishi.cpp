#include <Stdio.h>

int main()
{
	int a[100]={1,};
	int p,i;
	int sum=0;
	double avg;
	for(i=0;p!=-1;i++)
	{
		scanf("%d",&p);
		a[i]=p;
		sum+=a[i];
	}
	printf("sum=%d:\n",sum);
	avg=(1.0*sum+1)/(i-1);
	printf("I=%d\n",i);
	for(i=0;a[i]!=-1;i++)
	{
		if(a[i]>avg)
		{
			printf("%d\t",a[i]);
		}
	}
	printf("the avg is :%lf\n",avg);
	
	

	
}

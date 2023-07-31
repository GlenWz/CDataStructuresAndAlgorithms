#include <Stdio.h>

void Jc()
{
	int j=1;
	int sum=0;
	int jc=1;
	for(int i=0;i<10;i++)
	{
		for(int k=1;k<=j;k++)
		{
			jc*=k;
		}
		sum+=jc;
		printf("%d\t%d\n",sum,jc);
		j++;
		jc=1;
	}
	printf("%d",sum);
}



int main()
{
	int j=1;
	int sum=0;
	int jc=1;
	for(int i=1;i<11;i++)
	{
		jc*=i;
		sum+=jc;
		if(i!=10)
		{
			sum+=sum;
		}
		
	}
	
	Jc();
	printf("\n");
	printf("%d\t",sum);
}

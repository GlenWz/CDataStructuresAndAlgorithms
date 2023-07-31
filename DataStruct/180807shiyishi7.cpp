#include <stdio.h>

void swap(int a[])
{
	int min,max,tmp;
	min=max=a[0];
	for(int i=0;i<10;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
		
		if(a[i]<min)
		{
			min=a[i];
		}
	}
	for(int i=0;i<10;i++)
	{
		if(a[i]==max)
		{
			tmp=a[9];
			a[9]=a[i];
			a[i]=tmp;
		}
		
		if(a[i]==min)
		{
			tmp=a[0];
			a[0]=a[i];
			a[i]=tmp;
		}
	}
	for(int i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
	}
}



int main()
{
	int a[10]={9,2,5,4,6,7,9,2,1,5};
	swap(a);
}

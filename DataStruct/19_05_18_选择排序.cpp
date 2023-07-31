#include <Stdio.h>
#define len 10

int *sort(int *a)
{
	int i=0,p=0,min,tmp;
	for(i;i<len;)
	{
		for(int j=p;j<len;j++)
		{
			min=a[i];
			if(a[j]<min)
			{
				min=a[j];
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
		i++;
		p++;
	}
	return a;
}
void print(int *a)
{
	for(int i=0;i<len;i++)
	{
		printf("%d\t",a[i]);
	}
}

int main()
{
	int a[len]={};
	int j=10;
	for(int i=0;i<len;i++)
	{
		a[i]=j*j;
		j--;
	}
	print(a);
	int *aa=sort(a);

	printf("\n");
	print(aa);
}

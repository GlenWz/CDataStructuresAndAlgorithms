#include <Stdio.h>

void shell(int a[],int len)
{
	int tmp,i;
	for(int d=11;d>0;d/=2)
	{
		for(int p=1;p<len;p++)
		{
			tmp=a[p];
			for(i=p;i>0&&a[i-1]>tmp;i--)
			{
				a[i]=a[i-1];
			}
			a[i]=tmp;
		}
	}
	
}
void print(int a[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d\t",a[i]);
	}
}



int main()
{
	int a[]={789,454,12,45,678,42,32,54,5,8,7,93,21,10,20,43,23,45};
	int len=sizeof(a)/sizeof(a[0]);
	shell(a,len);
	print(a,len);
}

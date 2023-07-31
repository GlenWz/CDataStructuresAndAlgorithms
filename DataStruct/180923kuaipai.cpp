#include <Stdio.h>

void quicksort(int a[],int num,int len)
{
	int i=num;
	int j=len;
	int temp=a[num];
	while(i<j)
	{
		while(a[j]>=temp&&j>i)
		{
			j--;
		}
		if(j>i)
		{
			a[i]=a[j];
			i++;
			while(a[i]<temp&&i<j)
			{
				i++;
			}
			if(i<j)
			{
				a[j]=a[i];
				j--;
			}
		}
	}
	a[i]=temp;
	if(num<(i-1))
	{
		quicksort(a,num,i-1);
	}
	if((j+1)<len)
	{
		quicksort(a,j+1,len);
	}
}
void print(int len,int data[])
{
	for(int i=0;i<len;i++)
	{
		printf("%d\t",data[i]);
	}
}

int main()
{
	int data[]={5,7,9,33,21,54,27,1,123,458,956,120};
	int len=sizeof(data)/sizeof(data[0]);
	quicksort(data,0,len-1);
	print(len,data);
	
}

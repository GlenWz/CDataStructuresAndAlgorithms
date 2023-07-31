#include <stdio.h>

void Adjust(int j,int len,int data[])
{
	int tmp=data[j];
	for(int k=j*2+1;k<len;k=k*2+1)
	{
		if(k+1<len&&data[k]<data[k+1])
		{
			k++;
		}
		if(data[k]<tmp)
		{
			break;
		}else 
		{
			data[j]=data[k];
			j=k;
		}
	}
	data[j]=tmp;
}

void heapsort(int len,int data[])
{
	for(int i=len/2-1;i>0;i--)
	{
		Adjust(i,len,data);
	}
	for(int j=len-1;j>0;j--)
	{
		int tmp=data[0];
		data[0]=data[j];
		data[j]=tmp;
		Adjust(0,j,data);
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
	int a[]={5,8,9,3,7,64,52,31,123,654,97,753,62,210,359,67,642,398,751,23};
	int len=sizeof(a)/sizeof(a[0]);
	heapsort(len,a);
	print(len,a);
}

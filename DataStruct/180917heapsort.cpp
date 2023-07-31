#include <stdio.h>

void Adjustheap(int par,int len,int data[])
{
	int temp=data[par];
	for(int k=par*2+1;k<len;k=k*2+1)
	{
		if(k+1<len&&data[k]<data[k+1])
		{
			k++;
		}
		if(data[k]>temp)
		{
			data[par]=data[k];
			par=k;
		}else 
		{
			break;
		}
	}
	data[par]=temp;
}

void heapsort(int len,int data[])
{
	for(int i=len/2-1;i>=0;i--)
	{
		Adjustheap(i,len,data);
	}
	for(int j=len-1;j>0;j--)
	{
		int temp=data[0];
		data[0]=data[j];
		data[j]=temp;
		Adjustheap(0,j,data);
	}
}
void print(int len,int data[])
{
	for(int i=0;i<len;i++)
	{
		printf("%d->",data[i]);
	}
}

int main()
{
	int data[]={9,7,3,6,4,1,52,35,68,94,12,32,24,25,36,60,18,5,8,9,123,456,789,987,654,321,213,546,71,25,53,97,99,930,390};
	int len=sizeof(data)/sizeof(data[0]);
	heapsort(len,data);
	print(len,data);
	return 0;
}

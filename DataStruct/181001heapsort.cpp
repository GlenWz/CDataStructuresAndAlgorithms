#include <stdio.h>

void Adjustheap(int i,int len,int data[])
{
	int tmp=data[i];
	for(int j=i*2+1;j<len;j=j*2+1)
	{
		if(j+1<len&&data[j+1]>data[j])
		{
			j++;
		}
		if(data[j]>tmp)
		{
			data[i]=data[j];
			i=j;
		}else 
		{
			break;
		}
	}
	data[i]=tmp;
}

void heapsort(int data[],int len)
{
	for(int i=len/2;i>=0;i--)
	{
		Adjustheap(i,len,data);
	}
	for(int j=len-1;j>0;j--)
	{
		int  tmp=data[0];
		data[0]=data[j];
		data[j]=tmp;
		Adjustheap(0,j,data);
	}
}

void print(int data[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d\t",data[i]);
	}
}

int main()
{
	int data[]={5,9,6,36,369,98,41,20,30,10,1,2,3,99};
	int len=sizeof(data)/sizeof(data[0]);
	heapsort(data,len);
	print(data,len);
}

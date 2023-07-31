#include <stdio.h>

void Adjust(int i,int len,int data[])
{
	int tmp=data[i];
	for(int k=i*2+1;k<len;k=k*2+1)
	{
		if(k+1<len&&data[k+1]>data[k])
		{
			k++;
		}
		if(data[k]>tmp)
		{
			data[i]=data[k];
			i=k;
		}else 
		{
			break;
		}
		
	}
	data[i]=tmp;
}

void heapsort(int len,int data[])
{
	for(int i=len/2-1;i>=0;i--)
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
void print(int data[],int  len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d\t",data[i]);
	}
}




int main()
{
	int data[]={5,7,9,8,6,32,65,91,23,57,5668,66,466,50};
	int len=sizeof(data)/sizeof(data[0]);
	heapsort(len,data);
	print(data,len);
}



#include <stdio.h>

void Adjust(int i,int len,int data[])
{
	int tmp,j;
	tmp=data[i];
	for(j=i*2+1;j<len;j=j*2+1)
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
	for(int i=len/2-1;i>=0;i--)
	{
		Adjust(i,len,data);
	}
	for(int j=len-1;j>0;j--)
	{
		int tmp=data[j];
		data[j]=data[0];
		data[0]=tmp;
		Adjust(0,j,data);
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
	int data[]={8,7,9,62,30,10,52,61,72,300,87,999,123,510,71};
	int len=sizeof(data)/sizeof(data[0]);
	heapsort(data,len);
	print(data,len);
}

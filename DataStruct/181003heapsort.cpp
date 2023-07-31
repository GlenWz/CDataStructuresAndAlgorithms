#include <Stdio.h>
#define MAXSIZE 100

void Adjustheap(int i,int len,int data[])
{
	int tmp;
	tmp=data[i];
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




void heapsort(int data[],int len)
{
	for(int i=len/2;i>=0;i--)
	{
		Adjustheap(i,len,data);
	}
	for(int j=len-1;j>0;j--)
	{
		int tmp=data[0];
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
	int data[]={5,7,9,3,6,41,20,10,358,96,321,123,102,1};
	int len=sizeof(data)/sizeof(data[0]);
	heapsort(data,len);	
	print(data,len);
}

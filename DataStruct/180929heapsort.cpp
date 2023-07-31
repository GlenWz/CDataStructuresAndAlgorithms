#include <Stdio.h>

void ADJUST(int par,int len,int data[])
{
	int tmp=data[par];
	for(int k=par*2+1;k<len;k=k*2+1)
	{
		if(k+1<len&&data[k+1]>data[k])
		{
			k++;
		}
		if(data[k]>tmp)
		{
			data[par]=data[k];
			par=k;
		}else 
		{
			break;
		}
	}
	data[par]=tmp;
}

void heapsoort(int data[],int len)
{
	for(int i=len/2;i>=0;i--)
	{
		ADJUST(i,len,data);
	}
	for(int j=len-1;j>=0;j--)
	{
		int tmp=data[0];
		data[0]=data[j];
		data[j]=tmp;
		ADJUST(0,j,data);
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
	int data[]={1,2,99,68,32,12,35,74,10,20,30,62,0,1259,7};
	int len=sizeof(data)/sizeof(data[0]);
	heapsoort(data,len);
	print(data,len);
}

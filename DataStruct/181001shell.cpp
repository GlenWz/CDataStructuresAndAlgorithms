#include <Stdio.h>

void shell(int data[],int len)
{
	int tmp,i,d,p;
	for(d=5;d>0;d=d/2)
	{
		for(p=d;p<len;p+=d)
		{
			tmp=data[p];
			for(i=p;data[i-d]>tmp&&i>0;i-=d)
			{
				data[i]=data[i-d];
			}
			data[i]=tmp;
		}
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
	int data[]={5,8,93,64,2,20,35,12,30,963,3};
	int len=sizeof(data)/sizeof(data[0]);
	shell(data,len);
	print(data,len);
}

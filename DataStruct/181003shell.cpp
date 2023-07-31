#include <Stdio.h>
#define MAXSIZE 100

void shell(int data[],int len)
{
	int tmp,i,d,p;
	for(d=5;d>0;d/=2)
	{
		for(p=d;p<len;p+=d)
		{
			tmp=data[p];
			for(i=p;i>0&&data[i-d]>tmp;i-=d)
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
	int data[]={5,9,8,7,6,223,6544,23,1};
	int len=sizeof(data)/sizeof(data[0]);
	shell(data,len);
	print(data,len);
}

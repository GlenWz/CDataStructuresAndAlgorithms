#include <Stdio.h>

void shell(int data[],int len)
{
	int d,i,p,tmp;
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
	int data[]={1,5,9,8,6,3,2,1,0,11,22,59,36,75,311,120,2};
	int len=sizeof(data)/sizeof(data[0]);
	shell(data,len);
	print(data,len);
}

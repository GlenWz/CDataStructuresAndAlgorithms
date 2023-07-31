#include <stdio.h>

void shell(int len,int data[])
{
	int tmp,i,p,d;
	for(d=5;d>0;d/=2)
	{
		for(p=d;p<len;p+=d)
		{
			tmp=data[p];
			for(i=p;i>=d&&data[i-1]>tmp;i-=d)
			{
				data[i]=data[i-1];
			}
			data[i]=tmp;
		}
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
	int data[]={5,1,2,33,65,98,75,96,32,20,10,15,3,9,26,37,28,29,333,222,11,226};
	int len=sizeof(data)/sizeof(data[0]);
	shell(len,data);
	print(len,data);
}

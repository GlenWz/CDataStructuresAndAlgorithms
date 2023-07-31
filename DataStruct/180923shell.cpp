#include <stdio.h>

void shell(int len,int data[])
{
	int tmp,i,p,d;
	for(d=5;d>0;d=d/2)
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
void print(int len,int data[])
{
	for(int i=0;i<len;i++)
	{
		printf("%d\t",data[i]);
	}
}



int main()
{
	int data[]={5,8,9,6,7,6,3,1,2,59,6,42,31,46,697,56,};
	int len=sizeof(data)/sizeof(data[0]);
	shell(len,data);
	print(len,data);
}

#include <stdio.h>

void shell(int len,int data[])
{
	int tmp,i;
	int cnt=0;
	for(int d=11;d>0;d/=2)
	{
		for(int p=1;p<len;p++)
		{
			tmp=data[p];
			for(i=p;i>0&&data[i-1]>tmp;i--)
			{
				data[i]=data[i-1];
				++cnt;
			}
			data[i]=tmp;
		}
	}
	printf("%d\n",cnt);
}
void print(int len,int data[])
{
	for(int i=0;i<len;i++)
	{
		printf("%d->",data[i]);
	}
}






int main()
{
	int data[]={5,9,3,4,6,13,23,31,89,67,52,364,213,546,97,51,62,94,87,93,50,100,212};
	int len=sizeof(data)/sizeof(data[0]);
	shell(len,data);
	print(len,data);
}

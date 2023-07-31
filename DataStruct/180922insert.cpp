#include <Stdio.h>

void insert(int len,int data[])
{
	int tmp,i;
	int cnt=0;
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
	printf("%d\n",cnt);
}
void print(int len,int a[])
{
	for(int i=0;i<len;i++)
	{
		printf("%d\t",a[i]);
	}
}



int main()
{
	int data[]={5,1,2,33,65,98,75,96,32,20,10,15,3,9,26,37,28,29,333,222,11,226};
	int len=sizeof(data)/sizeof(data[0]);
	insert(len,data);
	print(len,data);
	
}

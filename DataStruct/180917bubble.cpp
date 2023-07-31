#include <stdio.h>

void swap(int *p,int *q)
{
	int temp=*p;
	*p=*q;
	*q=temp;
}


void bubblesort(int len,int data[])
{
	for(int i=0;i<len;i++)
	{
		for(int j=len-1;j>0;j--)
		{
			if(data[j]<data[j-1])
			{
				swap(&data[j],&data[j-1]);
			}
		}
	}
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
	int data[]={12,13,15,19,17,94,90,80,87,64,62,32,61,43,41,21,9,7,3,6,4,1,52,35,68,94,12,32,24,25,36,60,18,5,8,9,123,456,789,987,654,321,213,546,71,25,53,97,99,930,390};
	int len=sizeof(data)/sizeof(data[0]);
	printf("bubblesort:\n");
	bubblesort(len,data);
	print(len,data);
	return 0;
}

#include <Stdio.h>
#include <Stdlib.h>

void Adjust(int a[],int len,int i)
{
	int tmp=a[i];
	for(int son=i*2+1;son<len;son=son*2+1)
	{
		if(son+1<len&&a[son+1]>a[son])
		{
			son++;
		}
		if(a[son]>tmp)
		{
			a[i]=a[son];
			i=son;
		}else 
		{
			break;
		}
	}
	a[i]=tmp;
}


void heapsort(int a[],int len)
{
	for(int i=len/2;i>=0;i--)
	{
		Adjust(a,len,i);
	}
	for(int j=len-1;j>0;j--)
	{
		int tmp=a[0];
		a[0]=a[j];
		a[j]=tmp;
		Adjust(a,j,0);
	}
}
void print(int len,int a[])
{
	for(int i=0;i<len;i++)
	{
		printf("%d->",a[i]);
	}
}

int main()
{
	int a[]={85,7,8,9,6,315,122,555,412,12,21,30,25,88,789,125};
	int len=sizeof(a)/sizeof(a[0]);
	heapsort(a,len);
	print(len,a);
}

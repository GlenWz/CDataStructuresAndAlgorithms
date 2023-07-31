#include <stdio.h>
#include <stdlib.h>

void Shell_Sort(int a[],int N)
{
	int n=6,p,i,tmp;   				//ShellÔöÁ¿
	for(;n>=1;n/=2)
	{
		for(p=n;p<N;p+=n)
		{
			tmp=a[p];
			for(i=p;a[i-n]>tmp&&i>=n;i-=n)
			{
				a[i]=a[i-n];
			}	
			a[i]=tmp;
		}	
	} 
}
void Print(int a[],int N)
{
	for(int i=0;i<N;i++)
	{
		printf("%d->",a[i]);
	}
	printf("\n");
}


int main()
{
	int a[]={10,8,15,1,5,9,3,5,7,8,5,2,6,5,4,15,12,1,335,36,69,64,21,75,23,10,102,};
	int N=sizeof(a)/sizeof(a[0]);
	Shell_Sort(a,N);
	Print(a,N);
}





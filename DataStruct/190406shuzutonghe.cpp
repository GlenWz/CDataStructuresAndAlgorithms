#include <Stdio.h>
#include <Stdlib.h>

int mergeAB(int *a,int lena,int *b,int lenb)
{
	int i,j,k;
	k=lena;
	printf("\n");
	for(i=0,j=0;i!=lena-1&&j<lenb;)
	{
		if(a[i]==b[j]||a[i+1]==b[j])
		{
			++j;
		}else if(a[i]<b[j]&&a[i+1]>b[j])
		{
			++k;
			for(int l=k;l>i;l--)
			{
				a[l]=a[l-1];
			}
			a[i+1]=b[j];
			++i;
			++j;
		}else
		{
			i++;
		}
	}
	if(i==k-1&&j!=lenb-1)
	{
		for(int t=k;j<lenb;j++)
		{
		
			a[t]=b[j];
			++k;
		}	
	}
	for(int s=0;s<k;s++)
	{
		printf("%d->",a[s]);
	}
	printf("\n");
	return k;	
}
void printAB(int *a,int lena)
{
	for(int i=0;i<lena;i++)
	{
		printf("%d->",a[i]);
	}
	printf("\n-------------------------\n");
}


int main()
{
	int a[]={1,3,5,7,9,11,13,15};
	int lena=sizeof(a)/sizeof(a[0]);
	int b[]={1,2,3,4,5,6,7,8,9,18,21,23};
	int lenb=sizeof(b)/sizeof(b[0]);
	int me;
	printAB(a,lena);
	printAB(b,lenb);
	me=mergeAB(a,lena,b,lenb);
	printAB(a,me);
}

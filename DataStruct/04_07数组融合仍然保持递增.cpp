#include <Stdio.h>
#include <stdlib.h>

int builda(int *a)
{
	int j=0;
	int len=10;
	for(int i=0;i<len;i++)
	{
		a[i]=j;
		j+=2;
	}
	return len;
}
int buildb(int *b)
{
	int j=1;
	int len=10;
	for(int i=0;i<len;i++)
	{
		b[i]=j;
		j+=3;
	}
	return len;
}
void print(int *a,int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d->",a[i]);
	}
	printf("\n");
}
int mergec(int *a,int *b,int lena,int lenb)
{
	int i,j,k;
	for(i=0,j=0;i<lena&&j<lenb;)
	{
		if(a[i]==b[j]||a[i+1]==b[j])
		{
			++j;
		}else if(a[i]>b[j])
		{
			++lena;
			for(int l=lena;l>i-1;l--)
			{
				a[l]=a[l-1];
			}
			a[i]=b[j];
			++i;
			++j;
		}else if(a[i]<b[j]&&a[i+1]>b[j])
		{
			++lena;
			for(int l=lena;l>i;l--)
			{
				a[l]=a[l-1];
			}
			a[i+1]=b[j];
			++i;
			++j;
		}else 
		{
			++i;
		}
	}
	if(i==lena-1&&j<lenb-1)
	{
		for(int l=lena;j<lenb;j++,l++)
		{
			a[l]=b[j];
			++lena;
		}
	}
	return lena;
}

int main()
{
	int a[20];
	int b[20];
	int lena,lenb,lenc;
	lena=builda(a);
	lenb=buildb(b);
	print(a,lena);
	print(b,lenb);
	lenc=mergec(a,b,lena,lenb);
	print(a,lenc);
}






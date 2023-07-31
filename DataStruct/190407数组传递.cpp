#include <Stdio.h>
#include <Stdlib.h>

int builda(int *a)
{
	int len=10;
	int j=1;
	for(int i=0;i<len;i++)
	{
		a[i]=j;
		j+=2;
	}
	return len;
}
int buildb(int *b)
{
	int len=10;
	int j=1;
	for(int i=0;i<len;i++)
	{
		b[i]=i;
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
int mergeab(int *a,int lena,int *b,int lenb)
{
	int i,j,k;
	for(i=0,j=0;i<lena&&j<lenb;)
	{
	//	printf("\nAI:%d   AI+1:%d  BJ:%d\n",a[i],a[i+1],b[j]);
		if(a[i]==b[j]||a[i+1]==b[j])
		{
			++j;
		//	printf("i am j");
		}else if(a[i]<b[j]&&a[i+1]>b[j])
		{
			++lena;
		//	printf("iam h");
			for(int s=lena;s>i;s--)
			{
				a[s]=a[s-1];
			}
			a[i+1]=b[j];
			++i;
			++j;
		}else if(a[i]>b[j])
		{
			++lena;
			for(int o=lena;o>i-1;o--)
			{
				a[o]=a[o-1];
			}
			a[i]=b[j];
			++i;
			++j;
		}else
		{
			++i;
		//	printf("i am i");
		}
	}
	if(j!=lenb-1)
	{
		for(int p=lena;j<lenb;p++,j++)
		{
			a[p]=b[j];
			++lena;
		}
	}
	return lena;
}



int main()
{
	int lena,lenb,lenab;
	int a[20];
	int b[20];
	lena=builda(a);
	lenb=buildb(b);
	print(a,lena);
	print(b,lenb);
	lenab=mergeab(a,lena,b,lenb);
	print(a,lenab);
}






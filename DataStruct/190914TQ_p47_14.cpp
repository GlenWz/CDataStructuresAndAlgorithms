#include <Stdio.h>
#include <stdlib.h>
#define max1 5

void HAOFANA(int a[][max1],int aa[])
{
	int tmp=0;
	for(int i=0;i<max1;i++)
	{
		for(int j=0;j<max1;j++)
		{
			if(a[i][j]!=0)
			{
				aa[tmp++]=i;
				aa[tmp++]=j;
				aa[tmp++]=a[i][j];
			}
		}
	}
	aa[tmp]=-1;
}
void JUZHEN(int a[],int b[],int c[])
{
	int tmp=0,k,t,s,i=0,v=0,j=0;
	for(;a[i]!=-1&&b[j]!=-1;)
	{
		for(s=i,t=j,k=0;k<2;k++)
		{
			if(a[s]==b[t])
			{
				tmp=8;
				s++;
				t++;
			}else 
			{
				if(a[s]>b[t])
				{
					tmp=1;
					break;
				}else if(a[s]<b[t])
				{
					tmp=-1;
					break;
				}
			}
		}
		if(tmp==8)
		{
			for(k=0;k<3;k++)
			{
				if(k==2)
				{
					c[v++]=a[i]+a[j];
					i++;
					j++;
				}else 
				{
					c[v++]=a[i];
					i++;
					j++;
				}	
			}
		}
		if(tmp==1)
		{
			for(k=0;k<3;k++)
			{
				c[v++]=b[j];
				j++;
			}
		}
		if(tmp==-1)
		{
			for(k=0;k<3;k++)
			{
				c[v++]=a[i];
				i++;
			}
		}
	}
	if(a[i]==-1&&b[j]!=-1)
	{
		for(;b[j]!=-1;j++,v++)
		{
			c[v]=b[j];
		}
	}
	if(b[j]==-1&&a[i]!=-1)
	{
		for(;a[i]!=-1;i++,v++)
		{
			c[v]=b[j];
		}
	}
	c[v]=-1;
}
void Print(int a[])
{
	for(int i=0;a[i]!=-1;i++)
	{
		printf("%d->",a[i]);
	}
	printf("\n");
}


int main()
{
	int a[max1][max1];
	
	for(int i=0;i<max1;i++)
	{
		for(int j=0;j<max1;j++)
		{
			if(i==j-1||j==i-1)
			{
				a[i][j]=i+j;
			}else
			{
				a[i][j]=0;
			}
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	int b[max1][max1];
	for(int i=0;i<max1;i++)
	{
		for(int j=0;j<max1;j++)
		{
			if(i==j)
			{
				b[i][j]=i+j;
			}else 
			{
				b[i][j]=0;
			}
			printf("%d  ",b[i][j]);
		}
		printf("\n");
	}
	int AA[100];
	int BB[100];
	HAOFANA(a,AA);
	HAOFANA(b,BB);
	
	int CC[200];
	Print(AA);
	Print(BB);
	JUZHEN(AA,BB,CC);
	Print(CC);
}

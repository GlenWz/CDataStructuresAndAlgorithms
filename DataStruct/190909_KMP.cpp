#include <stdio.h>
#include <stdlib.h>

void PrefixT(char pattern[],int lenp,int Prefix[])
{
	Prefix[0]=0;
	int j=0;
	for(int i=1;i<lenp;)
	{
		if(pattern[i]==pattern[j])
		{
			j++;
			Prefix[i]=j;
			i++;
		}else 
		{
			if(j>0)
			{
				j=Prefix[j-1];
			}else 
			{
				Prefix[i]=j;
				i++;
			}
		}
	}
}
void SortP(int Prefix[],int lenp)
{
	for(int i=lenp;i>0;i--)
	{
		Prefix[i]=Prefix[i-1];
	}
	for(int i=0;i<lenp;i++)
	{
		printf("%d  ",Prefix[i]);
	}
	printf("\n");
}
int KMP(char str[],int strlen,char pattern[],int lenp,int Prefix[])
{
	int tmp,i,j;
	for(i=0,j=0;i<strlen;)
	{
		printf("%d\n",i);
		if(str[i]==pattern[j])
		{
			i++;
			j++;
			if(j>=lenp)
			{
				return i-lenp;
			}
		}else 
		{
			if(j>0)
			{
				j=Prefix[j];
			}else 
			{
				i++;
			}
		}
	}
	return -1;
}

int main()
{
	char str[]="BBBBBBBBBBBBA";
	int lenstr=sizeof(str)/sizeof(str[0])-1;
	char pattern[]="BBBA";
	int lenp=sizeof(pattern)/sizeof(pattern[0])-1;
	int Prefix[lenp];
	PrefixT(pattern,lenp,Prefix);
	SortP(Prefix,lenp);
	int pos=KMP(str,lenstr,pattern,lenp,Prefix);
	printf("\n****the pos is :%d\n",pos);
} 









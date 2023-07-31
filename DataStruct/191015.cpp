#include <Stdio.h>
#include <Stdlib.h>
#define MAXSIZE 100

void PrefixTable(char pattern[],int Prefix[],int lenp)
{
	Prefix[0]=0;
	int j=0;
	for(int i=1;i<lenp;)
	{
		if(pattern[i]==pattern[j])
		{
			++j;
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

void SortPrefix(int Prefix[],int lenp)
{
	for(int j=lenp;j>0;j--)
	{
		Prefix[j]=Prefix[j-1];
	}
}
int KMP(int Prefix[],int lenp,char str[],int strlen,char pattern[])
{
	int j=0;
	for(int i=0;i<strlen;)
	{
		if(pattern[j]==str[i])
		{
			j++;
			i++;
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
	char pattern[]="BCABCA";
	int lenp=sizeof(pattern)/sizeof(pattern[0])-1;
	int Prefix[lenp];
	PrefixTable(pattern,Prefix,lenp);
	SortPrefix(Prefix,lenp);
	char str[]="dhkdakaslBCABCAjkl";
	int strlen=sizeof(str)/sizeof(str[0])-1;
	int pos=KMP(Prefix,lenp,str,strlen,pattern);
	printf("The Position is %d\n",pos);
}







#include <Stdio.h>
#include <Stdlib.h>

void PrefixT(char pat[],int patlen,int prefix[])
{
	int i,j=0;
	prefix[0]=0;
	for(i=1;i<patlen;)
	{
		if(pat[i]==pat[j])
		{
			j++;
			prefix[i]=j;
			i++;
		}else 
		{
			if(j>0)
			{
				j=prefix[i-1];
			}else 
			{
				prefix[i]=j;
				i++;
			}
		}
	}
}
void SortP(int prefix[],int patlen)
{
	for(int i=patlen-1;i>0;i--)
	{
		prefix[i]=prefix[i-1];
	}
	for(int i=0;i<patlen;i++)
	{
		printf("%d\t",prefix[i]);
	}
}
int KMP_A(char str[],int strlen,char pat[],int patlen,int prefix[])
{
	int i,j=0;
	for(i=0;i<strlen;)
	{
		if(str[i]==pat[j])
		{
			i++;
			j++;
			if(j==patlen)
			{
				return i-j;
			}	
		}else 
		{
			if(j>0)
			{
				j=prefix[j];
			}else 
			{
				i++;
			}
		}	
	}
	return -1;	
}

int KMP(char str[],char pat[],int strlen,int patlen)
{
	int prefix[patlen];
	PrefixT(pat,patlen,prefix);
	SortP(prefix,patlen);
	int pos=KMP_A(str,strlen,pat,patlen,prefix);
	return pos;
}

int WhatTheFuck(char str[],char pat[],int strlen,int patlen)
{
	int pos,i,j,ret=0;
	do
	{
		pos=KMP(str,pat,strlen,patlen);
		if(pos!=-1)
		{
			ret++;
			for(i=pos;i+patlen<=strlen;i++)
			{
				str[i]=str[i+patlen];
			}
			for(j=i;j<strlen;j++)
			{
				str[j]='\0';
			}
			strlen=strlen-patlen;
		}
	}while(pos!=-1);
	return ret;
}

int main()
{
	char str[]="BCABCABAAABCAB";
	char pat[]="BCAB";
	int strlen=sizeof(str)/sizeof(str[0])-1;
	int patlen=sizeof(pat)/sizeof(pat[0])-1;
	int num=WhatTheFuck(str,pat,strlen,patlen);
	printf("\nthe num is :%d\n",num);
}










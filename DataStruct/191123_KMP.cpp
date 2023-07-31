#include <stdio.h>
#include <stdlib.h>

int PrefixT(char pattern[],int lens,int Prefix[])
{
	int i=0,j=1;
	Prefix[0]=0;
	for(;j<lens;)
	{
		if(pattern[i]==pattern[j])
		{
			++i;
			Prefix[j]=i;
			j++;
		}else
		{
			if(i>0)
			{
				i=Prefix[i-1];
			}else 
			{
				Prefix[j]=i;
				j++;
			}
		}
	}
}
void Sort(int Prefix[],int lens)
{
	for(int i=lens;i>0;i--)
	{
		Prefix[i]=Prefix[i-1];
	}
}
int  KMP(char pattern[],int Prefix[],char str[],int lens,int strlen)
{
	int i,j=0;
	for(i=0;i<strlen;)
	{
		if(pattern[j]==str[i])
		{
			i++;
			j++;
			if(j>=lens)
			{
				return i-j;
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
}


int main()
{
	char pattern[]="abcabc";
	int lens=sizeof(pattern)/sizeof(pattern[0])-1;
	int Prefix[lens];
	PrefixT(pattern,lens,Prefix);
	Sort(Prefix,lens);
	char str[]="dhadlhabcabc";
	int strlen=sizeof(str)/sizeof(str[0])-1;
	int pos=KMP(pattern,Prefix,str,lens,strlen);
	printf("the position is %d",pos);	
}

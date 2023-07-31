#include <stdio.h>

void Prefix(char pattern[],int prefix[],int len)
{
	int i,tmp=0;
	prefix[0]=0;
	for(i=1;i<len;)
	{
		if(pattern[i]==pattern[tmp])
		{
			tmp++;
			prefix[i]=tmp;
			i++;
		}else 
		{
			if(tmp==0)
			{
				prefix[i]=tmp;
				i++;
			}else
			{
				tmp=prefix[tmp-1];
			}
		}
	}
}
void SortPre(int prefix[],int len)
{
	int i,j;
	for(i=len;i>0;i--)
	{
		prefix[i]=prefix[i-1];
	}
	for(j=0;j<len;j++)
	{
		printf("%d\t",prefix[j]);
	}
	printf("\n");
}
int Kmp(char pattern[],int prefix[],int len,char string[],int lenstr)
{
	int i,j=0;
	for(i=0;i<lenstr;)
	{
		if(pattern[j]==string[i])
		{
			j++;
			if(j==len)
			{
				return i-j;
			}
			i++;
		}else 
		{
			if(j!=0)
			{
				j=prefix[j];
			}else 
			{
				i++;
			}
		}
	}
}



int main()
{
	char pattern[]="ABCAB";
	int len=sizeof(pattern)/sizeof(pattern[0])-1;
	int prefix[len];
	Prefix(pattern,prefix,len);
	SortPre(prefix,len);
	char string[]="CSJDADLKASDJSABCABKLK";
	int strlen=sizeof(string)/sizeof(string[0])-1;
	int pos;
	pos=Kmp(pattern,prefix,len,string,strlen);
	printf("the position is %d\n",pos);
}








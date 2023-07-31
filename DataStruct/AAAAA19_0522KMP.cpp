#include <stdio.h>
#include <Stdlib.h>

void PreFix(char pattern[],int prefix[],int lenP)
{
	prefix[0]=0;
	int len=0;
	int i=1;

	while(i<=lenP)
	{
		
		if(pattern[i]==pattern[len])
		{
			len++;
			prefix[i]=len;
			i++;
		}else 
		{
			if(len>0)
			{
				len=prefix[len-1];
			}else
			{	
				prefix[i]=len;
				i++;
			}
		}
	}
}
void SortPreFix(int prefix[],int len)
{
	for(int i=len;i>0;i--)
	{
		prefix[i]=prefix[i-1];
	}
	prefix[0]=0;
}
int KMP(char string[],char pattern[],int prefix[],int strlen,int lenP)
{
	int j=0;
	int ret=-1;
	for(int i=0;i<strlen&&pattern[j]!='\0';)
	{
		if(string[i]==pattern[j])
		{
			i++;
			j++;
			ret=i;
			if(j==lenP)
			{
				ret-=lenP;
				return ret;
			}
		}else if(string[i]!=pattern[j]&&j==0)
		{
			j=prefix[j];
			i++;
		}else 
		{
			j=prefix[j];
		}
	}
	return -1;
}

int main()
{
	char Pattern[]="BCABCA";
	int lenP=sizeof(Pattern)/sizeof(Pattern[0])-1;
	printf("LEP:%d\n",lenP);
	int prefix[lenP];
	PreFix(Pattern,prefix,lenP);
	SortPreFix(prefix,lenP);
	for(int i=0;i<lenP;i++)
	{
		printf("%d\n",prefix[i]);
	}
	char String[]="ABCBCABACBCABCAAB";
	int StrLen=sizeof(String)/sizeof(String[0])-1;
	int position=KMP(String,Pattern,prefix,StrLen,lenP);
	printf("Position:%d\n",position);
	
	
}

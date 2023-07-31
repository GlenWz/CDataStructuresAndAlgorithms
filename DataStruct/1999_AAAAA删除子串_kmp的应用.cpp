#include <Stdio.h>
#include <stdlib.h>

void PrefixTable(char pattern[],int lenp,int prefix[])
{
	prefix[0]=0;
	int i,j;
	for(i=1,j=0;i<lenp;)
	{
		if(pattern[i]==pattern[j])
		{
			j++;
			prefix[i]=j;
			i++;
		}else 
		{
			if(j>0)
			{
				j=prefix[j-1];
			}else 
			{
				prefix[i]=j;
				i++;
			}
		}
	}
}
void SortP(int prefix[],int lenp)
{
	for(int i=lenp-1;i>0;i--)
	{
		prefix[i]=prefix[i-1];
	}
	for(int i=0;i<lenp;i++)
	{
		printf("%d  ",prefix[i]);	
	}
	printf("\n");
}

int KMP_A(char str[],int lenstr,char pattern[],int lenp,int prefix[])
{
	int i,j,tmp;
	
	for(i=0,j=0;i<lenstr;)
	{
		if(str[i]==pattern[j])
		{
			i++;
			j++;
			if(j==lenp)
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

int Kmp(char str[],char pattern[],int strlen,int lenp)
{
	int prefix[lenp];
	PrefixTable(pattern,lenp,prefix);
	SortP(prefix,lenp);
	
	int ret=KMP_A(str,strlen,pattern,lenp,prefix);
	return ret;
	
}




void DelPattern(char str[],char pattern[],int strlen,int lenp)
{
	int pos=-1;
	do {
		pos=Kmp(str,pattern,strlen,lenp);
		printf("POS=%d\n",pos);
		if(pos!=-1)
		{
			int i;
			for(i=pos;i+lenp<=strlen;i++)
			{
				str[i]=str[i+lenp];	
			}
			for(;i<strlen;i++)
			{
				str[i]='\0';
			}
			strlen=strlen-lenp;
		}		
	}while(pos!=-1);
}

void Print(char str[])
{
	for(int i=0;str[i]!='\0';i++)
	{
		printf("%c",str[i]);
	}
	printf("\n");
}

int main()
{
	char str[]="BCABCADASLKJDLKABCAJKBCA";
	char pattern[]="BCA";
	int strlen=sizeof(str)/sizeof(str[0])-1;
	int lenp=sizeof(pattern)/sizeof(pattern[0])-1;
	DelPattern(str,pattern,strlen,lenp);
	Print(str);
 } 
 
 
 
 
 
 
 
 

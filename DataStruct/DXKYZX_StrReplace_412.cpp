#include <stdio.h>
#include <stdlib.h>

void PrefixT(char t[],int tlen,int prefix[])
{
	prefix[0]=0;
	printf("the ");
	int i,j;
	for(i=1,j=0;i<tlen;)
	{
		if(t[i]==t[j])
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
void Sort(int prefix[],int len)
{
	printf("++++%d",prefix[0]);
	for(int i=len-1;i>0;i--)
	{
		
		prefix[i]=prefix[i-1];
		
	}
}
int KMP(char str[],char t[],int strlen,int tlen,int prefix[])
{
	int i,j,tmp;
	for(i=0,j=0;i<strlen;)
	{
		if(str[i]==t[j])
		{
			j++;
			i++;
			if(j==tlen)
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


int KmpReplace(char str[],char t[],char h[],int strlen,int tlen,int hlen)
{
	int ret=0;
	int prefix[tlen];
	PrefixT(t,tlen,prefix);
	Sort(prefix,tlen);
	do
	{
		ret=KMP(str,t,strlen,tlen,prefix);
	//	printf("RET:%d",ret);
		if(ret!=-1)
		{
			int tmp=hlen-tlen;
			if(tmp>0)
			{
				for(int j=strlen+tmp;j>ret;j--)
				{
					str[j]=str[j-tmp];
				}
			}
			if(tmp<0)
			{
				
			}
			for(int i=ret,k=0;k<hlen;i++)
			{
				str[i]=h[k++];
			}
		}
	}while(ret!=-1);
}



void Replace(char str[],char t[],char h[],int strlen,int tlen,int hlen)
{
	
	KmpReplace(str,t,h,strlen,tlen,hlen);
	
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
	char str[]="StringStringStringString";
	char t[]="S";
	char h[]="s";
	int strlen=sizeof(str)/sizeof(str[0])-1;
	int tlen=sizeof(t)/sizeof(t[0])-1;
	int hlen=sizeof(h)/sizeof(h[0])-1;
	Replace(str,t,h,strlen,tlen,hlen);
	Print(str);
}

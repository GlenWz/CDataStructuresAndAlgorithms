#include <stdio.h>
#include <stdlib.h>

int Prefix(int prefix[],int len,char str[])
{
	int i=1;
	prefix[0]=0;
	int tmp=0;
	while(i<len)
	{
		if(str[i]==str[tmp])
		{
			tmp++;
			prefix[i]=tmp;
			i++;
		}else 
		{
			if(tmp>0)
			{
				tmp=prefix[tmp-1];
				
			}else
			{
				prefix[i]=tmp;
				i++;
			}
		}
	}
}
void Sort(int prefix[],int len)
{
	for(int i=len;i>0;i--)
	{
		prefix[i]=prefix[i-1];	
	}
	for(int i=0;i<len;i++)
	{
		printf("%d->",prefix[i]);
	}
	printf("\n");
}
int KMP(char String[],int lenstr,char str[],int len,int prefix[])
{
	int tmp=0;
	int i;
	for(i=0;i<lenstr;)
	{
		if(String[i]==str[tmp])
		{
			tmp++;
			i++;
			if(tmp>=len)
			{
				return i-tmp;
			}
		}else 
		{
			if(tmp>0)
			{
				tmp=prefix[tmp];
				
			}else
			{
				i++;
			}
		}
	}
	return 0;
}
int main()
{
	char str1[]="BCABCA";
	char str2[]="BBCBBC";
	char str3[]="BF";
	int len1=sizeof(str1)/sizeof(str1[0])-1;
	int len2=sizeof(str2)/sizeof(str2[0])-10;
	int len3=sizeof(str3)/sizeof(str3[0])-1;
	int prefix1[len1]={};
	int prefix2[len2]={};
	int prefix3[len3]={};
	Prefix(prefix1,len1,str1);
	Prefix(prefix2,len2,str2);
	Prefix(prefix3,len3,str3);
	Sort(prefix1,len1);
	Sort(prefix2,len2);
	Sort(prefix3,len3);
	char String[]="BCASDBFSSKKJGIJASBBCBBCSDAJLKGKLBCABCA";
	int lenstr=sizeof(String)/sizeof(String[0])-1;
	int position1=KMP(String,lenstr,str1,len1,prefix1);
	int position2=KMP(String,lenstr,str2,len2,prefix2);
	int position3=KMP(String,lenstr,str3,len3,prefix3);
	char mima1[]="BCASDBFSSKKJGIJASBBCBBCSDAJLKGKL";
	char mima2[]="BCASDBFSSKKJGIJAS";
	int mima2len=sizeof(mima2)/sizeof(mima2[0])-1;
	int mima1len=sizeof(mima1)/sizeof(mima1[0])-1;
	printf("%d \n%d \n",mima1len,mima2len);
	printf("\n");
	printf("%d",position1);
	printf("%d",mima1len*mima2len+4+9236875);
	printf("MIao:%d\n",position1*position2+position3+9236875);
	
	
}

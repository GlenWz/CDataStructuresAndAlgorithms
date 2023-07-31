#include <Stdio.h>
#include <Stdlib.h>

void PrefixT(char pattern[],int lenp,int prefix[])
{
	int i,j=0;
	for(i=1;i<lenp;)
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
				j=prefix[i-1];
				
			}else 
			{
				prefix[i]=j;
				i++;
			}
		}
	}
}
void Sort(int prefix[],int lenp)
{
	for(int i=lenp-1;i>0;i--)
	{
		prefix[i]=prefix[i-1];
	}
}
int KMP_C(char str[],int strlen,char pattern[],int lenp,int &num,int prefix[],int &pos)
{
	int i,j,tmp,k,ret=0;
	tmp=lenp-1;
	for(i=0,j=0;i+tmp<strlen;)
	{
		if(pattern[j]==str[i]&&pattern[j+tmp]==str[i+tmp])
		{
			k=i;
			for(;i<=k+tmp;)
			{
				if(pattern[j]!=str[i])
				{
					break;
				}
				i++;
				j++;
			}
			num++;
			pos=k;
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
		ret++;
	}
	return ret;
}

int main()
{
	char pattern[]="ABCABC";
	int lenp=sizeof(pattern)/sizeof(pattern[0])-1;
	int prefix[lenp];
	PrefixT(pattern,lenp,prefix);
	Sort(prefix,lenp);
	char str[]="stringABVkldalABCABCjlka";
	int  strlen=sizeof(str)/sizeof(str[0])-1;
	int num=0,pos;
	int ret=KMP_C(str,strlen,pattern,lenp,num,prefix,pos);
	printf("the num is %d\n%d\n%d\npos is %d\n",num,ret,strlen,pos);
}











#include <Stdio.h>
#include <Stdlib.h>

void PreFixTable(char Pattern[],int Prefix[],int lenPa)
{
	Prefix[0]=0;
	int i=1;
	int tmp=0;
	while(i<lenPa)
	{
		if(Pattern[i]==Pattern[tmp])
		{
			tmp++;
			Prefix[i]=tmp;
			i++;
		}else 
		{
			if(tmp>0)
			{
				tmp=Prefix[tmp-1];
			}else
			{
				Prefix[i]=tmp;
				i++;
			}
		}
	}
}
void SortPrefix(int Prefix[],int lenP)
{
	for(int i=lenP;i>0;i--)
	{
		Prefix[i]=Prefix[i-1];
	}
}
int KMP(char String[],char Pattern[],int Prefix[],int Strlen,int lenPa)
{
	int j=0;
	int ret=-1;
	for(int i=0;i<Strlen;)
	{
		if(String[i]==Pattern[j])
		{
			i++;
			j++;
			if(j==lenPa)
			{
				return i-lenPa;
			}
		}else if(String[i]!=Pattern[j]&&j==0)
		{
			j=Prefix[j];
			i++;
		}else 
		{
			j=Prefix[j];
		}
	}
	return -1;
}

int main()
{
	char Pattern[]="BCABCA";
	int lenPa=sizeof(Pattern)/sizeof(Pattern[0])-1;
	int Prefix[lenPa];
	PreFixTable(Pattern,Prefix,lenPa);
	SortPrefix(Prefix,lenPa);
	
	char String[]="ABCBCABSCABXBABCABCAB";
	int lenStr=sizeof(String)/sizeof(String[0])-1;
	int Position=KMP(String,Pattern,Prefix,lenStr,lenPa);
	printf("%d\n",Position);
}

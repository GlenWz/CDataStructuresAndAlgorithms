#include <Stdio.h>
#include <stdlib.h>

void PrefixTable(char Pattern[],int Prefix[],int lenPa)
{
	Prefix[0]=0;
	int i=1;
	int tmp=0;
	while(i<lenPa)
	{
		if(Pattern[tmp]==Pattern[i])
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
void SortPre(int Prefix[],int lenpa)
{
	for(int i=lenpa;i>0;i--)
	{
		Prefix[i]=Prefix[i-1];
	}
	for(int i=0;i<lenpa;i++)
	{
		printf("%d->",Prefix[i]);
	}
	
}

int Kmp(char Str[],int lenStr,char Pattern[],int lenPa,int Prefix[])
{
	int j=0;
	int i=0;
	for(;i<lenStr;)
	{
		if(Pattern[j]==Str[i])
		{
			i++;
			j++;
			if(j>=lenPa)
			{
				return i-lenPa;
			}
		}else if(Pattern[j]!=Str[i]&&j==0)
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
	int LenPa=sizeof(Pattern)/sizeof(Pattern[0])-1;
	int Prefix[LenPa];
	
	PrefixTable(Pattern,Prefix,LenPa);
	SortPre(Prefix,LenPa);
	
	char Str[]="BCCBBSDADBDBCABCA";
	int lenStr=sizeof(Str)/sizeof(Str[0]);
	int position=Kmp(Str,lenStr,Pattern,LenPa,Prefix);
	
	if(position==-1)
	{
		printf("NOT FIND!");
	}else 
	{
		printf("the position is %d",position);
	}
	
}

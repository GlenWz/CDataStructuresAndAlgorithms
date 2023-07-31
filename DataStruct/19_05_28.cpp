#include <Stdio.h>

void PrefixTable(char Pattern[],int lenPa,int PreFix[])
{
	PreFix[0]=0;
	int i=1;
	int tmp=0;
	while(i<lenPa)
	{
		if(Pattern[i]==Pattern[tmp])
		{
			tmp++;
			PreFix[i]=tmp;
			i++;
		}else 
		{
			if(tmp>0)
			{
				tmp=PreFix[tmp-1];
			}else 
			{
				PreFix[i]=tmp;
				i++;
			}
		}
	}	
}
void PFTsort(int PreFix[],int lenPa)
{
	for(int i=lenPa;i>0;i--)
	{
		PreFix[i]=PreFix[i-1];
	}
}
int KMP_(char String[],int PreFix[],int lenPa,char Pattern[],int StrLen)
{
	int j=0;
	for(int i=0;i<StrLen;)
	{
		if(Pattern[j]==String[i])
		{
			i++;
			j++;
			if(j==lenPa)
			{
				return i-lenPa;
			}
		}else if(Pattern[j]!=String[i]&&j==0)
		{
			j=Pattern[j];
			i++;
		}else 
		{
			j=Pattern[j];
		}
	}
	return -1;
}

int main()
{
	char Pattern[]="ABCABC";
	int lenPa=sizeof(Pattern)/sizeof(Pattern[0])-1;
	int PreFix[lenPa];
	
	PrefixTable(Pattern,lenPa,PreFix);
	PFTsort(PreFix,lenPa);
	
	char String[]="AVBCBASDDKGABCABCDDS";
	int lenStr=sizeof(String)/sizeof(String[0]);
	int position=KMP_(String,PreFix,lenPa,Pattern,lenStr);
	
	printf("The Position is %d\n",position);
	
	
}

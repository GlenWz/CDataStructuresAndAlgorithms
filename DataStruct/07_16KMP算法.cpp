#include <Stdio.h>

int PrefixT(char Pattern[],int lenP,int Prefix[])
{
	int tmp=0;
	int i;
	Prefix[0]=0;
	for(i=1;i<lenP;)
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
				Prefix[i]=0;
				i++;
			}
		}
	}
}
void SortP(int Prefix[],int lenP)
{
	for(int i=lenP;i>0;i--)
	{
		Prefix[i]=Prefix[i-1];
	}
	for(int i=0;i<lenP;i++)
	{
		printf("%d\t",Prefix[i]);
	}
	printf("\n");
}
int KMP(char Str[],int StrLen,int Prefix[],int lenP,char Pattern[])
{
	int tmp=0;
	int i;
	for(i=0;i<StrLen;)
	{
		if(Str[i]==Pattern[tmp])
		{
			tmp++;
			i++;
			if(tmp>=lenP)
			{
				return i-tmp;
			}
		}else 
		{
			if(tmp>0)
			{
				tmp=Prefix[tmp];
			}else 
			{
				i++;
			}
		}
	}
	return -1;
}

int main()
{
	char Pattern[]="BCABCA";
	int lenP=sizeof(Pattern)/sizeof(Pattern[0])-1;
	int Prefix[lenP];
	PrefixT(Pattern,lenP,Prefix);
	SortP(Prefix,lenP);
	char Str[]="aaasdADSADASHKJHADBCABCAdddsss";
	int StrLen=sizeof(Str)/sizeof(Str[0])-1;
	int pos=KMP(Str,StrLen,Prefix,lenP,Pattern);
	if(pos==-1)
	{
		printf("NOT FIND!\n");
	}else 
	{
		printf("the pos is %d\n",pos);
	}
}






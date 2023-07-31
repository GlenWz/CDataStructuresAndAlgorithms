#include <stdio.h>

void FixTable(char *pattern,int lenp,int fixtable[])
{
	int i,j=0,tmp=0;
	fixtable[0]=0;
	for(i=1;i<lenp;)
	{
		if(pattern[i]==pattern[j])
		{
			++tmp;
			fixtable[i]=tmp;
			i++;
			j++;
		}else 
		{
			if(j>0)
			{
				j=fixtable[j-1];
				i++;
			}else 
			{
				fixtable[i]=0;
				i++;
			}
		}
	}
}
void Sort(int fixtable[],int lenp)
{
	for(int i=lenp;i>0;i--)
	{
		fixtable[lenp]=fixtable[lenp-1];
	}
}
int KMP(char pattern[],int lenp,int prefix[],char string[],int lenstr)
{
	int i,j;
	for(i=0,j=0;i<lenstr;)
	{
		if(pattern[j]==string[i])
		{
			i++;
			j++;
			if(j>=lenp)
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
				j=prefix[j];
			}
		}
	}
	return -1;
}


int main()
{
	char pattern[]="BCABCAS";
	char string[]="bsBACBCABCASJKLJ";
	int lenp=sizeof(pattern)/sizeof(pattern[0])-1;
	int fixtable[lenp];
	FixTable(pattern,lenp,fixtable);
	Sort(fixtable,lenp);
	int strlen=sizeof(string)/sizeof(string[0])-1;
	int pos=KMP(pattern,lenp,fixtable,string,strlen);
	printf("the position is %d\n",pos);
}








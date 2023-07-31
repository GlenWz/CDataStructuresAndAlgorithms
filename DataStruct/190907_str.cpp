#include <Stdio.h>
#include <stdlib.h>
#define max 10

void Notin(char s[],char t[],int lens,int lent,char notin[])
{
	int n=0;
	int i,j;
	for(i=0;i<lens;i++)
	{
		for(j=0;j<lent;j++)
		{
			if(s[i]==t[j])
			{
				i++;
				break;
			}else 
			{
				if(j==lent-1)
				{
					notin[n++]=s[i];
					t[lent++]=s[i];
				}
			}
		}
	}
}
void Print(char nin[])
{
	for(int i=0;nin[i]!='\0';i++)
	{
		printf("%c",nin[i]);
	}
	printf("\n");
}


int main()
{
	char s[]="adsadjklq";
	char t[]="lhdafashjz";
	int lent=sizeof(t)/sizeof(t[0])-1;
	int lens=sizeof(s)/sizeof(s[0])-1;
	char nin[lent+lens];
	Notin(s,t,lens,lent,nin);
	Print(nin);
	
	
}

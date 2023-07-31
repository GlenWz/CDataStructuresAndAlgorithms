#include <Stdio.h>
#include <Stdlib.h>

void String(char str[],char jtr[],char rtr[],int strlen,int jtrlen)
{
	int i,j,k;
	for(i=0,k=0;i<strlen;)
	{
		for(j=0;j<jtrlen;j++)
		{
			if(str[i]==jtr[j])
			{
				i++;
				break;
			}
			if(j==jtrlen-1)
			{
				rtr[k++]=str[i];
				jtr[jtrlen]=str[i];
				jtrlen++;
			}
		}
	}
}
void Print(char rtr[])
{
	for(int i=0;rtr[i]!='\0';i++)
	{
		printf("%c",rtr[i]);
	}
	printf("\n");
}


int main()
{
	char str[]="stringi";
	char jtr[]="kjhstrstrllol";
	int lenstr=sizeof(str)/sizeof(str[0])-1;
	int lenjtr=sizeof(jtr)/sizeof(jtr[0])-1;
	char rtr[lenstr];
	String(str,jtr,rtr,lenstr,lenjtr);
	Print(rtr);
}

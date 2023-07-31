#include <stdlib.h>
#include <stdio.h>

char *Transform(char str[])
{
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]>=65&&str[i]<=90)
		{
			str[i]=str[i]+32;
		}else if(str[i]>=95&&str[i]<=122) 
		{
			str[i]=str[i]-32;
		}
	}
	return str;
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
	char str[]="stringaaAAAaadAA,SDAaa..";
	Print(str);
	char *str1=Transform(str);
	Print(str1);
}

#include <stdio.h>
#include <stdlib.h>

void NIZHI(char str[],int lenstr)
{
	char c;
	int i,j;
	for(i=0,j=lenstr-1;i<j;i++,j--)
	{
		c=str[i];
		str[i]=str[j];
		str[j]=c;
	}
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
	char str[]="ABCDEFG";
	int lenstr=sizeof(str)/sizeof(str[0])-1;
	NIZHI(str,lenstr);
	
	Print(str);
	
}

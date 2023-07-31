#include <Stdio.h>
#include <stdlib.h>

int main()
{
	char str[]="string";
	char s;
	int len=sizeof(str)/sizeof(str[0])-1;
	for(int i=len-1,j=0;i>j;i--,j++)
	{
		s=str[i];
		str[i]=str[j];
		str[j]=s;
	}
	for(int i=0;i<len;i++)
	{
		printf("%c",str[i]);
	}
	printf("\n");
}

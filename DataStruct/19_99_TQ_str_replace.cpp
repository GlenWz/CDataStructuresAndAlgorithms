#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

void Replace(char *str,int a,int b,char *pat)
{
	int j;
	int cha=abs((b-a)-strlen(pat));
	int StrLen=strlen(str);
	int PatLen=strlen(pat);
	if((b-a)<strlen(pat))
	{
		for(int i=StrLen+cha,j=StrLen;i>a;i--)
		{
			str[i]=str[j--];
		}
	}else 
	{
		for(int i=a;i<StrLen+cha;i++)
		{
			str[i]=str[i+cha];
		}
	}
	for(int i=a,j=0;j<PatLen;i++,j++)
	{
		str[i]=pat[j];
	}
}
void Print(char str[])
{
	for(int i=0;str[i]!='\0';i++)
	{
		printf("%c",str[i]);
	}
}




int main()
{
	char str[]="abcd";
	char pat[]="xyz";
	int a,b;
	printf("please input the a:\n");
	scanf("%d",&a);
	printf("please input the b:\n");
	scanf("%d",&b);
	Replace(str,a,b,pat);
	Print(str);
	
}

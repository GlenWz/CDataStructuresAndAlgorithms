#include <Stdio.h>

char *Strncpy(char *s1,char *s2,int n)
{
	char *s;
	for(s=s1;n>0&&*s2!='\0';n--)
	{
		*s++=*s2++;
	}
	for(;n>0;n--)
	{
		*s++='\0';
	}
	return s1;
}
void PrintStr(char *s)
{
	for(;*s!='\0';)
	{
		printf("%c",*s++);
	}
}

int main()
{
	char str2[]="string 0kkk\0  jk";
	int n=sizeof(str2)/sizeof(str2[0]);
//	printf("%d",n);
	char str1[n];
	char *s=Strncpy(str1,str2,n);
	PrintStr(s);
}



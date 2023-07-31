#include <stdio.h>
#include <string.h>
char* mycpy(char* dst,const char* src)
{
	int idx=0;
	while(src[idx]!='\0')
	{
		dst[idx]=src[idx];
		idx++;
	}
	dst[idx]=src[idx];
	return dst;
}

int main()
{
	char s1[]="abc";
	char s2[]="acb";
	strcpy(s1,s2);
	printf("%s",s1);
	return 0;
	
}



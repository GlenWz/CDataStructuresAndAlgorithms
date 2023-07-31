#include <string.h>
#include <stdio.h> 

int mylen(const char*s)
{
	int cnt=0;
	int idx=0;
	while(s[idx]!='\0')
	{
		idx++;
		cnt++;
	}
}

int main()
{
	char line[]="hello";
	printf("%d\n",sizeof(line));
	printf("%d",strlen(line));
	return 0;
	
}//

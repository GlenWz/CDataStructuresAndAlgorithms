#include <stdio.h>

int main()
{
	char *s="hello world!";
//	s[0]='b';
	char *s2="hello world!";
	char s3[]="hello world!";
	printf("s=%p\n",s);
	printf("s2=%p\n",s2);
	printf("s3=%p\n",&s3);
    printf("s3=%p\n",s3);
	return 0;

}

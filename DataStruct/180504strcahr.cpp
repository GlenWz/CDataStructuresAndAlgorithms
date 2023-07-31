#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char a[]="string";
	char *p=strchr(a,'t');
//	char *t=strchr(a,'t');
	strchr(t,p);
	*t=(char*)malloc(strlen(p)+1);
	printf("%s\n",p);
	printf("%s\n",p+1);
	printf("t=%s\n",t);
	free(t);
	return 0;
}


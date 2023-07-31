#include <stdio.h>
#include <string.h>

int main()
{
	char line[]="hello";
	printf("strlen=%lu\n",strlen(line));
	printf("string=%lu\n",sizeof(line));
	return 0; 
}

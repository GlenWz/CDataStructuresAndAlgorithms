o#include <Stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	char s[80];
	char c;
	FILE *pf;
	if((pf=fopen("d:\\lianxi\\shuchu.txt","r"))==NULL)
	{
		printf("meiyoukaide\n");
		system("PAUSE");
		exit(1);
	}
	fscanf(pf,"%d\n",&i);
	printf("%d\n",i);
	fgets(s,80,pf);
	puts(s);
	c=fgetc(pf);
	putchar(c);
	fclose(pf);
	system("PAUSE");
	return 0;
}

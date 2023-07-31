#include <stdio.h>
#include <stdlib.h>


int main()
{
	FILE *pf;
	if((pf=fopen("d:\\lianxi\\shuchu.txt","w"))==NULL)
	{
		printf("meiyoudakai!");
		system("PAUSE");
		exit(1);
	}
	fprintf(pf,"%d\n",123);
	fputs("hello world\n",pf);
	fputc('char',pf);
	fclose(pf);
	system("PAUSE");
	return 0;
}

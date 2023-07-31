#include <stdio.h>
#include <stdlib.h>


int main()
{
	FILE *pf;
	if((pf=fopen("d:\\lianxi\\jingjie.xls","w"))==NULL)
	{
		printf("NO FILE!\n");
		system("PAUSE");
		exit(1);
	}
	char ad=' ';
	for(int i=0;i<111;i++)
	{
		fputc(ad,pf);
		if(i%2==0)
		{
			fputs("\n",pf);
			fprintf(pf,"%d",i);
		}
		
		ad++;
	}
	fclose(pf);
	system("PAUSE");
	return 0;
}

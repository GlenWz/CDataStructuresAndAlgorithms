#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *pf;
	if((pf=fopen("d:\\lianxi\\new.txt","w"))==NULL)
	{
		printf("NO FILE");
		system("PAUSE");
		exit(1);
	}
	fputs("begin:\n",pf);
	for(int i=0;i<50;i++)
	{
		fprintf(pf,"%d\n",(i+=2));
	}
	fputs("end\n",pf);
	fclose(pf);
	system("PAUSE");
	return 0;
}

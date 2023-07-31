#include <stdio.h>
#include <stdlib.h>

int main()
{
	int ch;
	FILE *fp1;
	FILE *fp2;
	if((fp1=fopen("d:\\lianxi\\new.txt","r"))==NULL)
	{
		printf("NO FILE!");
		system("PAUSE");
		exit(1);
	}
	if((fp2=fopen("d:\\lianxi\\old.txt","w"))==NULL)
	{
		printf("NO FILE");
		system("PAUSE");
		exit(1);
	}
	ch=fgetc(fp1);
	while(ch!=EOF)
	{
		fputc(ch,fp2);
		ch=fgetc(fp1);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}

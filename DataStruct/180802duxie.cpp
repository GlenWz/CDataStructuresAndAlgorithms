#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int i;
	char s[80];
	char c;
	FILE *pf1;
	FILE *pf2;
	if((pf1=fopen("d:\\lianxi\\new.txt","r"))==NULL)
	{
		printf("NO FILE");
		system("PAUSE");
		exit(1);
	}
	if((pf1=fopen("d:\\lianxi\\write.txt","w"))==NULL)
	{
		printf("NO FILE");
		system("PAUSE");
		exit(1);
	}
	int ch;
	int a[50]={0,};
	for(int i=0;i<10;i++)
	{
		fscanf(pf1,"%d\n",&ch);
		a[i]=ch;
		fprintf(pf2,"%d\n",a[i]);
	}
	fclose(pf1);
	fclose(pf2);
	system("PAUSE");
	return 0;
}

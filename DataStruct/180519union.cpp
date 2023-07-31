#include<stdio.h>

typedef union
{
	int i;char ch[sizeof(int)];
}Chi;

int main()
{
	Chi chi;
	int i;
	chi.i=1234;
	for(i=0;i<sizeof(int);i++)
	{
		printf("%02hhX",chi.ch[i]);
	}
	printf("\n");
	printf("%d\n",sizeof(int));
}

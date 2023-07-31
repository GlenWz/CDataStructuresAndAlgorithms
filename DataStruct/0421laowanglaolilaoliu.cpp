#include<stdio.h>

int main()
{
	int laoli=178;
	int laowang=175;
	int laoliu=179;
	int *CR,*lyw;
	CR=&laoli;
	lyw=&laoliu;
	printf("crLoverHigh:%d\n",*CR);
	printf("LYWloverHigh:%d\n",*lyw);
	CR=&laowang;
	*lyw=180;
	putchar('\n');
	printf("laoliHigh:%d\n",laoli);
	printf("laowangHigh:%d\n",laowang);
	printf("laoliuHigh:%d\n",laoliu);
	printf("CRlover'sHigh:%d\n",*CR);
	printf("Lywlover'sHigh:%d\n",*lyw);
	return 0;
	
	
}

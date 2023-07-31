#include <stdio.h>

int swap(int *laoli,int *laowang);
int main()
{
	int laoli=5;
	int laowang=80;
	swap(&laoli,&laowang);
	printf("laoli=%d\n",laoli);
	printf("laowang=%d\n",laowang);
	return 0;
}
int swap(int *laoli,int *laowang)
{
	int j=*laoli;
	*laoli=*laowang;
	*laowang=j;
}

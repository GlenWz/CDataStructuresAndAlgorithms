#include <stdio.h>

void yangzi(int *laoliu);
int main()
{
	int laoli=178;
	int laowang=175;
	int laoliu=179;
	yangzi(&laoliu);
	printf("Laoli:%d\n",laoli);
	printf("Laowang:%d\n",laowang);
	printf("laoliu:%d\n",laoliu);
	return 0;
}

void yangzi(int *laoliu)
{
	if(*laoliu<180)
	*laoliu=180;
}

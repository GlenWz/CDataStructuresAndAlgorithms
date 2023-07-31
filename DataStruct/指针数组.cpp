#include <stdio.h>
 
 
int main()
 
{
 
     
	int i;
¡¡ 	char *pch[6] = {"ÃÃ","ÃÃ","Äã","×ø","´¬","Í·"};
    for(i=0;i<6;i++)
	{
        printf("%s, ",pch[i]);¡¡
    }¡¡
     
		printf("\n");¡¡
     
	for(i=5; i>=0; i--)
	{¡¡
        printf("%s\n",pch[i]);¡¡
    }
    return 0;
 
}

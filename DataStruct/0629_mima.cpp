#include <Stdio.h>
#include <Stdlib.h>

int main()
{
	char mima1[]="BCASDBFSSKKJGIJASBBCBBCSDAJLKGKL";
	char mima2[]="BCASDBFSSKKJGIJAS";//16
	int mima2len=sizeof(mima2)/sizeof(mima2[0])-1;
	int mima1len=sizeof(mima1)/sizeof(mima1[0])-1;
	printf("%d \n%d \n",mima1len,mima2len);
	printf("%d",mima1len*mima2len+6+9236875);
	printf("\n");
}

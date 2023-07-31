#include <Stdio.h>

void length(int str[])
{
	int len=sizeof(str)/sizeof(str[0]);
	printf("%d\n",len);
	
}




int main()
{
	int str[]={5,7,8,9,6,3,2,0,1};
	int len =sizeof(str)/sizeof(str[0]);
	printf("woshinidie:%d\n",len);
	length(str);
}

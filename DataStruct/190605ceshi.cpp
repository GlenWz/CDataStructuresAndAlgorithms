#include <Stdio.h>
#include <Stdlib.h>

int shuzu()
{
	return 1;
}
int shuzu1(int s)
{
	return s+888;
}


int main()
{
	char str[]="stedd";
	int len=sizeof(str)/sizeof(str[0]);
	printf("%d",len);
	for(int i=0;i<6;i++)
	{
		printf("%c",str[i]);
	}
	
	shuzu();
	int z=shuzu1(shuzu());
	printf("\n%d",z);
}

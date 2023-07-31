#include <stdio.h>

int main()
{
	int a;
	a=6;
	printf("sizeof(int)=%d\n",sizeof(int));
	printf("sizeof(a)=%d\n",sizeof(a)); //4个字节，一个字节8比特，说明这是一个三十二位的变量 
	return 0;
	
}

#include <stdio.h>
#include <stdlib.h>


int main()
{
	int i=0;
	int *p;
	printf("%d",(130*100)/1024); 
	while(1)
	{
		p=(int *)malloc(100*1024*1024);
		if(p==NULL)
		{
			return 0;
		}
		printf("第%d次，内存分配成功!\n",++i);
	}

 } 

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
		printf("��%d�Σ��ڴ����ɹ�!\n",++i);
	}

 } 

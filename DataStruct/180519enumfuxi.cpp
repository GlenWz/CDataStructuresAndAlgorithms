#include <stdio.h>
enum color{r,g,b
};
int main()
{
	int color=-1;
	char *colorname=NULL;
	printf("please input what's color you like?");
	scanf("%d",&color);
	switch(color)
	{
		case r:
			colorname="red";
			break;
		case g:
			colorname="green";
			break;
		case b:
			colorname="blue";
			break;
		defalut:
			colorname="unknow";
			break;
	}
	printf("you like %s\n",colorname);
	return 0;
	
}

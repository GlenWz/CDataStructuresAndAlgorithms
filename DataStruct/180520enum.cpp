#include <stdio.h>

enum color{r,g,b
};

int main()
{
	int color=1;
	char*colorname=NULL;
	printf("what's color do you like?");
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
		default:
			colorname="unknow";
			break;
	}
	printf("%s\n",colorname);
	return 0;
}

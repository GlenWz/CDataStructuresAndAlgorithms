#include <stdio.h>
enum color{r,g,b
};
int main()
{
	int color=-1;
	char *colorName=NULL;
	printf("ÄãÏ²»¶µÄÑÕÉ«ÊÇ£º\n");
	scanf("%d",&color);
	switch(color)
	{
		case r colorName="RED";break;
		case g colorName="Green";break;
		case b colorName="Blue";break;
		default:
			colorName="unknow";break;
	}
	printf("You like %s\n",colorName);
	return 0;
	
}

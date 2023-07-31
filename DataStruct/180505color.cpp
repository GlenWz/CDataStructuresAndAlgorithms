#include <stdio.h>

enum color{r,g,b
};
int main()
{
	int color=-1;
	char*colorName=NULL;
	printf("ÊäÈëÄãÏ²»¶µÄÑÕÉ«");
	scanf("%d",&color);
	switch(color)
	{
		case r: colorName="Red";break;
		case g: colorName="Green";break;
		case b: colorName="blue";break;
		default:colorName="Unknow";break;
	}
	printf("you like %s\n",colorName);
	return 0;
	
}

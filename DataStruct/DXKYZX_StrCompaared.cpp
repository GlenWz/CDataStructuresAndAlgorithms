#include <stdio.h>
#include <stdlib.h>

int compared(char str[],char t[])
{
	int ret=0,i,j;
	for(i=0,j=0;str[i]!='\0'&&t[i]!='\0';i++)      //这里再题目中要改一下，用strlen，不然遇到'\0' 
	{                                             //
		if(str[i]==t[i])
		{
			ret=0;
		}else if(str[i]>t[i])
		{
			ret=1;
			break;
		}else if(str[i]<t[i])
		{
			ret=-1;
			break;
		}
	}
	if(str[i]=='\0'&&t[i]!='\0')
	{
		ret=-1;
	}
	if(str[i]!='\0'&&t[i]=='\0')
	{
		ret=1;
	}
	return ret;
}




int main()
{
	char str[]="string";
	char t[]="string";
	int ret=compared(str,t);
	printf("%d",ret);
}

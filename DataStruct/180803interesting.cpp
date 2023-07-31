#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	char *ch;
	int length;
}STR;

int strassign(STR& str,char *ch)
{
	if(str.ch)
	{
		free(str.ch);
	}
	int len=0;
	char *c=ch;
	while(*c)
	{
		++len;
		++c;
	}
	if(len==0)
	{
		str.ch=NULL;
		str.length=0;
		return 1;
	}else
	{
		str.ch=(char *)malloc(sizeof(char)*(len+1));
		if(str.ch==NULL)
		{
			return 0;
		}else
		{
			c=ch;
			for(int i=0;i<=len;++i,++c)
			{
				str.ch[i]=*c;
			}
			str.length=len;
			return 1;
		}
	}
}
/*void print(STR str)
{
	for(int i=0;i<str.length;i++)
	{
		printf("%c",str.ch[i]);
	}
}*/

int strlen(STR str)
{
	return str.length;
}


int main()
{
	STR str;
	strassign(str,"interesting");
	int i=strlen(str);
	printf("%d\n",i);
//	print(str);
}

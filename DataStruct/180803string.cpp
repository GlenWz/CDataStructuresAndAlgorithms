#include <Stdio.h>
#include <Stdlib.h>

typedef struct{
	char *ch;
	int length;
}STR;

int strassign(STR str,char *ch)
{
	if(str.ch)
	{
		free(str.ch);
	}
	int len=0;
	char *c=ch;
	while(c)
	{
		++len;
		++c;
	}
	if(len==0)
	{
		str.ch=NULL;
		str.length=0;
		return 0;
	}
	else
	{
		str.ch=(char *)malloc(sizeof(char)*(len+1));
		if(str.ch==NULL)
		{
			return 0;
		}
		else{
			c=ch;
			for(int i=0;i<=len;i++,c++)
			{
				str.ch==c;
				
			}
			str.length=len;
			return 1 ;
		}
	}
}




int main()
{
	STR str;
	strassign(str,"interesting");
	
}

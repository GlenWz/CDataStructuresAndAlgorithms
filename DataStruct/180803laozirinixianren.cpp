#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	char *ch;
	int len;
}STR;
int strassign(STR str,char *ch)
{
	if(str.ch!=NULL)
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
		str.len=0;
		return 1;
	}else
	{
		str.ch=(char *)malloc((len+1)*sizeof(char));
		if(str.ch==NULL)
		{n
			return 0;
		}else
		{
			c=ch;
			for(int i=0;i<len+1;i++,++c)
			{
				str.ch[i]=*c;
				
				
			}
			str.len=len;
			return 1;
		}
	}
}
int main()
{
	STR str;
	strassign(str,"intere sting");
	
}

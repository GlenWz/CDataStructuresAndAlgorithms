#include <Stdio.h>

void swap(char *a,char *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;	
}
void StrMost(char *str,int len)
{
	int strlen=0,tmpl=0;
	char s1,tmps;
	for(int i=0;i<len;i++)
	{
		for(int j=len-1;j>i;j--)
		{
			if(str[j]<str[j-1])
			{
				swap(&str[j],&str[j-1]);
			}	
		}	
	}
	s1=tmps=str[0];
	for(int i=0;i<len;i++)
	{
		if(s1==str[i])
		{
			strlen++;	
		}else
		{
			strlen=1;
			s1=str[i];
			}	
		
		if(strlen>tmpl)
		{
			tmpl=strlen;
			tmps=str[i];
		 } 
	}
	printf("NUM:%d MOST:%c",tmpl,tmps);	
}
int main(){
	char str[]="asdjkldsadkjlkdasa";
	int len=sizeof(str)/sizeof(str[0]);
	StrMost(str,len);
}

#include <Stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct{
	char cc[MAXSIZE];
	int len;	
}string;

string *buildstring()
{
	char c[]="string";
	string *str=(string *)malloc(sizeof(string));
	str->len=0;
	for(int i=0;i<sizeof(c)/sizeof(c[0]);i++)
	{
		str->cc[i]=c[i];
		str->len++;
	}
	return str;
}
string *buildstring1()
{
	char c[]="LAOZISHINIDEI";
	string *s=(string *)malloc(sizeof(string));
	s->len=0;
	for(int i=0;i<sizeof(c)/sizeof(c[0]);i++)
	{
		s->cc[i]=c[i];
		s->len++;
	}
	return s;
}
int insertstring(string *s,string *a,int pos)
{
	if(pos>MAXSIZE||pos<0)
	{
		printf("the position is error!\n");
		return NULL;
	}
	if(s->len+a->len-1<=MAXSIZE)
	{
		for(int i=s->len+a->len-1;i>pos;i--)
		{
			s->cc[i]=s->cc[i-1];
			for(int j=0;j<a->len-1;j++)
			{
				s->cc[j+pos]=a->cc[i];
				s->len++;
			}
		}
	}
}
void print(string *s)
{
	for(int i=0;i<s->len;i++)
	{
		printf("%d",s->cc[i]);
	}
}



int main()
{
	string *s=buildstring();
	string *a=buildstring1();	
	insertstring(s,a,3);
	print(s);	
}

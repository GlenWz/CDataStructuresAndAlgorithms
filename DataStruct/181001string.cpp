#include <Stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct st{
	char CH[MAXSIZE];
	int len;
}string;

string *builds1()
{
	string *s=(string *)malloc(sizeof(string));
	s->len=0;
	char a[]="Str";
	for(int i=0;i<sizeof(a)/sizeof(a[0])-1;i++)
	{
		s->CH[i]=a[i];
		s->len++;
	}
	printf("%d\n",s->len);
	return s;
}
void print(string *s)
{
	for(int i=0;i<s->len;i++)
	{
		printf("%c",s->CH[i]);
	}
}
int insertstring(string *s,string *t,int pos)
{
	if(pos<0||pos>s->len)
	{
		printf("the position is error!\n");
		return NULL;
	}
	if(s->len+t->len-1<MAXSIZE)
	{
		for(int i=s->len+t->len-1;i>=pos+t->len;i--)
		{
			s->CH[i]=s->CH[i-t->len];
		}
		for(int j=0;j<t->len;j++)
			{
				s->CH[pos+j]=t->CH[j];
				
			}
		s->len=s->len+t->len;
	}
}


int main()
{
	string *s=builds1();
	string *t=builds1();
	
	insertstring(s,t,1);
	print(s);
}

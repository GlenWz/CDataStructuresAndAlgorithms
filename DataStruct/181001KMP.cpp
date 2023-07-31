#include <Stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct str{
	char CC[MAXSIZE];
	int len;
}string; 

string * builds()
{
	string *s=(string *)malloc(sizeof(string));
	s->len=0;
	char d[]="string";
	for(int i=0;i<sizeof(d)/sizeof(d[0])-1;i++)
	{
		s->CC[i]=d[i];
		s->len++;
	}
	return s;
}
void print(string *s)
{
	for(int i=0;i<s->len;i++)
	{
		printf("%c",s->CC[i]);
	}
}
string *buildpi()
{
	string *s=(string *)malloc(sizeof(string ));
	char C[]="ing";
	s->len=0;
	for(int i=0;i<sizeof(C)/sizeof(C[0])-1;i++)
	{
		s->CC[i]=C[i];
		s->len++;
	}
	return s;
}
int PIPEI(string *s,string *t)
{
	int si=0,ti=0;
	while(si<=s->len&&ti<=t->len)
	{
		if(s->CC[si]==t->CC[ti])
		{
			++si;
			++ti;
		}else 
		{
			si=si-ti+1;
			ti=0;
		}
	}
	if(ti>t->len)
	{
		return si-ti;
	}else 
	{
		return 0;
	}
}

int main()
{
	string *s=builds();
	string *pipei=buildpi();
	int kmp=PIPEI(s,pipei); //返回的是从S中第几个位置相匹配 
	//print(s);
	printf("%d\n",kmp);
} 

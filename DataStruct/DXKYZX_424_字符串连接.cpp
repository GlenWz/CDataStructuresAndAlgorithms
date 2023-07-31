#include <Stdio.h>
#include <stdlib.h>

typedef struct d{
	char data;
	struct d* next;
}string;

string *builds(char str[],int strlen)
{
	string *head=(string *)malloc(sizeof(string));
	head->data=NULL;
	string *ret=head;
	for(int i=0;i<strlen;i++)
	{
		string *s=(string *)malloc(sizeof(string));
		s->data=str[i];
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}
string *Connect(string *s1,string *s2)
{
	string *ret=s1;
	string *p1,*p2,*h2;
	p2=s2;
	h2=s2->next;
	for(p1=s1->next;p1->next!=NULL;p1=p1->next)
	{
		
	}
	p1->next=h2;
	free(p2);
	return ret;
}
void PrintS(string *s)
{
	string *h;
	for(h=s->next;h;h=h->next)
	{
		printf("%c",h->data);
	}
	printf("\n");
}



int main()
{
	char str[]="string";
	char str1[]="tingstring";
	int strlen=sizeof(str)/sizeof(str[0])-1;
	int str1len=sizeof(str1)/sizeof(str[0])-1;
	string *s1=builds(str,strlen);
	string *s2=builds(str1,str1len);
	PrintS(s1);
	PrintS(s2);
	string *ss12=Connect(s1,s2);
	PrintS(ss12);
}

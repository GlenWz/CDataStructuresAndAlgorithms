#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	char data;
	struct d *next;
}string;

string *buildstring(char str[],int strlen)
{
	string *head=(string *)malloc(sizeof(string));
	string *ret=head;
	head->data=NULL;
	for(int i=0;i<strlen-1;i++)
	{
		string *s=(string *)malloc(sizeof(string));
		s->data=str[i];
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}

int Judge(string *s,int strlen)
{
	int ret=0;
	int i=0,n=-1;
	char comp[strlen/2];
	int str2=strlen/2;
	string *h;
	for(h=s->next;h->next!=NULL;h=h->next,i++)
	{
		if(i<str2)
		{
			++n;
			comp[n]=h->data;
			
			printf("i:%d n:%d  str:%d\n",i,n,str2);

		}else 
		{
			printf("N:%d %d\n",n,i);
			if(comp[n]==h->data)
			{
				ret=1;
				
			}else 
			{
				ret=-1;
				break;
			}
			n--;
		}
	}
	return ret;
}

void PrintS(string *s)
{
	string *h;
	for(h=s->next;h!=NULL;h=h->next)
	{
		printf("%c->",h->data);
	}
	printf("\n");
}


int main()
{
	char str[]="stringgnirts";
	int strlen=sizeof(str)/sizeof(str[0])-1;
	
	string *s=buildstring(str,strlen);
	PrintS(s);
	int num=Judge(s,strlen);
	printf("%d",num);
}











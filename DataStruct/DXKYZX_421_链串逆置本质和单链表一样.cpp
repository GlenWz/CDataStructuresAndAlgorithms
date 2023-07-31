#include <Stdio.h>
#include <Stdlib.h>

typedef struct d{
	char data;
	struct d *next;
}string;

string *builds(char str[],int n)
{
	string *head=(string *)malloc(sizeof(head));
	head->data=NULL;
	string *ret=head;
	for(int i=0;i<n;i++)
	{
		string *s=(string *)malloc(sizeof(string));
		s->next=NULL;
		s->data=str[i];
		head->next=s;
		head=s;
	}
	return ret;
}

string *NIZHI(string *s)
{
	string *ret=s;
	string *p=s;
	string *h=s->next;
	string *q;
	for(;h!=NULL;)
	{
		q=h->next;
		h->next=p;
		p=h;
		h=q;
	}
	ret->next->next=NULL;
	ret->next=p;
	return ret;
}
void PrintS(string *s)
{
	string *h;
	for(h=s->next;s!=NULL;s=s->next)
	{
		printf("%c->",s->data);
	}
	printf("\n");
}

string *DelDS(string *str,int ds)
{
	string *ret=str;
	string *end1=str;
	string *Strdsp,*Strdsh,*Strdsq;
	for(int i=0;end1->next!=NULL;end1=end1->next,i++)
	{
		if(i==ds-1)
		{
			Strdsp=str;
			Strdsh=str->next;
			Strdsq=Strdsh->next;
		}
		if(i>ds-1)
		{
			Strdsp=Strdsh;
			Strdsh=Strdsq;
			Strdsq=Strdsq->next;
		}
	}	
	Strdsp->next=Strdsq;
	free(Strdsh);
	return ret;
}

int Compared(string *s1,string *s2,int strlen,int strlen2)
{
	int ret=0;
	string *h1=s1->next;
	string *h2=s2->next;
	for(;h1!=NULL&&h2!=NULL;h1=h1->next,h2=h2->next)
	{
		if(h1->data>h2->data)
		{
			ret=1;
			break;
		}else if(h1->data<h2->data)
		{
			ret=-1;
			break;
		}else
		{
			ret=0;
		}
	}
	if(h1==NULL&&h2!=NULL)
	{
		ret=-1;
	}
	if(h1!=NULL&&h2==NULL)
	{
		ret=1;
	}
	return ret;
}
string *Insert(string *s2,char instr,int strlen2)
{
	string *ret=s2;
	string *q=s2;
	string *h=s2->next;
	for(;h!=NULL;q=h,h=h->next)
	{
		if(h->data==instr)
		{
			string *s=(string *)malloc(sizeof(string));
			s->data=instr;
			q->next=s;
			s->next=h;
			strlen2++;
			break;
		}
	}
	if(h==NULL)
	{
		string *s=(string *)malloc(sizeof(string));
		s->data=instr;
		q->next=s;
		s->next=NULL;
		strlen2++;
	}
	return ret;
}



int main()
{
	char str[]="stringTTing";
	int	strlen=sizeof(str)/sizeof(str[0])-1;
	string *s=builds(str,strlen);
	PrintS(s);
	string *si=NIZHI(s);
	PrintS(si);
	
	int ds=1;
	string *DS=DelDS(si,ds);     //删除倒数第ds个 ,只允许遍历一遍 
	PrintS(DS);
	char str2[]="stringTTint";
	int strlen2=sizeof(str2)/sizeof(str2[0])-1;
	string *s2=builds(str2,strlen2);
	int comp=Compared(s,s2,strlen,strlen2);
	printf("the compared is %d\n",comp);
	char instr='l';
	string *ins=Insert(s2,instr,strlen2);
	PrintS(ins);
	char instr1='s';
	string *ins1=Insert(ins,instr1,strlen2);
	PrintS(ins1);
	
} 






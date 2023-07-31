#include <stdio.h>
#include <stdlib.h>

typedef struct v{
	int data;
	struct v *next;
}link;

link *buildl(int c)
{
	link *h=(link *)malloc(sizeof(link));
	h->data=NULL;
	link *ret=h;
	for(int i=0;i<10;i++)
	{
		link *s=(link *)malloc(sizeof(link));
		s->data=c*c;
		s->next=NULL;
		h->next=s;
		h=s;
		c++;
	}
	return ret;
}
link *Merge(link *a,link *s)
{
	link *c,*ret;
	c=NULL;
/*	c=(link *)malloc(sizeof(link));
	c->data=NULL;
	c->next=NULL;*/
	link *pa=a,*ps=s;
	a=a->next;
	s=s->next;
	if(a->data<s->data)
		{
			pa->next=a->next;
			a->next=c;
			c=a;
			a=pa->next;
		}else 
		{
			ps->next=s->next;
			s->next=c;
			c=s;
			s=ps->next;
		}
	
	
	for(;a!=NULL&&s!=NULL;)
	{
		if(a->data<s->data)
		{
			pa->next=a->next;
			a->next=c;
			c=a;
			a=pa->next;
		}else 
		{
			ps->next=s->next;
			s->next=c;
			c=s;
			s=ps->next;
		}
	}
	while(s!=NULL)
	{
		ps->next=s->next;
		s->next=c;
		c=s;
		s=ps->next;
	}
	while(a!=NULL)
	{
		pa->next=a->next;
		a->next=c;
		c=a;
		a=ps;
	}
	return c;
}
void Print(link *h)
{
	for(link *s=h->next;s;s=s->next)
	{
		printf("%d->",s->data);
	}
	printf("\n");
}
int main()
{
	link *s=buildl(5);
	Print(s);
	link *a=buildl(2);
	Print(a);
	link *sa=Merge(a,s);
	Print(sa);
	return 0;
}

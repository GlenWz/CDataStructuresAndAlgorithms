#include <Stdio.h>
#include <stdlib.h>



typedef struct link{
	int data;
	struct link *next;
}link;

link *buildlink1()
{
	link *head=(link *)malloc(sizeof(link));
	link *a;
	head->data=NULL;
	a=head;
	for(int i=0;i<5;i++)
	{
		link *s=(link *)malloc(sizeof(link));
		s->data=i*i+5;
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return a;
}
link *buildlink2()
{
	link *head=(link *)malloc(sizeof(link));
	link *b;
	head->data=NULL;
	b=head;
	for(int i=0;i<7;i++)
	{
		link *s=(link *)malloc(sizeof(link));
		s->data=i+9;
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return b;
}

void print(link *h)
{
	link *s;
	for(s=h->next;s!=NULL;s=s->next)
	{
		printf("%d->",s->data);
	}
	printf("\n");
}

link *merge(link *a,link *b)
{
	link *record,*q,*h;
	q=b;
	b=b->next;
	h=a;
	a=a->next;
	record=h;
	free(q);
	while(a!=NULL&&b!=NULL)
	{
		if(a->data>b->data)
		{
			h->next=b;
			b=b->next;
			h=h->next;
		}else 
		{
			h->next=a;
			a=a->next;
			h=h->next;
		}
	}
	h->next=NULL;
	if(a!=NULL)
	{
		h->next=a;
	}
	if(b!=NULL)
	{
		h->next=b;
	}
	return record;
}

int main()
{
	link *a=buildlink1();
	print(a);
	link *b=buildlink2();
	print(b);
	link *s=merge(a,b);
	print(s);
	
}

#include <stdio.h>
#include <stdlib.h>

typedef struct link{
	int data;
	struct link *next;
}link;

link *build1()
{
	link *head=(link *)malloc(sizeof(link));
	head->data=NULL;
	link *h=head;
	for(int i=0;i<5;i++)
	{
		link *s=(link *)malloc(sizeof(link));
		s->next=NULL;
		s->data=i*i+1;
		head->next=s;
		head=s;
	}
	return h;
}
link *build2()
{
	link *head=(link *)malloc(sizeof(link));
	head->data=NULL;
	link *h=head;
	for(int i=0;i<8;i++)
	{
		link *s=(link *)malloc(sizeof(link));
		s->next=NULL;
		s->data=i+5;
		head->next=s;
		head=head->next;
	}
	return h;
}
link *merge(link *a,link *b)
{
	link *q,*record,*h;
	q=b;
	b=b->next;
	h=a;
	record=h;
	a=a->next;
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
void print(link *a)
{
	link *h=a->next;
	for(;h!=NULL;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}

int main()
{
	link *a=build1();
	print(a);
	link *b=build2();
	print(b);
	link *ab=merge(a,b);
	print(ab);
}

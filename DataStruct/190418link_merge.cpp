#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *builda()
{
	int j=2;
	link *head=(link *)malloc(sizeof(link));
	link *h=head;
	head->data=NULL;
	for(int i=0;i<10;i++)
	{
		link *s=(link *)malloc(sizeof(link));
		s->data=j;
		s->next=NULL;
		head->next=s;
		head=s;
		j+=3;
	}
	return h;
}
link *buildb()
{
	int j=1;
	link *head=(link *)malloc(sizeof(link));
	head->data=NULL;
	link *h=head;
	for(int i=0;i<10;i++)
	{
		link *s=(link *)malloc(sizeof(link));
		s->data=j;
		s->next=NULL;
		head->next=s;
		head=s;
		j+=2;
	}
	return h;
}
link *merge(link *a,link *b)
{
	link *h=a;
	link *pa=a;
	a=a->next;
	link *pb=b;
	b=b->next;
	while(a!=NULL&&b!=NULL)
	{
		if(a->data>b->data)
		{
			pa->next=b;
			pb->next=b->next;
			b->next=a;
			pa=b;
			b=pb->next;
		}else if(a->data==b->data) 
		{
			link *f;
			f=b;
			b=b->next;
			pb->next=b;
			free(b);
		}else 
		{
			pa=a;
			a=a->next;
		}
	}
	if(a!=NULL)
	{
		pa->next=a;
	}
	if(b!=NULL)
	{
		pa->next=b;
	}
	return h;
}
void pLINK(link *head)
{
	link *h;
	for(h=head->next;h;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
	
}

int main()
{
	link *a,*b,*me;
	a=builda();
	pLINK(a);
	b=buildb();
	pLINK(b);
	me=merge(a,b);
	pLINK(me);
}

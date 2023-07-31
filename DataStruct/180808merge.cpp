#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *build1()
{
	link *h=(link *)malloc(sizeof(link));
	link *r=(link *)malloc(sizeof(link));
	h->next=r;h->data=NULL;
	r->data=NULL;r->next=h;
	int n=5;
	for(int i=0;i<5;i++)
	{
		link *s=(link *)malloc(sizeof(link));
		if(i!=4)
		{
			s->next=h;
			s->data=i+i;
			r->next=s;
			r=s;
		}else
		{
			s->next=NULL;
			s->data=i*i;
			r->next=s;
			r=s;
		}
	}
	link *p=h;
	h=h->next;
	free(p);
	return h;
}

link *build2()
{
	link *h=(link *)malloc(sizeof(link));
	link *r=(link *)malloc(sizeof(link));
	h->next=r;h->data=NULL;
	r->next=h;r->data=NULL;
	int n=5;
	for(int i=0;i<5;i++)
	{
		link *s=(link *)malloc(sizeof(link));
		if(i!=4)
		{
			s->next=h;
			s->data=i+3;
			r->next=s;
			r=s;
		}else
		{
			s->next=NULL;
			s->data=i+3;
			r->next=s;
			r=s;
		}
	}
	link *p=h;
	h=h->next;
	free(p);
	return h;
}

link *merge(link *h1,link *h2)
{
	link *h=h1;
	link *q,*tou;
	tou=h;
	h1=h1->next;
	q=h2;
	h2=h2->next;
	free(q);
	while(h1!=NULL&&h2!=NULL)
	{
		if(h1->data>h2->data)
		{
			h->next=h2;
			h2=h2->next;
			h=h->next;
		}else 
		{
			h->next=h1;
			h1=h1->next;
			h=h->next;
		}
	}
	h->next=NULL;
	if(h1!=NULL)
	{
		h->next=h1;
	}
	if(h2!=NULL)
	{
		h->next=h2;
	}
	return tou;
	
	
}

void bianli(link *head)
{
	link* h=head->next;
	for(h;h;h=h->next)
	{
		printf("%d\n",h->data);
	}
	printf("-----------------end\n");
}






int main()
{
	link *head1=build1();
	link *head2=build2();
	bianli(head2);
	bianli(head1);
	printf("----------------woshif\n");
	link *tou=merge(head1,head2);
	bianli(tou);
	
	
}

#include <Stdio.h>
#include <Stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}node;

node *build()
{
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
	for(int i=0;i<7;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=i;
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}
node *buildb()
{
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
	for(int i=1;i<7;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=i*2;
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}
node *Conmon(node *a,node *b)
{
	int tmp=1;
	node *ret,*pa,*pb,*ppa;
	ppa=a;
	pa=a->next;
	pb=b->next;
	a=pa->next;
	b=pb->next;
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	ret=head;
	for(;a!=NULL&&b!=NULL;)
	{
		if(pa->data<pb->data&&a->data<pb->data)
		{
			pa=a;
			a=a->next;
		}else if(pb->data<pa->data&&b->data<pa->data)
		{
			pb=b;
			b=b->next;
		}
		if(pb->data<pa->data&&b->data>pa->data)
		{
			node *s=(node *)malloc(sizeof(node));
			s->data=pa->data;
			s->next=NULL;
			head->next=s;
			head=s;
			tmp=0;
		}
		if(pa->data<pb->data&&a->data>pb->data)
		{
			node *s=(node *)malloc(sizeof(node));
			s->data=pb->data;
			s->next=NULL;
			head->next=s;
			head=s;
			tmp=1;
		}
		if(tmp==0)
		{
			pb=b;
			b=b->next;
		}else 
		{
			pa=a;
			a=a->next;
		}
	}
	if(a==NULL)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=pa->data;
		s->next=NULL;
		head->next=s;
		head=s;
	}
	if(b==NULL)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=pb->data;
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}
void Print(node *head)
{
	node *h;
	for(h=head->next;h!=NULL;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}





int main()
{
	node *a=build();
	Print(a);
	node *b=buildb();
	Print(b);
	node *c=Conmon(a,b);
	Print(c);	
}


















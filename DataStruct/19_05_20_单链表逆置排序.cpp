#include <Stdio.h>
#include <Stdlib.h>
#define len 10
typedef struct d{
	int data;
	struct d *next;
}node;

node *builda()
{
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
	for(int i=0;i<len;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=i*i;
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
	for(int i=0;i<len;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=i*i;
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}
node *NIZHI(node *head)
{
	node *h,*p,*q,*ret;
	p=head;
	h=head->next;
	ret=head;
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
node *Merge(node *a,node *b)
{
	node *pa=a;
	a=a->next;
	node *ret=a;
	node *pb=b;
	b=b->next;
	while(a&&b)
	{
		if(a->data<=b->data)
		{
			pa->next=b;
			pb->next=b->next;
			b->next=a;
			b=pb->next;
			pa=pa->next;
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
	return ret;
}
node *SortAB(node *ab)
{
	node *pa,*h,*qa;
	node *ret=ab;
	for(int i=0;i<20;i++)
	{
		for(pa=ab,h=ab->next,qa=h->next;qa!=NULL;)
		{
			if(h->data>qa->data)
			{
				h->next=qa->next;
				qa->next=h;
				pa->next=qa;
				pa=pa->next;
				qa=h->next;
			}else 
			{
				pa=pa->next;
				h=h->next;
				qa=qa->next;
			}
		}
	}
	return ret;
}


void Print(node *head)
{
	node *h=head;
	for(h=h->next;h;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}

int main()
{
	node *a=builda();
	Print(a);
	node *aa=NIZHI(a);
	Print(aa);
	node *b=buildb();
	node *ab=Merge(aa,b);
	Print(ab);
	node *Sab=SortAB(ab);
	Print(Sab);
}

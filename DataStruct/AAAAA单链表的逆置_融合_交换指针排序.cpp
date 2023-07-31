#include <Stdio.h>
#include <stdlib.h>
typedef struct d{
	int data;
	struct d *next;
}node;

node *builda()
{
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
	for(int i=0;i<10;i++)
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
	node *p=head;
	node *h=head->next;
	node *ret=p,*q;
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
node *buildb()
{
	node *head=(node *)malloc(sizeof(node));
	head->data=NULL;
	node *ret=head;
	for(int i=0;i<10;i++)
	{
		node *s=(node *)malloc(sizeof(node));
		s->data=i+i;
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}
node *merge(node *a,node *b)
{
	node *pa,*pb,*qa,*qb;
	pa=a;
	node *ret=a;
	qa=a->next;
	pb=b;
	qb=b->next;
	while(qa&&qb)
	{
		if(qa->data>=qb->data)
		{
			pa->next=qb;
			pb->next=qb->next;
			qb->next=qa;
			pa=pa->next;
			qb=pb->next;
		}else 
		{
			pa=pa->next;
			qa=qa->next;
		}
	}
	if(qa!=NULL)
	{
		pa->next=qa;
	}
	if(qb!=NULL)
	{
		pa->next=qb;
	}
	return ret;
}
node *SortAB(node *head)
{
	node *p,*q,*h;
	node *ret=head;
	for(int i=0;i<20;i++)
	{
		for(p=head,h=head->next,q=h->next;q!=NULL;)
		{
			if(h->data>q->data)
			{
				h->next=q->next;
				q->next=h;
				p->next=q;
				p=p->next;
				q=h->next;
			}else 
			{
				p=h;
				h=q;
				q=q->next;
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
	Print(b);
	node *ab=merge(aa,b);
	Print(ab);
	node *Sab=SortAB(ab);
	Print(Sab);
}

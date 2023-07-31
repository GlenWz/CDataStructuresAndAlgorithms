#include <Stdio.h>
#include <Stdlib.h>
typedef struct d{
	int data;
	struct d *next;
}node;

node *builda()
{
	node *head=(node *)malloc(sizeof(node));
	node *ret=head;
	head->data=NULL;
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
node *NIZHI(node *head)
{
	node *p,*ret,*h,*q;
	p=ret=head;
	h=head->next;
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
node *merge(node *a,node *b)
{
	node *qa,*qb,*pa,*pb,*ret;
	ret=a;
	pa=a;
	qa=a->next;
	pb=b;
	qb=b->next;
	while(qa!=NULL&&qb!=NULL)
	{
		if(qa->data>qb->data)
		{
			pb->next=qb->next;
			qb->next=qa;
			pa->next=qb;
			pa=pa->next;
			qb=pb->next;
		}else 
		{
			pa=qa;
			qa=qa->next;
		}
	}
	if(qa!=NULL)
	{
		pa->next=qa;
	}
	if(qb!=NULL)
	{
		pb->next=qa;
	}
	return ret;
}
node *SortAB(node *head)
{
	node *h,*p,*q,*ret;
	ret=head;
	for(int i=0;i<20;i++)
	{
		for(p=head,h=p->next,q=h->next;q!=NULL;)
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
				p=p->next;
				h=h->next;
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
	node *aa=NIZHI(a);
	Print(aa);
	node *b=buildb();
	node *ab=merge(aa,b);
	Print(ab);
	node *sab=SortAB(ab);
	Print(sab);
}

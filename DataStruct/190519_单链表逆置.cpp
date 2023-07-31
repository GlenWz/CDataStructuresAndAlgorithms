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
node *Nizhi(node *head)
{
	node *ret,*q,*p,*h;
	ret=p=head;
	h=p->next;
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
	node *pa,*pb,*qa,*qb,*ret;
	ret=a;
	pa=a;
	qa=a->next;
	pb=b;
	qb=b->next;
	while(qb!=NULL&&qa!=NULL)
	{
		if(qa->data>qb->data)
		{
			pb->next=qb->next;
			qb->next=qa;
			pa->next=qb;
			qb=pb->next;
			pa=pa->next;
		}else 
		{
			pa=qa;
			qa=qa->next;
		}
	}
	if(qa!=NULL)
	{
		pa->next=qa->next;
	}
	if(qb!=NULL)
	{
		qa->next=qb->next;
	}
	return ret;
}

node *SortAB(node *ab)
{
	node *h,*j,*p,*q,*ret;
	ret=ab;
	//for(j=ab;j!=NULL;j=j->next)
	for(int i=0;i<20;i++)
	{
		for(p=ab,h=ab->next,q=h->next;q!=NULL;)
		{
			if(h->data>=q->data)
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
	node *h;
	for(h=head->next;h!=NULL;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
	
}
int main()
{
	node *a=builda();
	Print(a);	
	node *aa=Nizhi(a);
	Print(aa);
	node *b=buildb();
	node *ab=Merge(aa,b); 
	Print(ab);
	node *sab=SortAB(ab);
	Print(sab);
}

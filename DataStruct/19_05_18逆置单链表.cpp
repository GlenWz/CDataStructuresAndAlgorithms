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
	node *h=head;
	for(int i=0;i<10;i++)
	{
		if(i==9)
		{
			node *n=(node *)malloc(sizeof(node));
			n->data=-1;
			n->next=NULL;
			head->next=n;
			head=n;
		}else 
		{
			node *s=(node *)malloc(sizeof(node));
			s->data=i*i;
			s->next=NULL;
			head->next=s;
			head=s;
		}
	}
	return h;
}
node *buildb()
{
	node *head=(node *)malloc(sizeof(node ));
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
	node *q,*p,*h,*ret;
	ret=p=head;
	h=head->next;
	for(;h->data!=-1;)
	{
		q=h->next;
		h->next=p;
		p=h;
		h=q;
	}
	ret->next->next=NULL;
	ret->next=p;
}
void Print(node *head)
{
	node *h;
	for(h=head->next;h;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}
node *Merge(node *a,node *b)
{
	node *ret=a;
	node *pa,*pb,*qa,*qb;
	pa=a;
	qa=a->next;
	pb=b;
	qb=b->next;
	while(qa!=NULL&&qb!=NULL)
	{
		if(qb->data<=qa->data)
		{
			pa->next=qb;
			pb->next=qb->next;
			qb->next=qa;
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
		pa->next=qa;
	}
	if(qb!=NULL)
	{
		pa->next=qb;
	}
	return ret;	
}
int main()
{
	node *a=builda();
	Print(a);
	node *aa=NIZHI(a);
	Print(aa);
	node *b=buildb();
	node *c=Merge(aa,b);
	Print(c);
	
}





